//
//  MenuOption.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 24/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "MenuOption.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Menu::Menu(std::string nam)
{
    name = nam;
}

void Menu::setName(std::string nam)
{
    name = nam;
}

std::string Menu::getName()
{
    return name;
}


void Menu::draw3dString (float x, float y, float z)
{
    int i;
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glScaled(0.0004, 0.0004, 0.05);
    glColor3f(1, 1, 1);
    
    for (i = 0; i < name[i] != '\0'; i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, name[i]);
    
    glPopMatrix();
}

void Menu::drawMenu(float ancho, float alto, float x, float y, bool selected)
{
    
    double z = .9999;
    
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glScalef(ancho, alto, z);
    //glColor3f(0, 0, 0);
    glutWireCube(1);
    if(selected)
        glColor3f(0, 1, 1);
    else
        glColor3f(0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    
    
    draw3dString ( - 0.15, y - 0.02, 0.5 ); //nos traemos las letras hacia adelante de 0 a .5
}