import os
import platform
from pathlib import Path

from PyGui import *
from PyGui import PyGui, ImGuiDir

c_bool_p = POINTER(c_bool)
c_float_p = POINTER(c_float)

bitness, os_type = platform.architecture()
windows = os_type == "WindowsPE"
lib_bitness = 'x86' if bitness == '32bit' else 'x64'
debug = True

clib_dir = Path('./out').absolute()
if debug:
    clib_dir /= 'debug'
else:
    clib_dir /= 'release'
if windows:
    clib_dir /= lib_bitness
os.chdir(clib_dir.as_posix())
clib_dir = (clib_dir / "libSkinux").with_suffix(".dll" if windows else ".so")
print('Loading {}'.format(clib_dir))

clib = CLib(str(clib_dir), dict(
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
    ImGui_ArrowButton=[c_bool, [c_char_p, c_int]]))
pygui = PyGui(clib)

with pygui as gui:
    while gui.running:
        with gui.update_app():
            if pygui.begin("SKINUX"):
                if pygui.button("Exit", ImVec2(100, 100)):
                    gui.running = False
                if pygui.arrow_button('Test', ImGuiDir.Right):
                    print('test')
                    pass
                pygui.end()
