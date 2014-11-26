//
//  User.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__User__
#define __HeyWorld__User__

#include <iostream>

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct Passport
{
    bool monumentsCompleted; // id = 0
    bool flagsCompleted; // id = 1
    bool charactersCompleted; // id = 2
};

struct Visa
{
    GLfloat x;
    GLfloat y;
    bool alive;
};

class User
{
    private:
    Passport userPassport;
    Visa userVisas[3];
    void initializePassport();
    void initializeVisas();
    
    public:
    int playerSprite; //boy = 0, girl = 1
    int numberPoints;
    User();
    User(int sprite);
    int howManyLives();
    void addPassportStamp(int stampId);
    void deleteVisa();
    bool isPlayerAlive();
    void resetUserSettings();
};

#endif /* defined(__HeyWorld__User__) */
