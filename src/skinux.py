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

pygui = PyGui(clib_dir)

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
