#include "skinux.h"

#include "lak/queue.cpp"

void draw()
{
    cout << "draw" << endl;
}

atomic_bool running(false);
lak::queue_t queue;

void drawLoop()
{
    while(running)
    {
        lak::ticket_t ticket = queue.lock();
        draw();
    }
}

thread drawThread;

void startDrawThread()
{
    if (running) stopDrawThread();
    running = true;
    drawThread = thread(drawLoop);
}

void stopDrawThread()
{
    if (!running) return;
    running = false;
    if (drawThread.joinable())
        drawThread.join();
}

lak::ticket_t updateRunning;

void beginUpdate()
{
    updateRunning = queue.lock();
}

void endUpdate()
{
    updateRunning.reset();
}