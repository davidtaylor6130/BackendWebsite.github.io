//
//  YoutubeEmbedComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "YoutubeEmbedComponent.hpp"
#include "imgui.h"

YoutubeEmbedComponenet::YoutubeEmbedComponenet()
{
    
}

void YoutubeEmbedComponenet::GUIUpdate(int PageCount, int ComponentCount) {
    ImGui::InputText("Name Of Text Element", &NameOfComponent[0], NameOfComponent.size());
    ImGui::InputText("ID Set in HTML", &HTML_ID[0], HTML_ID.size());
    ImGui::InputText("Text To place on your website", &YoutubeLink[0], YoutubeLink.size());
}

void YoutubeEmbedComponenet::JsonLoad() {
    
}

void YoutubeEmbedComponenet::JsonSaving() {
    
}
