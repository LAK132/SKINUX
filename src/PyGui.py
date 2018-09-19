from contextlib import contextmanager
from ctypes import byref, CFUNCTYPE, POINTER, c_int, c_void_p, c_char_p, c_float, c_double, c_bool, c_ushort, Structure

c_bool_p = POINTER(c_bool)
c_float_p = POINTER(c_float)


class enum(object):
    """A C enum like objec"""

    def __init__(self, names):
        if isinstance(names, list):
            self._dict = dict({v: c_int(i) for i, v in enumerate(names)})
        else:
            self._dict = dict({k: c_int(names[k]) for k in names})

    def __getattr__(self, name):
        if self._dict == None:
            return None
        return self._dict[name]

    def __getitem__(self, item):
        if item in self.__dict__:
            return self.__dict__[item]
        elif item in self._dict:
            return self._dict[item]


ImGuiKey = enum([
    'Tab',
    'LeftArrow',
    'RightArrow',
    'UpArrow',
    'DownArrow',
    'PageUp',
    'PageDown',
    'Home',
    'End',
    'Insert',
    'Delete',
    'Backspace',
    'Space',
    'Enter',
    'Escape',
    'A',
    'C',
    'V',
    'X',
    'Y',
    'Z',
    'COUNT'
])

ImGuiNavInput = enum([
    'Activate',
    'Cancel',
    'Input',
    'Menu',
    'DpadLeft',
    'DpadRight',
    'DpadUp',
    'DpadDown',
    'LStickLeft',
    'LStickRight',
    'LStickUp',
    'LStickDown',
    'FocusPrev',
    'FocusNext',
    'TweakSlow',
    'TweakFast',
    # Internal
    'KeyMenu_',
    'KeyLeft_',
    'KeyRight_',
    'KeyDown_',
    'COUNT',
    # 'InternalStart_' = ImGuiNavInput.KeyMenu_
])

ImGuiDir = enum({
    'None': -1,
    'Left': 0,
    'Right': 1,
    'Up': 2,
    'Down': 3,
    'COUNT': 4
})

ImGuiWindowFlags = enum([
    'None'
])


# ImGuiFocusedFlags
# ImGuiHoveredFlags
# ImGuiCond
# ImGuiSizeCallback
# ImGuiStyleVar

class ImTextureID(c_void_p):
    pass


class ImFontAtlas(Structure):
    pass


class ImFont(Structure):
    pass


class ImDrawData(Structure):
    pass


class ImWchar(c_ushort):
    pass


class ImVec2(Structure):
    _fields_ = [
        ("x", c_float),
        ("y", c_float)
    ]


class ImVec4(Structure):
    _fields_ = [
        ("x", c_float),
        ("y", c_float),
        ("z", c_float),
        ("w", c_float)
    ]


class ImColor(Structure):
    _fields_ = [("Value", ImVec4)]


