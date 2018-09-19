#include "pygui.h"

vec2 toCVec2(const ImVec2 &vec)
{
    return {vec.x, vec.y};
}

vec2 toCVec2(ImVec2 &&vec)
{
    return {vec.x, vec.y};
}

vec4 toCVec4(const ImVec4 &vec)
{
    return {vec.x, vec.y, vec.z, vec.w};
}

vec4 toCVec4(ImVec4 &&vec)
{
    return {vec.x, vec.y, vec.z, vec.w};
}

bool ImGui_Begin(const char* name, bool* p_open, ImGuiWindowFlags flags)
{
    return Begin(name, p_open, flags);
}

void ImGui_End()
{
    End();
}

bool ImGui_BeginChild(const char* str_id, vec2 size, bool border, ImGuiWindowFlags flags)
{
//BeginChild(const char* str_id, const ImVec2& size = ImVec2(0,0), bool border = false, ImGuiWindowFlags flags = 0);
    return BeginChild(str_id, ImVec2(size.x, size.y), border, flags);
}

void ImGui_EndChild()
{
    EndChild();
}

bool ImGui_IswindowAppearing()
{
    return IsWindowAppearing();
}

bool ImGui_IsWindowCollapsed()
{
    return IsWindowCollapsed();
}

bool ImGui_IsWindowFocused(ImGuiFocusedFlags flags)
{
    return IsWindowFocused(flags);
}

bool ImGui_IsWindowHovered(ImGuiHoveredFlags flags)
{
    return IsWindowHovered(flags);
}

ImDrawList* ImGui_GetWindowDrawList()
{
    return GetWindowDrawList();
}

vec2 ImGui_GetWindowPos()
{
    return toCVec2(GetWindowPos());
}

vec2 ImGui_GetWindowSize()
{
    return toCVec2(GetWindowSize());
}

float ImGui_GetWindowWidth()
{
    return GetWindowWidth();
}

float ImGui_GetWindowHeight()
{
    return GetWindowHeight();
}

vec2 ImGui_GetContentRegionMax()
{
    return toCVec2(GetContentRegionMax());
}

vec2 ImGui_GetContentRegionAvail()
{
    return toCVec2(GetContentRegionAvail());
}

float ImGui_GetContentRegionAvailWidth()
{
    return GetContentRegionAvailWidth();
}

vec2 ImGui_GetWindowContentRegionMin()
{
    return toCVec2(GetWindowContentRegionMin());
}

vec2 ImGui_GetWindowContentRegionMax()
{
    return toCVec2(GetWindowContentRegionMax());
}

float ImGui_GetWindowContentRegionWidth()
{
    return GetWindowContentRegionWidth();
}

void ImGui_SetNextWindowPos(vec2 pos, ImGuiCond cond, vec2 pivot)
{
    SetNextWindowPos(ImVec2(pos.x, pos.y), cond, ImVec2(pivot.x, pivot.y));
}

void ImGui_SetNextWindowSize(vec2 size, ImGuiCond cond)
{
    SetNextWindowSize(ImVec2(size.x, size.y), cond);
}

void ImGui_SetNextWindowSizeConstraints(vec2 size_min, vec2 size_max, ImGuiSizeCallback custom_callback, void* custom_callback_data)
{
    SetNextWindowSizeConstraints(ImVec2(size_min.x, size_min.y), ImVec2(size_max.x, size_max.y), custom_callback, custom_callback_data);
}

void ImGui_SetNextWindowContentSize(vec2 size)
{
    SetNextWindowContentSize(ImVec2(size.x, size.y));
}

void ImGui_SetNextWindowCollapsed(bool collapsed, ImGuiCond cond)
{
    SetNextWindowCollapsed(collapsed, cond);
}

void ImGui_SetNextWindowFocus()
{
    SetNextWindowFocus();
}

void ImGui_SetNextWindowBgAlpha(float alpha)
{
    SetNextWindowBgAlpha(alpha);
}

void ImGui_SetWindowPos(vec2 pos, ImGuiCond cond)
{
    SetWindowPos(ImVec2(pos.x, pos.y), cond);
}

void ImGui_SetWindowSize(vec2 size, ImGuiCond cond)
{
    SetWindowSize(ImVec2(size.x, size.y), cond);
}

