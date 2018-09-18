from CLib import CLib
from sys import platform
from ctypes import sizeof, c_void_p, c_char_p
import os

clibdir = "./out/debug/x86/skinux{}".format(".dll" if platform=="win32" else ".so")
clib = CLib(clibdir, dict(
    startDrawThread=[None, []],
    stopDrawThread=[None, []],
    beginUpdate=[None, []],
    endUpdate=[None, []]
))

clib.startDrawThread()

clib.beginUpdate()

clib.endUpdate()

clib.stopDrawThread()