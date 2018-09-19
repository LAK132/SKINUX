#include <iostream>
using std::cout;
using std::endl;
#include <cassert>
#include <thread>
using std::thread;
#include <atomic>
using std::atomic;
using std::atomic_bool;

#include <imgui/imgui.h>
// #include <imgui/imgui_impl_sdl_gl3.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <GL/gl3w.h>

#include "lak/pyexport.h"
#include "lak/queue.h"
#include "lak/ldebug.h"
#include "pygui.h"

#ifndef SKINUX_H
#define SKINUX_H

PY_EXPORT void init();

PY_EXPORT void stop();

//
// opengl access control
//

PY_EXPORT void beginOpenGLAccess();

PY_EXPORT void endOpenGLAccess();

//
// update control
//

// block until the update thread is active
PY_EXPORT bool beginUpdate();

// yield the update thread
PY_EXPORT void endUpdate();

#endif // SKINUX_H