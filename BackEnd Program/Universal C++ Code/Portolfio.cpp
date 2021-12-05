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
#include <filesystem>

void Portfolio::SaveElementsToJson()
{
    //- File Generaton -//
    std::ofstream OutputJsonFile(settings.jsonFileName);
    
    nlohmann::json json;
    (json)["Project Count"] = projectData.size();
    
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
    
}
