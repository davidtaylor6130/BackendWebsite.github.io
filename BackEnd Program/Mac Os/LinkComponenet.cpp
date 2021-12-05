//
//  LinkComponenet.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "LinkComponenet.hpp"
#include "imgui.h"

LinkComponent::LinkComponent() : BaseComponent()
{
    NameOfComponent = "New Link Element";
}

void LinkComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    ImGui::InputText("Name Of Text Element", &NameOfComponent[0], NameOfComponent.size());
    ImGui::InputText("ID Set in HTML", &HTML_ID[0], HTML_ID.size());
    ImGui::InputText("Link To Set on your website", &LinkForWebsite[0], LinkForWebsite.size());
}

void LinkComponent::JsonSaving()
{
    
}

void LinkComponent::JsonLoad()
{
    
}
