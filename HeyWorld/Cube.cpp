//
//  Cube.cpp
//  LightsBox
//
//  Created by Maria Montserrat Lozano on 15/11/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Cube.h"

Cube::Cube()
{

}

void Cube::drawCube()
{
    //toda la caja
    glPushMatrix();
    glRotated(angleBox, 0, 1, 0);
    //parta baja
    glPushMatrix();
    // glColor3f(0.0, 1.0, 0.0);
    // glutSolidCube(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    //parte para abrir
//    glPushMatrix();
// //   glRotated(angleTop, 1, 0, 0);
//    glTranslated(0, 0.6, 0);
//    glScalef(1.0, 0.25, 1.0);
//    glColor3f(0.0, 1.00, 0);
//    glutSolidCube(1);
//    glColor3f(1.0, 1.0, 1.0);
//    glutWireCube(1);
//    glPopMatrix();
    
    glPopMatrix();
}

void Cube::animationBox(int v)
{
    if(v == 0) //abrir tapa
    {
        if(angleTop > 0)
        {
            angleTop--;
            glutTimerFunc(50, animationBox, 0);
            
        }
        else
            angleTop = 0;
    }else if (v == 1) //rotar caja
    {
        if(angleBox < 360)
        {
            angleBox++;
            glutTimerFunc(50, animationBox, 1);
        }
        else
            angleBox = 0;
    }
    glutPostRedisplay();
}

void Cube::openCube()
{
    glutTimerFunc(50, animationBox, 0);
}

void Cube::closeCube()
{
    angleTop = 90;
    glutPostRedisplay();
}

void Cube::rotateCube()
{
     glutTimerFunc(100, animationBox, 1);
}