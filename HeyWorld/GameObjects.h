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
    std::string imgPathName;
    std::string gameObjectName;
    
public:
    Country myCountry;
    Sprite(/*std::string img,*/ int countryCode)
    {
        myCountry = Country(theWorld.worldCountries[countryCode].name, theWorld.worldCountries[countryCode].countryCode, theWorld.worldCountries[countryCode].capital, theWorld.worldCountries[countryCode].continentCode);
    }

    Sprite(/*std::string img,*/ std::string object, int countryCode)
    {
        gameObjectName = object;
        
        myCountry = Country(theWorld.worldCountries[countryCode].name, theWorld.worldCountries[countryCode].countryCode, theWorld.worldCountries[countryCode].capital, theWorld.worldCountries[countryCode].continentCode);
    }
   
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
    
public:
    Flag(/*std::string img,*/ int countryCode):Sprite(countryCode)
    {
        
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
    Character(/*std::string img,*/ std::string object, int countryCode):Sprite(object, countryCode)
    {
        
    }
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__GameObjects__) */
