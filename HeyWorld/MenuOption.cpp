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

Menu::Menu()
{
    setPosition(0, 0, .5);
    setDimensions(0.4, 0.07, .5);
    selected = false;
}

Menu::Menu(std::string name, double x, double y, double dimX, double dimY, double zPos)
{
    this->name = name;
    setPosition(x, y, .5);
    setDimensions(dimX, dimY, zPos);
    selected = false;
}

void Menu::setDimensions(double w, double h, double v)
{
    width = w;
    height = h;
    volume = v;
}

void Menu::setPosition(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Menu::setSelected(bool s)
{
    selected = s;
}

bool Menu::getSelected()
{
    return selected;
}

void Menu::draw3dString (int type, float xPos, float yPos, float zPos)
{
    int i;
    
    glPushMatrix();
    glTranslatef(xPos, yPos, zPos);
    if(type == 1)
    {
        glScaled(0.0003, 0.0003, 0.2);
    }else
    {
        glScaled(0.0004, 0.0004, 0.05);
    }
    
    glColor3f(0, 0, 0);
 
    for (i = 0; i < name[i] != '\0'; i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, name[i]);
    
    glPopMatrix();
}


void Menu::drawMenu(int type)
{//.9999;
    
    
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glScalef(width, height, volume);
    //glColor3f(0, 0, 0);
    glutWireCube(1);
    if(selected)
        glColor3f(0, 1, 1);
    else
        glColor3f(0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
 
    
    if (type == 1) // menu horizontal
    {
        draw3dString ( type, x-volume, y-(height/2.0), 0.05);
    }
    else{
        draw3dString ( type, x - 0.15, y - 0.02, 0.5); //nos traemos las letras hacia adelante de 0 a .5
    }
}


/*
 double z = 0.5;
     //renderBitmapString(name, x - width / 4.0, y - 12, 0);
 glPushMatrix();
 glTranslatef(x, y, -z/2.0);
 glScalef(width, height, z);
 glColor3f(0, 0, 0);
 glutWireCube(1);
 
 if(selected)
 glColor3f(0, 1, 1);
 else
 glColor3f(0, 1, 0);
 glutSolidCube(1);
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(x, y, z);
 glScalef(width, height, 1);
 glutWireCube(1);
 glPopMatrix();

*/