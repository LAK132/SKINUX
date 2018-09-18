#include "pygui.h"

bool ImGui_Begin(const char* name, bool* p_open, ImGuiWindowFlags flags)
{
    return ImGui::Begin(name, p_open, flags);
}

void ImGui_End()
{
    ImGui::End();
}

bool ImGui_BeginChild(const char* str_id, float width, float height, bool border, ImGuiWindowFlags flags)
{
    ImGui::BeginChild(str_id, ImVec2(width, height), border, flags);
}

void ImGui_EndChid()
{
    ImGui::EndChild();
}

bool ImGui_IswindowAppearing()
{
    return ImGui::IsWindowAppearing();
}

bool ImGui_IsWindowCollapsed()
{
    return ImGui::IsWindowCollapsed();
}

bool ImGui_IsWindowFocused(ImGuiFocusedFlags flags)
{
    return ImGui::IsWindowFocused(flags);
}

bool ImGui_IsWindowHovered(ImGuiHoveredFlags flags)
{
    ImGui::IsWindowHovered(flags);
}

void ImGui_Separator()
{
    ImGui::Separator();
}

void ImGui_SameLine(float pos_x, float spacing_w)
{
    ImGui::SameLine(pos_x, spacing_w);
}

void ImGui_NewLine()
{
    ImGui::NewLine();
}

void ImGui_Spacing()
{
    ImGui::Spacing();
}

void ImGui_Dummy(float width, float height)
{
    ImGui::Dummy(ImVec2(width, height));
}

void ImGui_Indent(float indent_w)
{
    ImGui::Indent(indent_w);
}

void ImGui_Unindent(float indent_w)
{
    ImGui::Unindent(indent_w);
}

void ImGui_BeginGroup()
{
    ImGui::BeginGroup();
}

void ImGui_EndGroup()
{
    ImGui::EndGroup();
}

void ImGui_TextUnformatted(const char* text, const char* text_end)
{
    ImGui::TextUnformatted(text, text_end);
}

// void ImGui_Text(const char* fmt, ...)
// {
// }

bool ImGui_Button(const char* label, float width, float height)
{
    return ImGui::Button(label, ImVec2(width, height));
}

bool ImGui_SmallButton(const char* label)
{
    return ImGui::SmallButton(label);
}

bool ImGui_InvisibleButton(const char* str_id, float width, float height)
{
    return ImGui::InvisibleButton(str_id, ImVec2(width, height));
}

bool ImGui_ArrowButton(const char* str_id, ImGuiDir dir)
{
    return ImGui::ArrowButton(str_id, dir);
}
