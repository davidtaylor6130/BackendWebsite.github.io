//
//  TextComponent.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef TextComponent_hpp
#define TextComponent_hpp

#include <stdio.h>
#include "BaseComponent.hpp"

class TextComponent : public BaseComponent {
public:
    TextComponent();
    
    void GUIUpdate(int PageCount, int ComponentCount) override;
    void JsonLoad() override;
    void JsonSaving() override;
    

    std::string TextForWebsite = "Default Text";
};

#endif /* TextComponent_hpp */