class ImGuiIO(Structure):
    _fields_ = [
        ("ConfigFlags", c_int),
        ("BackendFlags", c_int),
        ("DisplaySize", ImVec2),
        ("DeltaTime", c_float),
        ("IniSavingRate", c_float),
        ("IniFileName", c_char_p),
        ("LogFileName", c_char_p),
        ("MouseDoubleClickTime", c_float),
        ("MouseDoubleThreshold", c_float),
        ("KeyMap", c_int * ImGuiKey.COUNT.value),
        ("KeyRepeatDelay", c_float),
        ("KeyRepeatRate", c_float),
        ("UserData", c_void_p),
        ("Fonts", POINTER(ImFontAtlas)),
        ("FontGlobalScale", c_float),
        ("FontAllowUserScaling", c_bool),
        ("FontDefault", POINTER(ImFont)),
        ("DisplayFrameBufferScale", ImVec2),
        ("DisplayVisibleMin", ImVec2),
        ("DisplayVisibleMax", ImVec2),
        ("ConfigMacOSXBehaviors", c_bool),
        ("ConfigCursorBlink", c_bool),
        ("ConfigResizeWindowsFromEdges", c_bool),
        ("GetClipboardTextFn", CFUNCTYPE(c_char_p, c_void_p)),
        ("SetClipboardTestFn", CFUNCTYPE(None, c_void_p, c_char_p)),
        ("ClipboardUserData", c_void_p),
        ("ImeSetInputScreenPosFn", CFUNCTYPE(None, c_int, c_int)),
        ("ImeWindowHandle", c_void_p),
        ("RenderDrawListFn", CFUNCTYPE(None, POINTER(ImDrawData))),
        ("MousePos", ImVec2),
        ("MouseDown", c_bool * 5),
        ("MouseWheel", c_float),
        ("MouseWheelH", c_float),
        ("MouseDrawCursor", c_bool),
        ("KeyCtrl", c_bool),
        ("KeyShift", c_bool),
        ("KeyAlt", c_bool),
        ("KeySuper", c_bool),
        ("KeyDown", c_bool * 512),
        ("InputCharacters", ImWchar * 17),
        ("NavInputs", c_float * ImGuiNavInput.COUNT.value),
        ("WantCaptureMouse", c_bool),
        ("WantCaptureKeyboard", c_bool),
        ("WantTextInput", c_bool),
        ("WantSetMousePos", c_bool),
        ("WantSaveIniSettings", c_bool),
        ("NavActive", c_bool),
        ("NavVisible", c_bool),
        ("Framerate", c_float),
        ("MetricsRenderVertices", c_int),
        ("MetricsRenderIndices", c_int),
        ("MetricsRenderWindows", c_int),
        ("MetricsActiveWindows", c_int),
        ("MetricsActiveAllocations", c_int),
        ("MouseDelta", ImVec2),
        ("MousePosPrev", ImVec2),
        ("MouseClickedPos", ImVec2 * 5),
        ("MouseClickedTime", c_double * 5),
        ("MouseClicked", c_bool * 5),
        ("MouseDoubleClicked", c_bool * 5),
        ("MouseReleased", c_bool * 5),
        ("MouseDownOwned", c_bool * 5),
        ("MouseDownDuration", c_float * 5),
        ("MouseDownDurationPrev", c_float * 5),
        ("MouseDragMaxDistanceAbs", ImVec2 * 5),
        ("MouseDragMaxDistanceSqr", c_float * 5),
        ("KeyDownDuration", c_float * 512),
        ("KeyDownDurationPrev", c_float * 512),
        ("NavInputsDownDuration", c_float * ImGuiNavInput.COUNT.value),
        ("NavInputsDownDurationPrev", c_float * ImGuiNavInput.COUNT.value)
    ]


class PyGui(object):
    _lib = None

    def __init__(self, clib):
        self._lib = clib
        self.running = False

    def __enter__(self):
        self._lib.init()
        self.running = True
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self._lib.stop()
        del self._lib
        print('Cleaned temp lib')

    @contextmanager
    def update_app(self):
        try:
            yield self._lib.beginUpdate()
        finally:
            self._lib.endUpdate()

    @contextmanager
    def new_child(self, name, size=ImVec2(0, 0), border=c_bool(False), flags=c_int(0)):
        try:
            yield self.begin_child(name, size, border, flags)
        finally:
            self.end_child()

    def begin(self, name, open=True, flags=c_int(0)):
        p_open = c_bool(open)
        rtn = self._lib.ImGui_Begin(name.encode('utf-8'), byref(p_open), flags)
        return rtn, p_open.value

    def end(self):
        self._lib.ImGui_End()

    def begin_child(self, str_id, size=ImVec2(0, 0), border=c_bool(False), flags=c_int(0)):
        return self._lib.ImGui_BeginChild(str_id.encode('utf-8'), size, border, flags)

    def end_child(self):
        self._lib.ImGui_EndChild()

    def button(self, label, size=ImVec2(0, 0)):
        return self._lib.ImGui_Button(label.encode('utf-8'), size)

    def new_line(self):
        return self._lib.ImGui_NewLine()

    def spacing(self):
        return self._lib.ImGui_Spacing()

    def separator(self):
        return self._lib.ImGui_Separator()

    def small_button(self, label):
        return self._lib.ImGui_SmallButton(label.encode('utf-8'))

    def invisible_button(self, label, size):
        return self._lib.ImGui_InvisibleButton(label.encode('utf-8'), size)

    def arrow_button(self, label, direction):
        return self._lib.ImGui_ArrowButton(label.encode('utf-8'), direction)

    def text(self, text):
        return self._lib.ImGui_Text(text.encode('utf-8'))

    # def image_button(self, texture_id, size, u0=c_float(0), v0=c_float(0), u1=c_float(1), v1=c_float(1), padding=c_int(-1)):
    #     pass

    # def checkbox(self, label, value):
    #     val = c_bool(value)
    #     rtn = self._lib.ImGui_Checkbox(label, byref(val))
    #     value = val
    #     return rtn
