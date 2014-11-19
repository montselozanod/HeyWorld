//
//  User.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "User.h"

void User::initializePassport()
{
    userPassport.monumentsCompleted = false;
    userPassport.flagsCompleted = false;
    userPassport.charactersCompleted = false;
}

void User::initializeVisas()
{
    for (int i = 0; i < 3; i++)
    {
        //no estoy segura de coords.. seguro cambiaran con testing en la ventana.
        userVisas[i].x = 200 + i*15;
        userVisas[i].y = 200 + i*15;
        userVisas[i].alive = true;
    }
}

User::User()
{
    playerSprite = 0;
    initializePassport();
    initializeVisas();
}

User::User(int sprite)
{
    playerSprite = sprite;
    initializePassport();
    initializeVisas();
}

void User::addPassportStamp(int stampId)
{
    switch(stampId)
    {
        case 0:
            userPassport.monumentsCompleted = true;
            break;
        case 1:
            userPassport.flagsCompleted = true;
            break;
        case 2:
            userPassport.charactersCompleted = true;
            break;
    }
}

void User::deleteVisa()
{
    for (int i = 2; i >= 0; i--)
    {
        if(userVisas[i].alive)
        {
            userVisas[i].alive = false;
            return;
        }else
        {
            std::cout<<"hola"<<std::endl;
        }
    }
}

bool User::isPlayerAlive()
{
    if(userVisas[0].alive)
    {
        return true;
    }else
    {
        return false;
    }
}

void User::resetUserSettings()
{
    initializePassport();
    initializeVisas();
}



