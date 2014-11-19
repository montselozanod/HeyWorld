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
    //Country countries[200]; faltan poner todos los paises
    World theWorld;
    GLfloat x;
    GLfloat y;
    char* imgPathName;
    std::string gameObjectName;

    
public:
    Sprite(char* img, int code)
    {
        countryCode = code;
        imgPathName = img;
        visibility = false;
    }
    
    Sprite(std::string img, int code)
    {
        countryCode = code;
        gameObjectName= img;
        visibility = false;
    }

    Sprite(char* img, std::string object, int code)
    {
        imgPathName = img;
        gameObjectName = object;
        countryCode = code;
        visibility = false;
    }
    
    int countryCode;
    bool visibility;
    int difficultyLevel;
    void setImgName(char* name);
    char* getImgName();
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
    Monument(/*std::string img,*/ std::string object, int countryCode):Sprite(object, countryCode)
    {
    
    }
    
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#pragma mark FLAG CLASS
//FLAG CLASS
class Flag: public Sprite
{
    GLfloat	xrot;
    GLfloat	yrot;
    GLfloat	zrot;
    GLfloat hold;
    float points [45][45][3];
    int wiggle;
    bool dirRight;
public:
    Flag(char* img, int countryCode):Sprite(img,countryCode)
    {
        wiggle = 0;
        yrot = 0;
        dirRight = true;
    }
    void drawSprite();
};

#pragma mark CHARACTER CLASS
//CHARACTER CLASS
class Character: public Sprite
{
    
private:
    std::string characterName;
    
public:
    Character(char *img, std::string object, int countryCode):Sprite(img, object, countryCode)
    {
        
    }
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__GameObjects__) */
