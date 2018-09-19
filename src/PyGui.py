from ctypes import byref, POINTER, sizeof, c_int, c_void_p, c_char_p, c_float, c_bool

c_bool_p = POINTER(c_bool)
c_float_p = POINTER(c_float)

class PyGui(object):
    _lib = None
    def __init__(self, clib):
        self._lib = clib
    
    def begin(self, name, open=True, flags=c_int(0)):
        p_open = c_bool(open)
        rtn = self._lib.ImGui_Begin(name, byref(p_open), flags)
        return rtn, p_open.value

    def end(self):
        self._lib.ImGui_End()

    def begin_child(self, str_id, width=c_float(0), height=c_float(0), border=c_bool(False), flags=c_int(0)):
        return self._lib.ImGui_BeginChild(str_id, width, height, border, flags)

    def end_child(self):
        self._lib.ImGui_EndChild()

    def button(self, label, width=c_float(0), height=c_float(0)):
        return self._lib.ImGui_Button(label, width, height)

    def small_button(self, label):
        return self._lib.ImGui_SmallButton(label)

    def invisible_button(self, label, width, height):
        return self._lib.ImGui_InvisibleButton(label, width, height)

    def arrow_button(self, label, direction):
        return self._lib.ImGui_ArrowButton(label, direction)

    # def image_button(self, texture_id, width, height, u0=c_float(0), v0=c_float(0), u1=c_float(1), v1=c_float(1), padding=c_int(-1)):
    #     pass
    
    # def checkbox(self, label, value):
    #     val = c_bool(value)
    #     rtn = self._lib.ImGui_Checkbox(label, byref(val))
    #     value = val
    #     return rtn
