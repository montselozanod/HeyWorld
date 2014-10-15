//
//  Flag.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__Flag__
#define __HeyWorld__Flag__

#include <iostream>
#include "Sprite.h"

class Flag: public Sprite
{
    private:
    std::string imgName;
    public:
    void drawSprite();
    GLfloat getPosX();
    GLfloat getPosY();
    void changePosX();
    void changePosY();

};

#endif /* defined(__HeyWorld__Flag__) */
