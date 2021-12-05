//
//  ImageComponent.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef ImageComponent_hpp
#define ImageComponent_hpp

#include <stdio.h>
#include "BaseComponent.hpp"

class ImageComponent : public BaseComponent {
public:
    ImageComponent ();
    
    void GUIUpdate(int PageCount, int ComponentCount) override;
    void JsonLoad(nlohmann::json* json) override;
    void JsonSaving(nlohmann::json* json) override;
    
    std::string ImageDirectory = "Put Image Directory Here";
};

#endif /* ImageComponent_hpp */
