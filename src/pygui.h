#include <imgui/imgui.h>
#include "lak/pyexport.h"

#ifndef PYGUI_H
#define PYGUI_H

using namespace ImGui;

struct vec2
{
    float x, y;
};

vec2 toCVec2(const ImVec2 &vec);
vec2 toCVec2(ImVec2 &&vec);

struct vec4
{
    float x, y, z, w;
};

vec4 toCVec4(const ImVec4 &vec);
vec4 toCVec4(ImVec4 &&vec);

PY_EXPORT bool ImGui_Begin(const char* name, bool* p_open, ImGuiWindowFlags flags);
PY_EXPORT void ImGui_End();
PY_EXPORT bool ImGui_BeginChild(const char* str_id, vec2 size, bool border, ImGuiWindowFlags flags);
PY_EXPORT void ImGui_EndChild();

PY_EXPORT bool ImGui_IsWindowAppearing();
PY_EXPORT bool ImGui_IsWindowCollapsed();
PY_EXPORT bool ImGui_IsWindowFocused(ImGuiFocusedFlags flags);
PY_EXPORT bool ImGui_IsWindowHovered(ImGuiHoveredFlags flags);

PY_EXPORT ImDrawList* ImGui_GetWindowDrawList();
PY_EXPORT vec2 ImGui_GetWindowPos();
PY_EXPORT vec2 ImGui_GetWindowSize();
PY_EXPORT float ImGui_GetWindowWidth();
PY_EXPORT float ImGui_GetWindowHeight();

PY_EXPORT vec2 ImGui_GetContentRegionMax();
PY_EXPORT vec2 ImGui_GetContentRegionAvail();
PY_EXPORT float ImGui_GetContentRegionAvailWidth();

PY_EXPORT vec2 ImGui_GetWindowContentRegionMin();
PY_EXPORT vec2 ImGui_GetWindowContentRegionMax();
PY_EXPORT float ImGui_GetWindowContentRegionWidth();

PY_EXPORT void ImGui_SetNextWindowPos(vec2 pos, ImGuiCond cond, vec2 pivot);
PY_EXPORT void ImGui_SetNextWindowSize(vec2 size, ImGuiCond cond);
PY_EXPORT void ImGui_SetNextWindowSizeConstraints(vec2 size_min, vec2 size_max, ImGuiSizeCallback custom_callback, void* custom_callback_data);
PY_EXPORT void ImGui_SetNextWindowContentSize(vec2 size);
PY_EXPORT void ImGui_SetNextWindowCollapsed(bool collapsed, ImGuiCond cond);
PY_EXPORT void ImGui_SetNextWindowFocus();
PY_EXPORT void ImGui_SetNextWindowBgAlpha(float alpha);

PY_EXPORT void ImGui_SetWindowPos(vec2 pos, ImGuiCond cond);
PY_EXPORT void ImGui_SetWindowSize(vec2 size, ImGuiCond cond);
PY_EXPORT void ImGui_SetWindowCollapsed(bool collapsed, ImGuiCond cond);
PY_EXPORT void ImGui_SetWindowFocus();
PY_EXPORT void ImGui_SetWindowFontScale(float scale);

PY_EXPORT void ImGui_SetNamedWindowPos(const char* name, vec2 pos, ImGuiCond cond);
PY_EXPORT void ImGui_SetNamedWindowSize(const char* name, vec2 size, ImGuiCond cond);
PY_EXPORT void ImGui_SetNamedWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond);
PY_EXPORT void ImGui_SetNamedWindowFocus(const char* name);

PY_EXPORT float ImGui_GetScrollX();
PY_EXPORT float ImGui_GetScrollY();
PY_EXPORT float ImGui_GetScrollMaxX();
PY_EXPORT float ImGui_GetScrollMaxY();
PY_EXPORT void ImGui_SetScrollX(float scroll_x);
PY_EXPORT void ImGui_SetScrollY(float scroll_y);
PY_EXPORT void ImGui_SetScrollHere(float center_y_ratio);
PY_EXPORT void ImGui_SetScrollFromPosY(float pos_y, float center_y_ratio);

