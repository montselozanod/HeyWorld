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
#include <vector>
#include "Imageloader.h"
#include "MenuOption.h"

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;
GLuint texture = 0;
static GLuint texName[36];

//MENUS
Menu menu;
vector<Menu> menuOptions;
int currentIndex = 0; //current index for menus;
bool selectMenuPrincipal[4] = {true, false, false, false};
bool selectMenuDificultad[4] = {true, false, false, false};


//Estados
// Escoger Opcion De Juego = 0
// Escoger Dificultad = 1
// Jugar = 3
// FIn = 4

//Makes the image into a texture, and returns the id of the texture
void loadTexture(Image* image,int k)
{
    
    glBindTexture(GL_TEXTURE_2D, texName[k]); //Tell OpenGL which texture to edit
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                 0,                            //0 for now
                 GL_RGB,                       //Format OpenGL uses for image
                 image->width, image->height,  //Width and height
                 0,                            //The border of the image
                 GL_RGB, //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                 //as unsigned numbers
                 image->pixels);               //The actual pixel data
    
}

void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    gameState = 0;
    currentIndex = 0;
}

void initRendering()
{
    GLuint i=0;
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    
    GLfloat directedLight[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};

    glEnable(GL_DEPTH_TEST);

    
    glEnable(GL_TEXTURE_2D);
    
    glClearColor(1.0,1.0,1.0,1.0);
    
    // glEnable(GL_COLOR_MATERIAL);
    glGenTextures(1, texName); //Make room for our texture
    Image* image;
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/map.bmp");loadTexture(image,i++);
     delete image;
}

void initMenuPrincipal()
{
    menuOptions.push_back(Menu("Instrucciones", 0, 300));
    menuOptions.push_back(Menu("Monumentos", 0, 100));
    menuOptions.push_back(Menu("Banderas", 0, -100));
    menuOptions.push_back(Menu("Personajes", 0, -300));
}

void initMenuDificultad()
{
    menuOptions.push_back(Menu("Turista", 0, 300));
    menuOptions.push_back(Menu("Agente de Viajes", 0, 100));
    menuOptions.push_back(Menu("Gurú", 0, -100));
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(gameState == 0)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texName[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); //se pega la textura con
        glVertex3f(-winWidth, -winHeight, 0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(winWidth, -winHeight, 0);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(winWidth, winHeight, 0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-winWidth, winHeight, 0);
        glEnd();
        
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
    initRendering();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutSpecialFunc(teclasUPandDown);
    //mouse
    glutMainLoop();
    return 0;
}