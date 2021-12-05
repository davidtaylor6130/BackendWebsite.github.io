//
//  YoutubeEmbedComponent.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef YoutubeEmbedComponent_hpp
#define YoutubeEmbedComponent_hpp

#include <stdio.h>
#include "BaseComponent.hpp"

class YoutubeEmbedComponenet : public BaseComponent {
public:
    YoutubeEmbedComponenet();
    
    void GUIUpdate(int PageCount, int ComponentCount) override;
    void JsonLoad(nlohmann::json* json) override;
    void JsonSaving(nlohmann::json* json) override;
    
    std::string YoutubeLink = "Default Text";
};

#endif /* YoutubeEmbedComponent_hpp */
