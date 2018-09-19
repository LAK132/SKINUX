from CLib import *
from PyGui import *
from contextlib import contextmanager
from sys import platform
from ctypes import *
import os
import platform
from contextlib import contextmanager
from ctypes import POINTER, c_int, c_char_p, c_float, c_bool
from pathlib import Path
from CLib import CLib
from PyGui import PyGui, ImGuiDir

bitness, os_type = platform.architecture()
windows = os_type == "WindowsPE"
lib_bitness = 'x86' if bitness == '32bit' else 'x64'
debug = True
c_bool_p = POINTER(c_bool)
c_float_p = POINTER(c_float)
lib = Path('./out')
if debug:
    lib /='debug'

if windows:
    lib/=lib_bitness
clibdir = (lib/"libSkinux").with_suffix(".dll" if windows else ".so").absolute()
print('Loading {}'.format(clibdir))
clib = CLib(clibdir, dict(
    init=[None, []],
    stop=[None, []],
    beginOpenGLAccess=[None, []],
    endOpenGLAccess=[None, []],
    beginUpdate=[c_bool, []],
    endUpdate=[None, []],

    ImGui_Begin=[c_bool, [c_char_p, c_bool_p, c_int]],
    ImGui_End=[None, []],
    ImGui_BeginChild=[c_bool, [c_char_p, ImVec2, c_bool, c_int]],
    ImGui_EndChild=[None, []],
    ImGui_Separator=[None, []],
    ImGui_SameLine=[None, [c_float, c_float]],
    ImGui_NewLine=[None, []],
    ImGui_Spacing=[None, []],
    ImGui_Dummy=[None, [ImVec2]],
    ImGui_Indent=[None, [c_float]],
    ImGui_Unindent=[None, [c_float]],
    ImGui_BeginGroup=[None, []],
    ImGui_EndGroup=[None, []],
    ImGui_TextUnformatted=[None, [c_char_p, c_char_p]],
    ImGui_Button=[c_bool, [c_char_p, ImVec2]],
    ImGui_SmallButton=[c_bool, [c_char_p]],
    ImGui_InvisibleButton=[c_bool, [c_char_p, ImVec2]],
    ImGui_ArrowButton=[c_bool, [c_char_p, c_int]]
))

pygui = PyGui(clib)


@contextmanager
def graphicsThread():
    try:
        clib.init()
        yield True
    finally:
        clib.stop()


@contextmanager
def graphicsUpdate():
    try:
        yield clib.beginUpdate()
    finally:
        clib.endUpdate()


with graphicsThread() as running:
    while running:
        with graphicsUpdate() as cont:
            running = cont
            if pygui.begin("SKINUX"):
                if pygui.button("Exit", ImVec2(100, 100)):
                    running = False
                if pygui.arrow_button('Test', ImGuiDir.Right):
                    print('test')
                    pass
                pygui.end()