PY_EXPORT void ImGui_PushFont(ImFont* font);
PY_EXPORT void ImGui_PopFont();
PY_EXPORT void ImGui_PushStyleColor(ImGuiCol idx, vec4 col);
PY_EXPORT void ImGui_PopStyleColor(int count);
PY_EXPORT void ImGui_PushStyleVarFloat(ImGuiStyleVar idx, float val);
PY_EXPORT void ImGui_PushStyleVarVec(ImGuiStyleVar idx, vec2 val);
PY_EXPORT void ImGui_PopStyleVar(int count);
PY_EXPORT vec4 ImGui_GetStyleColor(ImGuiCol idx);

PY_EXPORT ImFont* ImGui_GetFont();
PY_EXPORT float ImGui_GetFontSize();
PY_EXPORT vec2 ImGui_GetFontTexUvWhitePixel();

PY_EXPORT void ImGui_PushItemWidth(float item_width);
PY_EXPORT void ImGui_PopItemWidth();
PY_EXPORT float ImGui_CalcItemWidth();
PY_EXPORT void ImGui_PushTextWrapPos(float wrap_pos_x);
PY_EXPORT void ImGui_PopTextWrapPos();
PY_EXPORT void ImGui_PushAllowKeyboardFocus(bool allow_keyboard_focus);
PY_EXPORT void ImGui_PopAllowKeyboardFocus();
PY_EXPORT void ImGui_PushButtonRepeat(bool repeat);
PY_EXPORT void ImGui_PopButtonRepeat();

PY_EXPORT void ImGui_Separator();
PY_EXPORT void ImGui_SameLine(float pos_x, float spacing_w);
PY_EXPORT void ImGui_NewLine();
PY_EXPORT void ImGui_Spacing();
PY_EXPORT void ImGui_Dummy(vec2 size);
PY_EXPORT void ImGui_Indent(float indent_w);
PY_EXPORT void ImGui_Unindent(float indent_w);

PY_EXPORT void ImGui_BeginGroup();
PY_EXPORT void ImGui_EndGroup();

PY_EXPORT vec2 ImGui_GetCursorPos();
PY_EXPORT float ImGui_GetCursorPosX();
PY_EXPORT float ImGui_GetCursorPosY();
PY_EXPORT void ImGui_SetCursorPos(vec2 local_pos);
PY_EXPORT void ImGui_SetCursorPosX(float x);
PY_EXPORT void ImGui_SetCursorPosY(float y);
PY_EXPORT vec2 ImGui_GetCursorStartPos();
PY_EXPORT vec2 ImGui_GetCursorScreenPos();
PY_EXPORT void ImGui_SetCursorScreenPos(vec2 screen_pos);

PY_EXPORT void ImGui_AlignTextToFramePadding();
PY_EXPORT float ImGui_GetTextLineHeight();
PY_EXPORT float ImGui_GetTextLineHeightWithSpacing();
PY_EXPORT float ImGui_GetFrameHeight();
PY_EXPORT float ImGui_GetFrameHeightWithSpacing();

PY_EXPORT void ImGui_PushStrID(const char* str_id);
PY_EXPORT void ImGui_PushPtrID(const void* ptr_id);
PY_EXPORT void ImGui_PushIntID(int int_id);
PY_EXPORT void ImGui_PopID();

PY_EXPORT void ImGui_TextUnformatted(const char* text, const char* text_end);
PY_EXPORT void ImGui_Text(const char* text);

PY_EXPORT bool ImGui_Button(const char* label, vec2 size);
PY_EXPORT bool ImGui_SmallButton(const char* label);
PY_EXPORT bool ImGui_InvisibleButton(const char* str_id, vec2 size);
PY_EXPORT bool ImGui_ArrowButton(const char* str_id, ImGuiDir dir);

PY_EXPORT void ImGui_Image(ImTextureID user_texture_id, vec2 size, vec2 uv0, vec2 uv1, vec4 tint_col, vec4 border_col);
PY_EXPORT bool ImGui_ImageButton(ImTextureID user_texture_id, vec2 size, vec2 uv0, vec2 uv1, int frame_padding, vec4 bg_col, vec4 tint_col);

PY_EXPORT bool ImGui_Checkbox(const char* label, bool* v);
PY_EXPORT bool ImGui_CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value);

PY_EXPORT bool ImGui_RadioButton(const char* label, bool active);
PY_EXPORT bool ImGui_RadioButtonInt(const char* label, int* v, int v_button);

// PY_EXPORT void ImGui_PlotLines

PY_EXPORT void ImGui_Bullet();

PY_EXPORT bool ImGui_BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags);
PY_EXPORT void ImGui_EndCombo();



#endif // PYGUI_H