void ImGui_SetWindowCollapsed(bool collapsed, ImGuiCond cond)
{
    SetWindowCollapsed(collapsed, cond);
}

void ImGui_SetWindowFocus()
{
    SetWindowFocus();
}

void ImGui_SetWindowFontScale(float scale)
{
    SetWindowFontScale(scale);
}

void ImGui_SetNamedWindowPos(const char* name, vec2 pos, ImGuiCond cond)
{
    SetWindowPos(name, ImVec2(pos.x, pos.y), cond);
}

void ImGui_SetNamedWindowSize(const char* name, vec2 size, ImGuiCond cond)
{
    SetWindowSize(name, ImVec2(size.x, size.y), cond);
}

void ImGui_SetNamedWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond)
{
    SetWindowCollapsed(name, collapsed, cond);
}

void ImGui_SetNamedWindowFocus(const char* name)
{
    SetWindowFocus(name);
}

float ImGui_GetScrollX()
{
    return GetScrollX();
}

float ImGui_GetScrollY()
{
    return GetScrollY();
}

float ImGui_GetScrollMaxX()
{
    return GetScrollMaxX();
}

float ImGui_GetScrollMaxY()
{
    return GetScrollMaxY();
}

void ImGui_SetScrollX(float scroll_x)
{
    SetScrollX(scroll_x);
}

void ImGui_SetScrollY(float scroll_y)
{
    SetScrollY(scroll_y);
}

void ImGui_SetScrollHere(float center_y_ratio)
{
    SetScrollHere(center_y_ratio);
}

void ImGui_SetScrollFromPosY(float pos_y, float center_y_ratio)
{
    SetScrollFromPosY(pos_y, center_y_ratio);
}

void ImGui_PushFont(ImFont* font)
{
    PushFont(font);
}

void ImGui_PopFont()
{
    PopFont();
}

void ImGui_PushStyleColor(ImGuiCol idx, vec4 col)
{
    PushStyleColor(idx, ImVec4(col.x, col.y, col.z, col.w));
}

void ImGui_PopStyleColor(int count)
{
    PopStyleColor(count);
}

void ImGui_PushStyleVarFloat(ImGuiStyleVar idx, float val)
{
    PushStyleVar(idx, val);
}

void ImGui_PushStyleVarVec(ImGuiStyleVar idx, vec2 val)
{
    PushStyleVar(idx, ImVec2(val.x, val.y));
}

void ImGui_PopStyleVar(int count)
{
    PopStyleVar(count);
}

vec4 ImGui_GetStyleColor(ImGuiCol idx)
{
    return toCVec4(GetStyleColorVec4(idx));
}

ImFont* ImGui_GetFont()
{
    return GetFont();
}

float ImGui_GetFontSize()
{
    return GetFontSize();
}

vec2 ImGui_GetFontTexUvWhitePixel()
{
    return toCVec2(GetFontTexUvWhitePixel());
}

void ImGui_PushItemWidth(float item_width)
{
    PushItemWidth(item_width);
}

void ImGui_PopItemWidth()
{
    PopItemWidth();
}

float ImGui_CalcItemWidth()
{
    return CalcItemWidth();
}

void ImGui_PushTextWrapPos(float wrap_pos_x)
{
    PushTextWrapPos(wrap_pos_x);
}

void ImGui_PopTextWrapPos()
{
    PopTextWrapPos();
}

void ImGui_PushAllowKeyboardFocus(bool allow_keyboard_focus)
{
    PushAllowKeyboardFocus(allow_keyboard_focus);
}

void ImGui_PopAllowKeyboardFocus()
{
    PopAllowKeyboardFocus();
}

void ImGui_PushButtonRepeat(bool repeat)
{
    PushButtonRepeat(repeat);
}

void ImGui_PopButtonRepeat()
{
    PopButtonRepeat();
}

void ImGui_Separator()
{
    Separator();
}

void ImGui_SameLine(float pos_x, float spacing_w)
{
    SameLine(pos_x, spacing_w);
}

void ImGui_NewLine()
{
    NewLine();
}

void ImGui_Spacing()
{
    Spacing();
}

void ImGui_Dummy(vec2 size)
{
    Dummy(ImVec2(size.x, size.y));
}

void ImGui_Indent(float indent_w)
{
    Indent(indent_w);
}

void ImGui_Unindent(float indent_w)
{
    Unindent(indent_w);
}

