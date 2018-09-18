from CLib import CLib
from sys import platform
from ctypes import sizeof, c_void_p, c_char_p
import os

os.chdir("out/debug")
if platform=="win32":
    os.chdir("x86")

clibdir = "libSkinux.{}".format("dll" if platform=="win32" else "so")

clib = CLib(clibdir, dict(
    init=[None, []],
    shutdown=[None, []],
    beginOpenGLAccess=[None, []],
    endOpenGLAccess=[None, []],
    beginUpdate=[None, []],
    endUpdate=[None, []]
))

clib.init()

clib.beginUpdate()

clib.endUpdate()

clib.shutdown()