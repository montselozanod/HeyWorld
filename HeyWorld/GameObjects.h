//
//  GameObjects.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__GameObjects__
#define __HeyWorld__GameObjects__

#include <iostream>

#pragma mark MONUMENT CLASS
//MONUMENT CLASS
class Monument
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
class Flag
{
    
public:
    void drawSprite();
};

#pragma mark CHARACTER CLASS
//CHARACTER CLASS
class Character
{
private:
    std::string characterName;
    
public:
    void drawSprite();
    void setName(std::string nam);
    std::string getName();
    
};

#endif /* defined(__HeyWorld__GameObjects__) */
