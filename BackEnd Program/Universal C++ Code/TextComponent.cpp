//
//  TextComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "TextComponent.hpp"
#include "imgui.h"

TextComponent::TextComponent() : BaseComponent()
{
    NameOfComponent = "New Text Element";
}

void TextComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    ImGui::InputText("Name Of Text Element", &NameOfComponent[0], NameOfComponent.size());
    ImGui::InputText("ID Set in HTML", &HTML_ID[0], HTML_ID.size());
    ImGui::InputText("Text To place on your website", &TextForWebsite[0], TextForWebsite.size());
}

void TextComponent::JsonSaving()
{
    
}

void TextComponent::JsonLoad()
{
    
}
