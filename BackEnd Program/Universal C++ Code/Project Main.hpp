//
//  Project Main.hpp
//  example_apple_metal
//
//  Created by David Taylor on 02/12/2021.
//  Copyright © 2021 Warren Moore. All rights reserved.
//
#ifndef UniversalCPPCode_H
#define UniversalCPPCode_H

#include "Portolfio.hpp"

class UniversalCPPCode {
public:
    UniversalCPPCode();
    ~UniversalCPPCode();
    
    void Update();
    
    Portfolio* portfolio;
};

#endif /* Project_Main_hpp */
