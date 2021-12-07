//
//  Portolfio.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "Portolfio.hpp"
#include <string>

#include <ostream>
#include <fstream>

#include "imgui.h"

#include "TextComponent.hpp"
#include "ImageComponent.hpp"
#include "LinkComponenet.hpp"
#include "YoutubeEmbedComponent.hpp"

Portfolio::Portfolio()
{
}

void Portfolio::SaveElementsToJson()
{
    //- File Generaton -//
    std::ofstream OutputJsonFile(settings.jsonFileName);
    
    nlohmann::json json;
    (json)["Project Count"] = projectData.size();
    json["BackendToolVersion"] = "V-1.0.0";
    
    for (int i = 0; i < projectData.size(); i++)
    {
        nlohmann::json ProjectJson;
        projectData[i]->SaveToJson(&ProjectJson);
        json["Projects"] += ProjectJson;
    }
    
    OutputJsonFile << json;
    OutputJsonFile.close();
}

void Portfolio::LoadFromJson()
{
    projectData.clear();
    
    //- File Read -//
    std::ifstream InputJsonFile;
    InputJsonFile.open(settings.jsonFileName);
    
    nlohmann::json InputJson;
    
    InputJsonFile >> InputJson;
    
    int ProjectCount = InputJson["Project Count"];
    for (int i = 0; i < ProjectCount; i++)
    {
        projectData.push_back(new ProjectData());
        projectData[i]->LoadFromJson(&(InputJson["Projects"][i]));
    }
}

void Portfolio::GenerateJavascript()
{
    LoadFromJson();
    std::ofstream JavascriptFile(settings.javascriptFileNmae);
    
    JavascriptFile << "var portfolioJson;" << std::endl;
    JavascriptFile << "// Write Jacascript Here" << std::endl;
    JavascriptFile << "function LoadPortfolioWebsite(){" << std::endl;
    JavascriptFile << " LoadPortfolio(" << '\u0022' << settings.jsonFileName << '\u0022' << ")" << std::endl;
    JavascriptFile << "}" << std::endl;
    JavascriptFile << std::endl;
    JavascriptFile << "function LoadPortfolio(SettingFileLocation) {" << std::endl;
    JavascriptFile << "  //fetch(SettingFileLocation).then(function(resp) {return resp.json();}).then(function(data){console.log(data); portfolioJson = data; CreateHTMLProjectElements();});" << std::endl;
    JavascriptFile << "  CreateHTMLProjectElements();" << std::endl;
    JavascriptFile << "}" << std::endl;
    JavascriptFile << std::endl;
    JavascriptFile << "function CreateHTMLProjectElements(){" << std::endl;
    JavascriptFile << std::endl;
    
    for (int i = 0 ; i < projectData.size(); i++)
    {
        JavascriptFile << std::endl;
        JavascriptFile << " // Project number: " + std::to_string(i) << std::endl;
        for (int j = 0; j < projectData[i]->PortfolioElements.size(); j++)
        {
            JavascriptFile << " //Element "<< std::to_string(j) <<  std::endl;
            std::string temp;
            
            switch (projectData[i]->PortfolioElements[j]->Type) {
                    
                case ComponentType::TEXT_COMPONENT:
                    JavascriptFile << " // Text Component" << std::endl;
                    JavascriptFile << " var portolioElemet = document.getElementById(" << '\u0022' << projectData[i]->PortfolioElements[j]->HTML_ID << '\u0022' << ");" << std::endl;
                    temp = dynamic_cast<TextComponent*>(projectData[i]->PortfolioElements[j])->TextForWebsite;
                    JavascriptFile << " portolioElemet.innerHTML = " << '\u0022' << temp << '\u0022' << ";" << std::endl;
                    break;
                    
                case ComponentType::LINK_COMPONENT:
                    JavascriptFile << " // Link Component" << std::endl;
                    JavascriptFile << " var portolioElemet = document.getElementById(" << '\u0022' << projectData[i]->PortfolioElements[j]->HTML_ID << '\u0022' << ");" << std::endl;
                    temp = dynamic_cast<LinkComponent*>(projectData[i]->PortfolioElements[j])->LinkForWebsite;
                    JavascriptFile << " portolioElemet.href = " << '\u0022' << temp << '\u0022' << ";" << std::endl;
                    break;
                    
                case ComponentType::IMAGE_COMPONENT:
                    JavascriptFile << " // Image Component" << std::endl;
                    JavascriptFile << " var portolioElemet = document.getElementById(" << '\u0022' << projectData[i]->PortfolioElements[j]->HTML_ID << '\u0022' << ");" << std::endl;
                    temp = dynamic_cast<ImageComponent*>(projectData[i]->PortfolioElements[j])->ImageDirectory;
                    JavascriptFile << " portolioElemet.src = " << '\u0022' << temp << '\u0022' << ";" << std::endl;
                    break;
                    
                case ComponentType::YOUTUBE_COMPONENT:
                    JavascriptFile << " // Youtube Component" << std::endl;
                    JavascriptFile << " var portolioElemet = document.getElementById(" << '\u0022' << projectData[i]->PortfolioElements[j]->HTML_ID << '\u0022' << ");" << std::endl;
                    temp = dynamic_cast<YoutubeEmbedComponenet*>(projectData[i]->PortfolioElements[j])->YoutubeLink;
                    JavascriptFile << " portolioElemet.src = " << '\u0022' << temp << '\u0022' << ";" << std::endl;
                    break;
                    
                default:
                    break;
            }
        }
    }
    
    JavascriptFile << std::endl;
    JavascriptFile << "}" << std::endl;
    
    JavascriptFile << "" << std::endl;
}

void Portfolio::OutputLogGUICall()
{
    for (int i = 0; i < Outputlog.size(); i++)
    {
        ImGui::PushID(i);
        ImGui::Text(&((Outputlog[i])[0]));
        ImGui::PopID();
    }
}

void Portfolio::AddToLog(std::string toAdd)
{
    Outputlog.push_back(toAdd);
}

void Portfolio::ClearLog()
{
    Outputlog.clear();
}
