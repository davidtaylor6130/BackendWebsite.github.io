//
//  YoutubeEmbedComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "YoutubeEmbedComponent.hpp"

#ifdef __APPLE__
#include "imgui.h"
#endif

#ifdef _WIN32
#include "../Windowns Code/imgui.h"
#endif

YoutubeEmbedComponenet::YoutubeEmbedComponenet() : BaseComponent(ComponentType::YOUTUBE_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Youtube Component");
}

void YoutubeEmbedComponenet::GUIUpdate(int PageCount, int ComponentCount)
{
    std::string ID;
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponentCount) + ":" + "1" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("Name", NameOfComponent, IM_ARRAYSIZE(NameOfComponent));
    ImGui::PopID();
    
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponentCount) + ":" + "1" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("ID", HTML_ID, IM_ARRAYSIZE(HTML_ID));
    ImGui::PopID();
    
    ID = std::to_string(PageCount) + ":" + std::to_string(ComponentCount) + ":" + "1" ;
    ImGui::PushID(&ID[0], &ID[ID.length()-1]);
    ImGui::InputText("Youtube Video URL (from embed code)", YoutubeLink, IM_ARRAYSIZE(YoutubeLink));
    ImGui::PopID();
}

void YoutubeEmbedComponenet::JsonSaving(nlohmann::json* json) {
    (*json)["YoutubeEmbedLink"] = YoutubeLink;
    BaseComponent::JsonSaving(json);
}

void YoutubeEmbedComponenet::JsonLoad(nlohmann::json* json) {
    WriteToCharArray(YoutubeLink, ((*json)["YoutubeEmbedLink"]));
    BaseComponent::JsonLoad(json);
}
