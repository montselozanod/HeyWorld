//
//  Monument.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__Monument__
#define __HeyWorld__Monument__

#include <iostream>
#include "Sprite.h"

class Monument: public Sprite
{
    private:
    std::string name;
    
    public:
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__Monument__) */
