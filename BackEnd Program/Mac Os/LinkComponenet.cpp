//
//  LinkComponenet.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "LinkComponenet.hpp"
#include "imgui.h"

LinkComponent::LinkComponent() : BaseComponent(ComponentType::LINK_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Link ELement");
}

void LinkComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    ImGui::InputText("Name Of Text Element", NameOfComponent, IM_ARRAYSIZE(NameOfComponent));
    ImGui::InputText("ID Set in HTML", HTML_ID, IM_ARRAYSIZE(HTML_ID));
    ImGui::InputText("Link To Set on your website", LinkForWebsite, IM_ARRAYSIZE(LinkForWebsite));
}

void LinkComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["URL_Link"] = LinkForWebsite;
    BaseComponent::JsonSaving(json);
}

void LinkComponent::JsonLoad(nlohmann::json* json)
{
    WriteToCharArray(LinkForWebsite, std::string((*json)["URL_Link"]) );
    BaseComponent::JsonLoad(json);
}