void ImGui_BeginGroup()
{
    BeginGroup();
}

void ImGui_EndGroup()
{
    EndGroup();
}

vec2 ImGui_GetCursorPos()
{
    return toCVec2(GetCursorPos());
}

float ImGui_GetCursorPosX()
{
    return GetCursorPosX();
}

float ImGui_GetCursorPosY()
{
    return GetCursorPosY();
}

void ImGui_SetCursorPos(vec2 local_pos)
{
    SetCursorPos(ImVec2(local_pos.x, local_pos.y));
}

void ImGui_SetCursorPosX(float x)
{
    SetCursorPosX(x);
}

void ImGui_SetCursorPosY(float y)
{
    SetCursorPosY(y);
}

vec2 ImGui_GetCursorStartPos()
{
    return toCVec2(GetCursorStartPos());
}

vec2 ImGui_GetCursorScreenPos()
{
    return toCVec2(GetCursorScreenPos());
}

void ImGui_SetCursorScreenPos(vec2 screen_pos)
{
    SetCursorScreenPos(ImVec2(screen_pos.x, screen_pos.y));
}

void ImGui_AlignTextToFramePadding()
{
    AlignTextToFramePadding();
}

float ImGui_GetTextLineHeight()
{
    return GetTextLineHeight();
}

float ImGui_GetTextLineHeightWithSpacing()
{
    return GetTextLineHeightWithSpacing();
}

float ImGui_GetFrameHeight()
{
    return GetFrameHeight();
}

float ImGui_GetFrameHeightWithSpacing()
{
    return GetFrameHeightWithSpacing();
}

void ImGui_PushStrID(const char* str_id)
{
    PushID(str_id);
}

void ImGui_PushPtrID(const void* ptr_id)
{
    PushID(ptr_id);
}

void ImGui_PushIntID(int int_id)
{
    PushID(int_id);
}

void ImGui_PopID()
{
    PopID();
}

void ImGui_TextUnformatted(const char* text, const char* text_end)
{
    TextUnformatted(text, text_end);
}

void ImGui_Text(const char* text)
{
    Text(text);
}

bool ImGui_Button(const char* label, vec2 size)
{
    return Button(label, ImVec2(size.x, size.y));
}

bool ImGui_SmallButton(const char* label)
{
    return SmallButton(label);
}

bool ImGui_InvisibleButton(const char* str_id, vec2 size)
{
    return InvisibleButton(str_id, ImVec2(size.x, size.y));
}

bool ImGui_ArrowButton(const char* str_id, ImGuiDir dir)
{
    return ArrowButton(str_id, dir);
}

void ImGui_Image(ImTextureID user_texture_id, vec2 size, vec2 uv0, vec2 uv1, vec4 tint_col, vec4 border_col)
{
    Image(user_texture_id, ImVec2(size.x, size.y), ImVec2(uv0.x, uv0.y), ImVec2(uv1.x, uv1.y), ImVec4(tint_col.x, tint_col.y, tint_col.z, tint_col.w), ImVec4(border_col.x, border_col.y, border_col.z, border_col.w));
}

bool ImGui_ImageButton(ImTextureID user_texture_id, vec2 size, vec2 uv0, vec2 uv1, int frame_padding, vec4 bg_col, vec4 tint_col)
{
    return ImageButton(user_texture_id, ImVec2(size.x, size.y), ImVec2(uv0.x, uv0.y), ImVec2(uv1.x, uv1.y), frame_padding, ImVec4(bg_col.x, bg_col.y, bg_col.z, bg_col.w), ImVec4(tint_col.x, tint_col.y, tint_col.z, tint_col.w));
}

bool ImGui_Checkbox(const char* label, bool* v)
{
    return Checkbox(label, v);
}

bool ImGui_CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value)
{
    return CheckboxFlags(label, flags, flags_value);
}

bool ImGui_RadioButton(const char* label, bool active)
{
    return RadioButton(label, active);
}

bool ImGui_RadioButtonInt(const char* label, int* v, int v_button)
{
    return RadioButton(label, v, v_button);
}

void ImGui_Bullet()
{
    Bullet();
}

bool ImGui_BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags)
{
    return BeginCombo(label, preview_value, flags);
}

void ImGui_EndCombo()
{
    EndCombo();
}


ImGuiIO& ImGui_GetIO(){
    return GetIO();
}
