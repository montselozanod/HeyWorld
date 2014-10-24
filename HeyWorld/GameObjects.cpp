//
//  GameObjects.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "GameObjects.h"

#pragma mark Sprite

std::string Sprite::getImgName()
{
    return imgPathName;
}

void Sprite::setImgName(std::string name)
{
    imgPathName = name;
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

#pragma mark MONUMENT
void Monument::setName(std::string nam)
{
    monumentName = nam;
}

std::string Monument::getName()
{
    return monumentName;
}

//override
void Monument::drawSprite()
{
    
}

//FLAG
#pragma mark FLAG

////override
//void Flag::drawSprite()
//{
//    
//}


#pragma mark Character
//Character

//override
void Character::drawSprite()
{
    
}
