//
//  BaseComponent.cpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#include "BaseComponent.hpp"

BaseComponent::BaseComponent(ComponentType type)
{
    Type = type;
}

void BaseComponent::JsonSaving(nlohmann::json *json)
{
    (*json)["ComponentType"] = Type;
    (*json)["ComponentHTMLID"] = HTML_ID;
}

void BaseComponent::JsonLoad(nlohmann::json *json)
{
    Type = (*json)["ComponentType"];
    WriteToCharArray(HTML_ID, (*json)["ComponentHTMLID"]);
}

void BaseComponent::WriteToCharArray(char* array, std::string toCopy)
{
    int i = 0;
    for (i = 0; i < toCopy.size(); i++)
        array[i]  = toCopy[i];
    
    array[i] = '\0';
}
