//
//  LinkComponenet.hpp
//  example_apple_metal
//
//  Created by David Taylor on 03/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//

#ifndef LinkComponenet_hpp
#define LinkComponenet_hpp

#include <stdio.h>
#include "BaseComponent.hpp"

class LinkComponent : public BaseComponent  {
public:
    LinkComponent();
    
    void GUIUpdate(int PageCount, int ComponentCount) override;
    void JsonLoad() override;
    void JsonSaving() override;
    
    std::string LinkForWebsite = "www.google.com";
};

#endif /* LinkComponenet_hpp */
