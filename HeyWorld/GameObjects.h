//
//  GameObjects.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__GameObjects__
#define __HeyWorld__GameObjects__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "World.h"

#pragma mark SPRITE BASE CLASS
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

#pragma mark MONUMENT CLASS
//MONUMENT CLASS
class Monument: public Sprite
{
private:
    std::string monumentName;
    
    
public:
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#pragma mark FLAG CLASS
//FLAG CLASS
class Flag: public Sprite
{
    
public:
    void drawSprite();
};

#pragma mark CHARACTER CLASS
//CHARACTER CLASS
class Character: public Sprite
{
private:
    std::string characterName;
    
public:
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__GameObjects__) */
