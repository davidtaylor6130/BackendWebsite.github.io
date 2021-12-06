//
//  YoutubeEmbedComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "YoutubeEmbedComponent.hpp"
#include "imgui.h"

YoutubeEmbedComponenet::YoutubeEmbedComponenet() : BaseComponent(ComponentType::YOUTUBE_COMPONENT)
{
    WriteToCharArray(NameOfComponent, "New Youtube Component");
}

void YoutubeEmbedComponenet::GUIUpdate(int PageCount, int ComponentCount) {
    ImGui::InputText("Name Of Text Element", NameOfComponent, IM_ARRAYSIZE(NameOfComponent));
    ImGui::InputText("ID Set in HTML", HTML_ID, IM_ARRAYSIZE(HTML_ID));
    ImGui::InputText("Text To place on your website", YoutubeLink, IM_ARRAYSIZE(YoutubeLink));
}

void YoutubeEmbedComponenet::JsonSaving(nlohmann::json* json) {
    (*json)["YoutubeEmbedLink"] = YoutubeLink;
    BaseComponent::JsonSaving(json);
}

void YoutubeEmbedComponenet::JsonLoad(nlohmann::json* json) {
    WriteToCharArray(NameOfComponent, ((*json)["YoutubeEmbedLink"]));
    BaseComponent::JsonLoad(json);
}
