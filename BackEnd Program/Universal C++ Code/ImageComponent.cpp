//
//  ImageComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "ImageComponent.hpp"
#include "imgui.h"

ImageComponent::ImageComponent() : BaseComponent(ComponentType::IMAGE_COMPONENT)
{
    NameOfComponent = "New Image Element";
}

void ImageComponent::GUIUpdate(int PageCount, int ComponenetCount)
{
    ImGui::InputText("Name Of Text Element", &NameOfComponent[0], NameOfComponent.size());
    ImGui::InputText("ID Set in HTML", &HTML_ID[0], HTML_ID.size());
    ImGui::InputText("Link To Set on your website", &ImageDirectory[0], ImageDirectory.size());
}

void ImageComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["ImageDirectory"] = ImageDirectory;
    BaseComponent::JsonSaving(json);
}

void ImageComponent::JsonLoad(nlohmann::json* json)
{
    ImageDirectory = (*json)["ImageDirectory"];
    BaseComponent::JsonLoad(json);
}
