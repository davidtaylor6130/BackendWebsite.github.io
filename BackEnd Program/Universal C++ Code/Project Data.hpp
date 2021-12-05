//
//  Project Data.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef Project_Data_hpp
#define Project_Data_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "BaseComponent.hpp"

class ProjectData {
public:
    std::string ProjectName = "New Project";
    bool IsThisProjectActive = true;
    
    std::vector<BaseComponent*> PortfolioElements;
    bool IsOpen = true;
    
    
    void GuiCall(int PageCounter);
    void SaveToJson(nlohmann::json* json);
    void LoadFromJson(nlohmann::json* json);
    
    
    template <typename T>
    void AddNewElement()
    {
        PortfolioElements.push_back(new T());
    }
};

#endif /* Project_Data_hpp */
