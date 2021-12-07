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
    WriteToCharArray(NameOfComponent, "New Image Element");
}

void ImageComponent::GUIUpdate(int PageCount, int ComponenetCount)
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
    ImGui::InputText("Image Directory", ImageDirectory, IM_ARRAYSIZE(ImageDirectory));
    ImGui::PopID();
}

void ImageComponent::JsonSaving(nlohmann::json* json)
{
    (*json)["ImageDirectory"] = ImageDirectory;
    BaseComponent::JsonSaving(json);
}

void ImageComponent::JsonLoad(nlohmann::json* json)
{
    WriteToCharArray(ImageDirectory, std::string((*json)["ImageDirectory"]));
    BaseComponent::JsonLoad(json);
}
