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
    NameOfComponent = "New Youtube Component";
}

void YoutubeEmbedComponenet::GUIUpdate(int PageCount, int ComponentCount) {
    ImGui::InputText("Name Of Text Element", &NameOfComponent[0], NameOfComponent.size());
    ImGui::InputText("ID Set in HTML", &HTML_ID[0], HTML_ID.size());
    ImGui::InputText("Text To place on your website", &YoutubeLink[0], YoutubeLink.size());
}

void YoutubeEmbedComponenet::JsonSaving(nlohmann::json* json) {
    (*json)["YoutubeEmbedLink"] = YoutubeLink;
    BaseComponent::JsonSaving(json);
}

void YoutubeEmbedComponenet::JsonLoad(nlohmann::json* json) {
    YoutubeLink = (*json)["YoutubeEmbedLink"];
    BaseComponent::JsonLoad(json);
}
