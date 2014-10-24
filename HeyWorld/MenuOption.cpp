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

void Menu::drawMenu(int ancho, int alto, int x, int y)
{
    glColor3f(0, 1, 0);
    glPushMatrix();
    glTranslatef(x, y, 0.5);
    glScalef(ancho, alto, 1.3);
    glutSolidCube(1);
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
}