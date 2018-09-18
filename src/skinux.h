#include <iostream>
using std::cout;
using std::endl;
#include <cassert>
#include <thread>
using std::thread;
#include <atomic>
using std::atomic_bool;

#include "lak/pyexport.h"
#include "lak/queue.h"

#ifndef SKINUX_H
#define SKINUX_H

//
// draw thread control
//

extern thread drawThread;

// start the draw thread
PY_EXPORT void startDrawThread();

// stop the draw thread
PY_EXPORT void stopDrawThread();

//
// update control
//

// block until the update thread is active
PY_EXPORT void beginUpdate();

// yield the update thread
PY_EXPORT void endUpdate();

#endif // SKINUX_H