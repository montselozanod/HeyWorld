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

void Menu::renderBitmapString(float x,float y,float z)
{
    int i;
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.3, 0.3, 0.01);
    
    for(i = 0; i < name[i] != '\0'; i++)
    {
        std::cout<<name[i];
        glutStrokeCharacter(GLUT_STROKE_ROMAN, name[i]);
    }
    glPopMatrix();
}

void Menu::drawMenu(int ancho, int alto, int x, int y, bool selected)
{
    double z = 0.5;
    
    glPushMatrix();
    glTranslatef(x, y, -z/2.0);
    glScalef(ancho, alto, z);
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
        glScalef(ancho, alto, 1);
        glutWireCube(1);
    glPopMatrix();
    
    renderBitmapString(x - ancho / 4.0, y - 12, 0);

}