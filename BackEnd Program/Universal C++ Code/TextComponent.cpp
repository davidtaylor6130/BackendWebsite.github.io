//
//  TextComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "TextComponent.hpp"

#ifdef __APPLE__
#include "imgui.h"
#endif

#ifdef _WIN32
#include "../Windowns Code/imgui.h"
#endif

TextComponent::TextComponent() : BaseComponent(ComponentType::TEXT_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Text Element");
}

void TextComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    std::string ID;
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponenetCount) + ":" + "1" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("Name", NameOfComponent, IM_ARRAYSIZE(NameOfComponent));
    ImGui::PopID();
    
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponenetCount) + ":" + "2" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("ID", HTML_ID, IM_ARRAYSIZE(HTML_ID));
    ImGui::PopID();
    
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponenetCount) + ":" + "3" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("Text", TextForWebsite, IM_ARRAYSIZE(TextForWebsite));
    ImGui::PopID();
}

void TextComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["TextForWebsite"] = TextForWebsite;
    BaseComponent::JsonSaving(json);
}

void TextComponent::JsonLoad(nlohmann::json* json)
{
    WriteToCharArray(TextForWebsite, (*json)["TextForWebsite"]);
    BaseComponent::JsonLoad(json);
}
