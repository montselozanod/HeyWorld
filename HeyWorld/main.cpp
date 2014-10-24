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
#include "MenuOption.h"

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;


//Estados
// Escoger Opcion De Juego = 0
// Escoger Dificultad = 1
// Jugar = 3
// FIn = 4


void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    gameState = 0;
}

void dificultad()
{

}

void menuPrincipal()
{
    Menu menu = Menu("Monumentos");
    menu.drawMenu(400, 100, 0, 100);
    Menu menu2 = Menu("Banderas");
    menu2.drawMenu(400, 100, 0, -100);
    Menu menu3 = Menu("Personajes");
    menu2.drawMenu(400, 100, 0, -300);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(gameState == 0)
    {
        menuPrincipal();
    }
    
    glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
    glViewport (0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //limpiar matriz de proyeccion
    glFrustum(-winWidth, winWidth, -winHeight, winHeight, 1,4);
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(200, 400); // 100, 100
    glutCreateWindow("Hey World!");
    init();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    //mouse
    glutMainLoop();
    return 0;
}