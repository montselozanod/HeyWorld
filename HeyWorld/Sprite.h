//
//  Sprite.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef HeyWorld_Sprite_h
#define HeyWorld_Sprite_h

#include "World.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Sprite
{
    private:
    GLfloat x;
    GLfloat y;
    
    public:
    Country myCountry;
    bool visibility;
    int difficultyLevel;
    virtual void drawSprite();
};

#endif
