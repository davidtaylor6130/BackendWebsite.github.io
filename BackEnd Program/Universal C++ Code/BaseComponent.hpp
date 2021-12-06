//
//  BaseComponent.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef BaseComponent_hpp
#define BaseComponent_hpp

#include <stdio.h>
#include <string>
#include "Json For Modern C++/json.hpp"

#define CharacterLengthMax 500

enum class ComponentType
{
    BASE_COMPONENT = 0,
    TEXT_COMPONENT,
    LINK_COMPONENT,
    IMAGE_COMPONENT,
    YOUTUBE_COMPONENT
};

class BaseComponent{
public:
    BaseComponent(ComponentType type);
    
    char NameOfComponent[CharacterLengthMax] = "NEW TEXT ELEMENT";
    char HTML_ID[CharacterLengthMax] = "NO ID SET";
    
    ComponentType Type;
    
    virtual void GUIUpdate(int PageCount, int ComponentCount) = 0;
    virtual void JsonSaving(nlohmann::json* json) = 0;
    virtual void JsonLoad(nlohmann::json* json) = 0;
    
    void WriteToCharArray(char* array, std::string toCopy);
};

#endif /* BaseComponent_hpp */
