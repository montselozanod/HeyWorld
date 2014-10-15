//
//  Character.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__Character__
#define __HeyWorld__Character__

#include <iostream>
#include "Sprite.h"

class Character: public Sprite
{
    private:
    std::string name;
    
    public:
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__Character__) */
