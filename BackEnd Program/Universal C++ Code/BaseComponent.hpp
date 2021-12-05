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

class BaseComponent{
public:
    std::string NameOfComponent = "NEW TEXT ELEMENT";
    std::string HTML_ID = "NO ID SET";
    
    virtual void GUIUpdate(int PageCount, int ComponentCount) = 0;
    virtual void JsonSaving() = 0;
    virtual void JsonLoad() = 0;
};

#endif /* BaseComponent_hpp */
