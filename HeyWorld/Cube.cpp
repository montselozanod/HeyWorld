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
    
    glPushMatrix();
    glRotated(angleBox, 0, 1, 0);
    
    // Parte de Atras del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glBindTexture(GL_TEXTURE_2D,texName[7]);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();
    

    
    // Parte de Abajo del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   // glBindTexture(GL_TEXTURE_2D,texName[9]);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glEnd();
    
    // Parte de lado Derecho del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE_SGIS);
    
    //glBindTexture(GL_TEXTURE_2D,texName[10]);
    glBegin(GL_QUADS);
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glEnd();
    
    // Lado Izquierdo del cubo
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    //glBindTexture(GL_TEXTURE_2D,texName[11]);
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();
    


    
//    //toda la caja
//    glPushMatrix();
//    glRotated(angleBox, 0, 1, 0);
//    //parta baja
//    glPushMatrix();
//    // glColor3f(0.0, 1.0, 0.0);
//    // glutSolidCube(1.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glutWireCube(1.0);
//    glPopMatrix();
    
    //parte para abrir
    glPushMatrix();
    glRotated(angleTop, 1, 0, 0);
    glTranslated(0, 0.6, 0);
    glScalef(1.0, 0.25, 1.0);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE_SGIS);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glBindTexture(GL_TEXTURE_2D,texName[8]);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glEnd();
    
    //glPopMatrix();
    
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