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
#include <string>
#include "BaseComponent.hpp"

class YoutubeEmbedComponenet : public BaseComponent {
public:
    YoutubeEmbedComponenet();
    
    void GUIUpdate(int PageCount, int ComponentCount) override;
    void JsonLoad() override;
    void JsonSaving() override;
    
    std::string YoutubeLink = "YOUTUBELINK HERE";
};

#endif /* YoutubeEmbedComponent_hpp */
