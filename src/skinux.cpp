#include "skinux.h"
#include <imgui/imgui_impl_sdl_gl3.cpp>

SDL_Window* window;
SDL_GLContext context;
size_t screenWidth = 1280;
size_t screenHeight = 720;

bool update()
{
    bool rtn = true;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: {
                rtn = false;
            }
        }
        ImGui_ImplSdlGL3_ProcessEvent(&event);
    }
    ImGui::NewFrame();
    return rtn;
}

void draw()
{
    glViewport(0, 0, screenWidth, screenHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (ImDrawData *drawData = ImGui::GetDrawData())
        ImGui_ImplSdlGL3_RenderDrawData(drawData);
    ImGui_ImplSdlGL3_NewFrame(window);
}

atomic_bool running(false);
lak::queue_t windowLock;
lak::queue_t drawLock;

void drawLoop()
{
    while(running)
    {
        lak::ticket_t windowt = windowLock.lock();
        SDL_GL_MakeCurrent(window, context);

        lak::ticket_t drawt = drawLock.lock();
        draw();
        drawt = nullptr;

        SDL_GL_SwapWindow(window);
        SDL_GL_MakeCurrent(window, 0);
        windowt = nullptr;
    }
}

thread drawThread;

void init()
{
    assert(!running);
    assert(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) == 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    window = SDL_CreateWindow("SKINUX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    if (SDL_GL_SetSwapInterval(-1) == -1) // adaptive vsync
    {
        SDL_GL_SetSwapInterval(1); // standard vsync
    }

    gl3wInit();

    #ifndef NDEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback((GLDEBUGPROC)[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
    {
        if (type == GL_DEBUG_TYPE_ERROR)
            cout << std::ios::hex << "** GL ERROR ** severity = 0x" << severity
            << ", message = " << endl << message << endl << endl;
    }, 0);
    #else
    glDisable(GL_DEBUG_OUTPUT);
    #endif

    ImGui::CreateContext();
    ImGui_ImplSdlGL3_Init(window);
    ImGui::StyleColorsDark();
    ImGui::GetStyle().WindowRounding = 0;
    ImGui_ImplSdlGL3_NewFrame(window);

    glClearColor(0.0f, 0.3125f, 0.3125f, 1.0f);

    draw();
    SDL_GL_SwapWindow(window);
    SDL_GL_MakeCurrent(window, 0); // make sure to release the window from this thread
    update();
    ImGui::Render();

    running = true;
    drawThread = thread(drawLoop);
}

void stop()
{
    assert(running);
    running = false;
    if (drawThread.joinable())
        drawThread.join();

    ImGui_ImplSdlGL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

lak::ticket_t openglAccess;

void beginOpenGLAccess()
{
    openglAccess = windowLock.lock();
    SDL_GL_MakeCurrent(window, context);
}

void endOpenGLAccess()
{
    SDL_GL_MakeCurrent(window, 0);
    openglAccess.reset();
}

lak::ticket_t updateRunning;

bool beginUpdate()
{
    updateRunning = drawLock.lock();
    return update();
}

void endUpdate()
{
    ImGui::Render();
    updateRunning.reset();
}

int main()
{
    init();
    bool run = true;
    while (run)
    {
        run = beginUpdate();
        if (ImGui_Begin("SKINUX TEST", NULL, 0))
        {
            if (ImGui_Button("Exit", {0, 0}))
                run = false;
            ImGui_End();
        }
        endUpdate();
    }
    stop();
    return 0;
}

#include <imgui/imgui.cpp>
#include <imgui/imgui_draw.cpp>
#include <imgui/imgui_demo.cpp>
extern "C" {
#include <GL/gl3w.c>
}
#include "pygui.cpp"
#include "lak/queue.cpp"