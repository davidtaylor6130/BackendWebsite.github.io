//
//  Project Data.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "Project Data.hpp"
#include "TextComponent.hpp"
#include "ImageComponent.hpp"
#include "LinkComponenet.hpp"
#include "YoutubeEmbedComponent.hpp"
#include "imgui.h"
#include "Json For Modern C++/json.hpp"

void ProjectData::GuiCall(int ID_Counter) {
    
    ImGui::Spacing();
    ImGui::InputText("Portfolio Name", &ProjectName[0], ProjectName.length());
    ImGui::Checkbox("Is This Project on your portfolio", &IsThisProjectActive);
    
    for (int i = 0; i < PortfolioElements.size(); i++)
    {
        ImGui::Separator();
        ImGui::Spacing();
        std::string ID = std::to_string(ID_Counter) + ":" + std::to_string(i);
        ImGui::PushID(&ID[0], &ID[ID.length()-1]);
        
        bool ShowComponentGUI = ImGui::CollapsingHeader((PortfolioElements[i]->NameOfComponent), ImGuiTreeNodeFlags_AllowItemOverlap);
        ImGui::SameLine(ImGui::GetWindowWidth() - 25);
        bool RemoveComponent = ImGui::Button("X");
        
        if (ShowComponentGUI)
        {
            PortfolioElements[i]->GUIUpdate(ID_Counter, i);
        }
        
        if (RemoveComponent)
        {
            PortfolioElements.erase(PortfolioElements.begin() + i);
        }
        ImGui::PopID();
        ImGui::Spacing();
    }
}

void ProjectData::SaveToJson(nlohmann::json* json)
{
    (*json)["ProjectName"] = ProjectName;
    (*json)["IsProjectActive"] = IsThisProjectActive;
    (*json)["ElementCount"] = PortfolioElements.size();
    for (int i = 0; i < PortfolioElements.size(); i++)
    {
        nlohmann::json PortfolioJson;
        PortfolioElements[i]->JsonSaving(&PortfolioJson);
        (*json)["PortolfioElements"] += PortfolioJson;
    }
}

void ProjectData::LoadFromJson(nlohmann::json* json)
{
    ProjectName = (*json)["ProjectName"];
    IsThisProjectActive = (*json)["IsProjectActive"];
    int ElementCount = (*json)["ElementCount"];
    for (int i = 0; i < ElementCount; i++)
    {
        int temp = (int)(*json)["PortolfioElements"][i]["ComponentType"];
        
        switch (temp)
        {
            case (int)ComponentType::TEXT_COMPONENT:
                AddNewElement<TextComponent>();
                break;
                
            case (int)ComponentType::LINK_COMPONENT :
                AddNewElement<LinkComponent>();
                break;
                
            case (int)ComponentType::YOUTUBE_COMPONENT:
                AddNewElement<YoutubeEmbedComponenet>();
                break;
                
            case (int)ComponentType::IMAGE_COMPONENT:
                AddNewElement<ImageComponent>();
                break;
        }
        nlohmann::json* temp1 = &(*json)["PortolfioElements"][i];
        PortfolioElements[i]->JsonLoad(temp1);
    }
}
