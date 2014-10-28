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
#include "Image.h"
#include "MenuOption.h"

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;
GLuint texture = 0;
int currentIndex = 0; //current indes for menus;
bool selectMenuPrincipal[4] = {true, false, false, false};
bool selectMenuDificultad[4] = {true, false, false, false};
Image image;

//Estados
// Escoger Opcion De Juego = 0
// Escoger Dificultad = 1
// Jugar = 3
// FIn = 4

void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    gameState = 0;
    currentIndex = 0;
}

void menuPrincipal()
{
    Menu menu1 = Menu("Instrucciones");
    menu1.drawMenu(400, 100, 0, 300, selectMenuPrincipal[0]);
    Menu menu = Menu("Monumentos");
    menu.drawMenu(400, 100, 0, 100, selectMenuPrincipal[1]);
    Menu menu2 = Menu("Banderas");
    menu2.drawMenu(400, 100, 0, -100, selectMenuPrincipal[2]);
    Menu menu3 = Menu("Personajes");
    menu3.drawMenu(400, 100, 0, -300, selectMenuPrincipal[3]);
}

void menuDificultad()
{
    Menu menu = Menu("Turista");
    menu.drawMenu(400, 100, 0, 100, selectMenuDificultad[0]);
    Menu menu2 = Menu("Agente de Viajes");
    menu2.drawMenu(400, 100, 0, -100, selectMenuDificultad[1]);
    Menu menu3 = Menu("Gurú");
    menu3.drawMenu(400, 100, 0, -300, selectMenuDificultad[2]);
}

void background()
{
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2i(0,0); glTexCoord2i(0,0);
            glTexCoord2i(1, 0); glTexCoord2i(winWidth, 0);
            glTexCoord2i(1,1); glVertex2i(winWidth, winHeight);
            glTexCoord2i(0,1); glVertex2i(0, winHeight);
        glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(gameState == 0)
    {
        texture = image.LoadTexture( "/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/mundo.png", winWidth, winHeight); //load the texture
        glEnable( GL_TEXTURE_2D );
        image.cube(0);
        image.FreeTexture(texture);
        menuPrincipal();
    }else if(gameState == 1)
    {
        menuDificultad();
    }else if(gameState == 3)
    {
    
    }else
    {
    
    }
    
    glutSwapBuffers();
}

void teclasUPandDown(int tecla, int x, int y)
{
    if(gameState == 0)
    {
        switch(tecla)
        {
            case GLUT_KEY_DOWN:
                selectMenuPrincipal[currentIndex] = false;
                if(currentIndex < 3)
                    currentIndex++;
                else
                    currentIndex = 3;
                selectMenuPrincipal[currentIndex] = true;
                glutPostRedisplay();
                break;
            case GLUT_KEY_UP:
                selectMenuPrincipal[currentIndex] = false;
                if(currentIndex > 0)
                currentIndex--;
                else
                    currentIndex = 0;
                selectMenuPrincipal[currentIndex] = true;
                glutPostRedisplay();
                break;
        }
    }else if (gameState == 1)
    {
        switch(tecla)
        {
            case GLUT_KEY_DOWN:
                selectMenuDificultad[currentIndex] = false;
                currentIndex++;
                selectMenuDificultad[currentIndex] = true;
                glutPostRedisplay();
                break;
            case GLUT_KEY_UP:
                selectMenuDificultad[currentIndex] = false;
                    currentIndex--;
                selectMenuDificultad[currentIndex] = true;
                glutPostRedisplay();
                break;

        }
    
    }
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
    glutSpecialFunc(teclasUPandDown);
    //mouse
    glutMainLoop();
    return 0;
}