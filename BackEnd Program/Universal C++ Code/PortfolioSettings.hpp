//
//  PortfolioSettings.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef PortfolioSettings_hpp
#define PortfolioSettings_hpp

#include <stdio.h>
#include <string>
#include "Json For Modern C++/json.hpp"

class PortfolioSettings {
public:
    PortfolioSettings();
    
    std::string jsonFileName;
    std::string javascriptFileNmae;
    
    bool isDataDirty;
    
    void UpdateJsonSettings(nlohmann::json* json);
    void LoadJsonSettings(nlohmann::json* json);
};

#endif /* PortfolioSettings_hpp */
