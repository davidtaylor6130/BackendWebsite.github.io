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

class PortfolioSettings {
public:
    
    std::string jsonFileName = "FILE NOT SET";
    std::string javascriptFileNmae = "FILE NOT SET";
    
    bool isDataDirty;
};

#endif /* PortfolioSettings_hpp */
