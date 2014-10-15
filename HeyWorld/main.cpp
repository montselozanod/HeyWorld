//
//  main.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 12/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;


void init()
{

}

void display()
{

}

void ChangeSize(GLsizei w, GLsizei h)
{
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(200, 400); // 100, 100
    glutCreateWindow("BlackJack");
    init();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    //mouse
    glutMainLoop();
    return 0;
}