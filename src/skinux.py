from CLib import CLib
from PyGui import PyGui
from sys import platform
from ctypes import POINTER, sizeof, c_int, c_void_p, c_char_p, c_float, c_bool
import os

c_bool_p = POINTER(c_bool)
c_float_p = POINTER(c_float)

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
    endUpdate=[None, []],

    ImGui_Begin=[c_bool, [c_char_p, c_bool_p, c_int]],
    ImGui_End=[None, []],
    ImGui_BeginChild=[c_bool, [c_char_p, c_float, c_float, c_bool, c_int]],
    ImGui_EndChild=[None, []],
    ImGui_Separator=[None, []],
    ImGui_SameLine=[None, [c_float, c_float]],
    ImGui_NewLine=[None, []],
    ImGui_Spacing=[None, []],
    ImGui_Dummy=[None, [c_float, c_float]],
    ImGui_Indent=[None, [c_float]],
    ImGui_Unindent=[None, [c_float]],
    ImGui_BeginGroup=[None, []],
    ImGui_EndGroup=[None, []],
    ImGui_TextUnformatted=[None, [c_char_p, c_char_p]],
    ImGui_Button=[c_bool, [c_char_p, c_float, c_float]],
    ImGui_SmallButton=[c_bool, [c_char_p]],
    ImGui_InvisibleButton=[c_bool, [c_char_p, c_float, c_float]],
    ImGui_ArrowButton=[c_bool, [c_char_p, c_int]]
))

pygui = PyGui(clib)

running = True

clib.init()

while running:
    clib.beginUpdate()
    if pygui.begin("SKINUX"):
        if pygui.button("Exit"):
            running = False
        pygui.end()
    clib.endUpdate()

clib.shutdown()