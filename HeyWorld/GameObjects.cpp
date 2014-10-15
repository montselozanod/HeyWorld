//
//  GameObjects.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "GameObjects.h"

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

//override
void Flag::drawSprite()
{
    
}


#pragma mark Character
//Character

//override
void Character::drawSprite()
{
    
}
