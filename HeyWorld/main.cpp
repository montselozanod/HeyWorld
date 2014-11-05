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
#include "Game.h"
#include "Imageloader.h"
#include "MenuOption.h"

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;
GLuint texture = 0;

static GLuint texName[36];

Game game;

bool showInstructions;

//MENUS
vector<Menu> menuOptions;
vector<Menu> menuDif;
int currentIndex = 0; //current index for menus;

int angulo=45;
int z=1;
int x=1;
int y=1;


//Estados
// Escoger Opcion De Juego = 0
// Escoger Dificultad = 1
// Jugar = 3
// FIn = 4

void checkDisplayOption()
{
    if(gameState == 0)
    {
        if(currentIndex != 0) //if not click instructions
        {
            game.setTypeGame(currentIndex-1);
            currentIndex = 0;
            menuDif[0].setSelected(true);
            gameState ++;
        }else
        {
            //show instructions
            showInstructions = true;
        }
    }else if(gameState == 1)
    {
        game.setDifficultyGame(currentIndex);
        
    }
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    
    switch (theKey)
    {
        case 27: //esc
            exit(0);
            break;
        case 13: //enter
            checkDisplayOption();

        default:
        break;
    }
}


void timer(int value)
{
    angulo = (angulo +8) % 360;
    
    glutPostRedisplay();
    glutTimerFunc(100,timer,0);
}

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

void initMenus()
{
    
    menuOptions.push_back(Menu("Instrucciones", 0.0, 0.2));
    menuOptions.push_back(Menu("Monumentos", 0.0, 0.1));
    menuOptions.push_back(Menu("Banderas", 0.0, 0.0));
    menuOptions.push_back(Menu("Personajes", 0.0, -0.1));
    menuOptions[0].setSelected(true);
    menuDif.push_back(Menu("Turista", 0.0, 0.2));
    menuDif.push_back(Menu("Agente de Viajes", 0.0, 0.1));
    menuDif.push_back(Menu("Guru", 0.0, 0.0));
}

void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    initMenus();
    gameState = 0;
    currentIndex = 0;
    showInstructions = false;
}

void initRendering()
{
    GLuint i=0;
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    
  //  GLfloat directedLight[] = {0.9f, 0.9f, 0.9f, 1.0f};
  //  GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
//    glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);
    glEnable(GL_DEPTH_TEST);

    
    //glEnable(GL_TEXTURE_2D);
    
    //glClearColor(1.0,1.0,1.0,1.0);
    
    // glEnable(GL_COLOR_MATERIAL);
    glGenTextures(3, texName); //Make room for our texture
    Image* image;
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/estrellas.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/map.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/Mapamundi.bmp");loadTexture(image,i++);
     delete image;
}

void drawMenuPrincipal()
{
    for (int i = 0; i < menuOptions.size(); i++)
    {
        menuOptions[i].drawMenu();
    }
}
void drawMenuDificultad()
{
    for(int i = 0; i < menuDif.size(); i++)
    {
        menuDif[i].drawMenu();
    }

}

void fondoPrincipal()
{
    /*Fondo de estrellas*/
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
    glVertex3f(-1, -1, 0);
    
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1, -1, 0);
    
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1, 1, 0);
    
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1, 1, 0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    /*Tierra rodando*/
    glPushMatrix();
    glTranslatef(0, -.25, -.25);
    glRotated(angulo, 0, 1, 0);
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, texName[1]);
    
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    
    glBindTexture(GL_TEXTURE_2D, texName[1]);
    
    glPushMatrix();
    glTranslatef(.25, .25, 0);
    glutSolidSphere(.5, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
}

void display()
{
    GLUquadricObj *qobj;
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); //resetaear. Esto es para que no se guarden los otros colores activados
    
    if(gameState == 0)
    {
        fondoPrincipal();
        /*Menu principal*/
        drawMenuPrincipal();
        
    }else if(gameState == 1)
    {
        fondoPrincipal();
        drawMenuDificultad();
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
                menuOptions[currentIndex].setSelected(false);
                if(currentIndex < 3)
                    currentIndex++;
                else
                    currentIndex = 3;
                menuOptions[currentIndex].setSelected(true);
                glutPostRedisplay();
                break;
            case GLUT_KEY_UP:
                menuOptions[currentIndex].setSelected(false);
                if(currentIndex > 0)
                currentIndex--;
                else
                    currentIndex = 0;
                menuOptions[currentIndex].setSelected(true);
                glutPostRedisplay();
                break;
        }
    }else if (gameState == 1)
    {
        switch(tecla)
        {
            case GLUT_KEY_DOWN:
                menuDif[currentIndex].setSelected(false);
                if(currentIndex < 2)
                    currentIndex++;
                else
                    currentIndex = 2;
                menuDif[currentIndex].setSelected(true);
                glutPostRedisplay();
                break;
            case GLUT_KEY_UP:
                menuDif[currentIndex].setSelected(false);
                if(currentIndex > 0)
                    currentIndex--;
                else
                    currentIndex = 0;
                menuDif[currentIndex].setSelected(true);
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
    //glFrustum(-winWidth, winWidth, -winHeight, winHeight, 1,200);
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0); //180
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    //gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    gluLookAt(0, 0, 1.5, 0, 0, 0, 0, 1, 0); //10 alejamos la camara, 6 acercamos la camara
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(200, 400); // 100, 100
    glutCreateWindow("Hey World!");
    init();
    glutKeyboardFunc(myKeyboard);
    initRendering();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutSpecialFunc(teclasUPandDown);
    //mouse
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}