//
//  Monument.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Monument.h"

void Monument::setName(std::string nam)
{
    name = nam;
}

std::string Monument::getName()
{
    return name;
}

//override
void Monument::drawSprite()
{

}