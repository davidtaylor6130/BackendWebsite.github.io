//
//  Project Main.cpp
//  example_apple_metal
//
//  Created by David Taylor on 02/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "Project Main.hpp"
#include "imgui.h"

#include "TextComponent.hpp"
#include "ImageComponent.hpp"
#include "LinkComponenet.hpp"
#include "YoutubeEmbedComponent.hpp"

UniversalCPPCode::UniversalCPPCode()
{
    portfolio = new Portfolio();
}

UniversalCPPCode::~UniversalCPPCode()
{
    
}

void UniversalCPPCode::Update()
{
    //---------- PLACE GUI CODE HERE
    static bool p_NULL = NULL;
    ImGui::Begin("Settings", &p_NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::SetWindowPos(ImVec2(0,0));
    ImGui::SetWindowSize(ImVec2(300, 300));
    
    
    if (portfolio->settings.isDataDirty)
    {
        ImGui::Text("YOU NEED TO SAVE");
    }
    else
    {
        ImGui::Text("All Changes Saved");
    }
    
    if (ImGui::TreeNode("Javascript Settings"))
    {
        ImGui::InputText("JavaScript File Directory", &portfolio->settings.javascriptFileNmae[0], portfolio->settings.javascriptFileNmae.length());
        ImGui::TreePop();
    }
    if (ImGui::TreeNode("Generic Settings"))
    {
        ImGui::InputText("JavaScript File Directory", &portfolio->settings.jsonFileName[0], portfolio->settings.jsonFileName.length());
        ImGui::TreePop();
    }
    
    if (ImGui::Button("Save Portfolio Changes"))
    {
        portfolio->settings.isDataDirty = false;
        portfolio->SaveElementsToJson();
        portfolio->GenerateJavascript();
    }
    
    if (ImGui::Button("Load Portfolio Via Json"))
    {
        portfolio->LoadFromJson();
    }
    
    ImGui::Separator();
    
    if (ImGui::Button("Genarate Javascript Code"))
    {
        portfolio->GenerateJavascript();
    }
    
    ImGui::End();

    ImGui::Begin("Portfolio", &p_NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::SetWindowPos(ImVec2(300,0));
    ImGui::SetWindowSize(ImVec2(900, 1000));
    
    ImGui::BeginTabBar("Projects");
    
    int ID_Counter = 0;
    for (int i = 0; i < portfolio->projectData.size(); i++)
    {
        ID_Counter++;
        ImGui::PushID(ID_Counter);
        
        
        if (ImGui::BeginTabItem(&portfolio->projectData[i]->ProjectName[0], &portfolio->projectData[i]->IsOpen))
        {
            portfolio->selectedIndex = i;
            portfolio->projectData[i]->GuiCall(ID_Counter);
            ImGui::EndTabItem();
        }
        ImGui::PopID();
        
    }
    
    portfolio->previousSelectedIndex = portfolio->selectedIndex;
    ImGui::EndTabBar();
    
    ImGui::End();
    
    
    ImGui::Begin("ToolBox", &p_NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::SetWindowPos(ImVec2(0,300));
    ImGui::SetWindowSize(ImVec2(300, 500));
    
    if (ImGui::Button("Add New Project to your portfolio"))
    {
        portfolio->projectData.push_back(new ProjectData());
    }
    
    if (ImGui::Button("Remove Current Project From Portfolio"))
    {
        portfolio->projectData.erase(portfolio->projectData.begin() + portfolio->selectedIndex);
    }
    
    ImGui::Separator();
    
    if (ImGui::Button("Add Text Element"))
    {
        portfolio->GetCurrentlySelectedProject()->AddNewElement<TextComponent>();
    }
    if (ImGui::Button("Add Youtube Embed Element"))
    {
        portfolio->GetCurrentlySelectedProject()->AddNewElement<YoutubeEmbedComponenet>();
    }
    if (ImGui::Button("Add Link Element"))
    {
        portfolio->GetCurrentlySelectedProject()->AddNewElement<LinkComponent>();
    }
    if (ImGui::Button("Add Image Element"))
    {
        portfolio->GetCurrentlySelectedProject()->AddNewElement<ImageComponent>();
    }
    
    ImGui::End();
    
}
