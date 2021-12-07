//
//  LinkComponenet.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "LinkComponenet.hpp"


#ifdef __APPLE__
#include "imgui.h"
#endif

#ifdef _WIN32
#include "../Windowns Code/imgui.h"
#endif

LinkComponent::LinkComponent() : BaseComponent(ComponentType::LINK_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Link ELement");
}

void LinkComponent::GUIUpdate(int PageCount, int ComponenetCount)
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
    ImGui::InputText("Link To Website (full url including https://)", LinkForWebsite, IM_ARRAYSIZE(LinkForWebsite));
    ImGui::PopID();
}

void LinkComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["URL_Link"] = LinkForWebsite;
    BaseComponent::JsonSaving(json);
}

void LinkComponent::JsonLoad(nlohmann::json* json)
{
    WriteToCharArray(LinkForWebsite, (*json)["URL_Link"] );
    BaseComponent::JsonLoad(json);
}
