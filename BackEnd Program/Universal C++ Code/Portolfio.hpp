//
//  Portolfio.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef Portolfio_hpp
#define Portolfio_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Project Data.hpp"
#include "PortfolioSettings.hpp"

class Portfolio {
public:
    Portfolio();
    
    ProjectData newProject;
    
    std::vector<std::string> Outputlog;
    
    std::vector<ProjectData*> projectData;
    PortfolioSettings settings;
    
    int selectedIndex = -1;
    int previousSelectedIndex = -1;
    
    ProjectData* GetCurrentlySelectedProject()
    {
        if (selectedIndex == -1)
        {
            return &newProject;
        }
        
        return projectData[selectedIndex];
    }
    
    void SaveElementsToJson();
    void LoadFromJson();
    void GenerateJavascript();
    void AddToLog(std::string toAdd);
    void OutputLogGUICall();
    void ClearLog();
};

#endif /* Portolfio_hpp */
