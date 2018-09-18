#include <imgui/imgui.h>
#include "lak/pyexport.h"

#ifndef PYGUI_H
#define PYGUI_H

PY_EXPORT bool ImGui_Begin(const char* name, bool* p_open, ImGuiWindowFlags flags);
PY_EXPORT void ImGui_End();
PY_EXPORT bool ImGui_BeginChild(const char* str_id, float width, float height, bool border, ImGuiWindowFlags flags);
PY_EXPORT void ImGui_EndChid();

PY_EXPORT bool ImGui_IswindowAppearing();
PY_EXPORT bool ImGui_IsWindowCollapsed();
PY_EXPORT bool ImGui_IsWindowFocused(ImGuiFocusedFlags flags);
PY_EXPORT bool ImGui_IsWindowHovered(ImGuiHoveredFlags flags);

PY_EXPORT void ImGui_Separator();
PY_EXPORT void ImGui_SameLine(float pos_x, float spacing_w);
PY_EXPORT void ImGui_NewLine();
PY_EXPORT void ImGui_Spacing();
PY_EXPORT void ImGui_Dummy(float width, float height);
PY_EXPORT void ImGui_Indent(float indent_w);
PY_EXPORT void ImGui_Unindent(float indent_w);

PY_EXPORT void ImGui_BeginGroup();
PY_EXPORT void ImGui_EndGroup();

PY_EXPORT void ImGui_TextUnformatted(const char* text, const char* text_end);
// PY_EXPORT void ImGui_Text(const char* fmt, ...);

PY_EXPORT bool ImGui_Button(const char* label, float width, float height);
PY_EXPORT bool ImGui_SmallButton(const char* label);
PY_EXPORT bool ImGui_InvisibleButton(const char* str_id, float width, float height);
PY_EXPORT bool ImGui_ArrowButton(const char* str_id, ImGuiDir dir);

#endif // PYGUI_H