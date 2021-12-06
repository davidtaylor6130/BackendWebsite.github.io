//
//  PortfolioSettings.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "PortfolioSettings.hpp"

PortfolioSettings::PortfolioSettings()
{
    jsonFileName.resize(500);
    javascriptFileNmae.resize(500);
}

void PortfolioSettings::UpdateJsonSettings(nlohmann::json* json)
{
    (*json)["JsonFileName"] = jsonFileName;
    (*json)["JavaScriptFileName"] = javascriptFileNmae;
}

void PortfolioSettings::LoadJsonSettings(nlohmann::json* json)
{
    jsonFileName = (*json)["JsonFileName"];
    javascriptFileNmae = (*json)["JavaScriptFileName"];
}
