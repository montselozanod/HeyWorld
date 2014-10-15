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
    std::string imgName;
    
    public:
    Country myCountry;
    bool visibility;
    int difficultyLevel;
    void setImgName(std::string name);
    std::string getImgName();
    virtual void drawSprite();
    GLfloat getPosX();
    GLfloat getPosY();
    void changePosX(GLfloat x);
    void changePosY(GLfloat y);
};

std::string Sprite::getImgName()
{
    return imgName;
}

void Sprite::setImgName(std::string name)
{
    imgName = name;
}

void Sprite::drawSprite()
{

}

GLfloat Sprite::getPosX()
{
    return x;
}

GLfloat Sprite::getPosY()
{
    return y;
}

void Sprite::changePosX(GLfloat posX)
{
    x = posX;
}

void Sprite::changePosY(GLfloat posY)
{
    y = posY;
}
#endif
