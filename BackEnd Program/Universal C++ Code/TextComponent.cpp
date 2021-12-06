//
//  TextComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "TextComponent.hpp"
#include "imgui.h"

TextComponent::TextComponent() : BaseComponent(ComponentType::TEXT_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Text Element");
}

void TextComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    ImGui::InputText("Name Of Text Element", NameOfComponent, IM_ARRAYSIZE(NameOfComponent));
    ImGui::InputText("ID Set in HTML", HTML_ID, IM_ARRAYSIZE(HTML_ID));
    ImGui::InputText("Text To place on your website", TextForWebsite, IM_ARRAYSIZE(TextForWebsite));
}

void TextComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["TextForWebsite"] = TextForWebsite;
    BaseComponent::JsonSaving(json);
}

void TextComponent::JsonLoad(nlohmann::json* json)
{
    WriteToCharArray(TextForWebsite, std::string((*json)["TextForWebsitw"]));
    BaseComponent::JsonLoad(json);
}
