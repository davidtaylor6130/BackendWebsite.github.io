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
}

void BaseComponent::JsonLoad(nlohmann::json *json)
{
    Type = (*json)["ComponentType"];
}
