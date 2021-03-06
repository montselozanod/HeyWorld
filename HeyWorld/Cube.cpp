//
//  Cube.cpp
//  LightsBox
//
//  Created by Maria Montserrat Lozano on 15/11/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Cube.h"
#define SIZE 11.0f

Cube::Cube()
{
    
}

void Cube::drawCube()
{
    
    glPushMatrix();
    glRotated(angleBox, 0, 1, 0);
    
    // Parte de Atras del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-SIZE, -SIZE, -SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-SIZE,  SIZE, -SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( SIZE,  SIZE, -SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( SIZE, -SIZE, -SIZE);
    glEnd();
    
    
    
    // Parte de Abajo del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-SIZE, -SIZE, -SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( SIZE, -SIZE, -SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( SIZE, -SIZE,  SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-SIZE, -SIZE,  SIZE);
    glEnd();
    
    // Parte de lado Derecho del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE_SGIS);
    glBegin(GL_QUADS);
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( SIZE, -SIZE, -SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( SIZE,  SIZE, -SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( SIZE,  SIZE,  SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( SIZE, -SIZE,  SIZE);
    glEnd();
    
    // Lado Izquierdo del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-SIZE, -SIZE, -SIZE);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-SIZE, -SIZE,  SIZE);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-SIZE,  SIZE,  SIZE);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-SIZE,  SIZE, -SIZE);
    glEnd();
    
    //parte para abrir
    glPushMatrix();
    glRotated(angleTop, 1, 0, 0);
    glTranslated(0, 0.6, 0);
    glScalef(1.0, 0.25, 1.0);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-SIZE,  SIZE+30, -SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-SIZE,  SIZE+30,  SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( SIZE,  SIZE+30,  SIZE);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f( SIZE,  SIZE+30, -SIZE);
    glEnd();
    
    
    
    glPopMatrix();
    glPopMatrix();
    
    
    
    
}

void Cube::animationBox(int v)
{
    if(v == 0) //abrir tapa
    {
        if(angleTop > 0)
        {
            angleTop=angleTop-5;
            glutTimerFunc(10, animationBox, 0);
            
        }
        else
            angleTop = 0;
    }else if (v == 1) //rotar caja
    {
        if(angleBox < 180)
        {
            angleBox=angleBox+10;
            glutTimerFunc(10, animationBox, 1);
        }
        else
        {
            angleBox = 0;
            openCube();
        }
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
    glutTimerFunc(50, animationBox, 1);
}