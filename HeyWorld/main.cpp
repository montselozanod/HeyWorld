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

#define CONTINENTS 3

GLsizei winWidth = 1200, winHeight =600; // Tamaño inicial de la ventana
int windowID;
int subWindowMap;
int subWindowSprite;
int gameState = 0;
GLuint texture = 0;


static GLuint texName[36];

Game game;

bool showInstructions;

//MENUS
std::vector<Menu> menuOptions;
std::vector<Menu> menuDif;
std::vector<Menu> menuContinents;
int currentIndex = 0; //current index for menus;

int angulo=45;
//int z=1;
//int x=1;
//int y=1;

/*Variables para dibujar los pines*/
bool arrPines[2]={false,false};
float radiusPin = .03;
float posX = 0.0;
float posY = 0.0;
int numContinente = 0; //1.America 2.Asia 3.Europa 4.Africa.. Esto es para saber qué vector agarramos
float contPaises = 10; //Variable para utilizar.. tiene la cantidad de paises en base al país seleccionado
World *continente = new World();
/**/

// GAMESTATE
// Menu Principal = 0
// Menu Dificultad = 1
    // Juego
    // Sale opcion con menu mapa = 2
    // Mapa con pines = 3
    // Pasaste de nivel
// FIn = 5
void displayMain();
void initWindows();
void despliegaMapa(int i);
void drawMenuContinente();

void rectVerdeRojo()
{
    
    //movemos camara
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    gluLookAt(0, 0, 3, 0, 0, 0, 0, .1, 0);

    glPushMatrix();
    glColor3f(0,0,0);
    //glColor3f(0,1,0);//Verde
    //glColor3f(1,0,0);//rojo
    glPointSize(1);
    glBegin(GL_QUADS);
    glVertex2f(-1.1,-1.2);
    glVertex2f(1.1,-1.2);
    glVertex2f(1.1,1);
    glVertex2f(-1.1,1);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
}

void fondoAzul()
{
    
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    gluLookAt(0, 0, 3, 0, 0, 0, 0, .1, 0);//movemos camara para que se vea el mapa
    
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_TEXTURE); //Dejar activa la Textura
    glBindTexture(GL_TEXTURE_2D, texName[10]); //Escogemos la textura
    
    glPushMatrix();
    glRotated(angulo, 0, 1, 0); //se acumula en la matriz de TEXTURE
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
    glVertex3f(-4, -2.5, 0);
    glTexCoord2f(4.0f, 0.0f);
    glVertex3f(4, -2.5, 0);
    glTexCoord2f(4.0f, 1.0f);
    glVertex3f(4, 2.5, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4, 2.5, 0);
    
//    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
//    glVertex3f(-1, -1, 0);
//    glTexCoord2f(4.0f, 0.0f);
//    glVertex3f(1, -1, 0);
//    glTexCoord2f(4.0f, 1.0f);
//    glVertex3f(1, 1, 0);
//    glTexCoord2f(0.0f, 1.0f);
//    glVertex3f(-1, 1, 0);
    glEnd();
    
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();//camara
    
}

void renderSubWindow()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    despliegaMapa(currentIndex);
    rectVerdeRojo();
    drawMenuContinente();
   
    glutSwapBuffers();
    glutSetWindow(subWindowSprite);
    glutPostRedisplay();
}


void renderSubWindowSprite()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //pintar textura de agua
    //fondoAzul();

    game.draw(); //Dibujar caja de objetos
    glutSwapBuffers();
    
    glutSetWindow(subWindowMap);
    glutPostRedisplay();
}

void gameManagement()
{
    subWindowMap = glutCreateSubWindow(windowID, 0, 0, 600, winHeight);
    glutDisplayFunc(renderSubWindow);
    initWindows();
    glutSetWindow(subWindowMap);
    glutPostRedisplay();
    
    glLoadIdentity();
    
    subWindowSprite = glutCreateSubWindow(windowID, 600, 0, 600, winHeight);
    glutDisplayFunc(renderSubWindowSprite);
    initWindows();
    glutSetWindow(subWindowSprite);
    glutPostRedisplay();
    


    
    //    glutCreateSubWindow(windowID, 600, 0, 600, winHeight);
    //    glutDisplayFunc(renderSubWindow);
    //    initWindows();
    //game.playGame();
}


void checkDisplayOption()
{
    if(gameState == 0)
    {
        switch(currentIndex)
        {
            case 0:
                showInstructions = true;
                break;
            case 1:
                gameState = 1;
                menuOptions[currentIndex].setSelected(false);
                currentIndex = 0;
                menuDif[0].setSelected(true);
                break;
            case 2:
                exit(0);
                break;
        }
    }else if(gameState == 1)
    {
        switch(currentIndex)
        {
            case 0: //turista
            case 1: //agente
            case 2: //guru
                game = Game(currentIndex);
                menuDif[currentIndex].setSelected(false);
                currentIndex = 0;
                menuContinents[0].setSelected(true);
                gameState = 2;
                gameManagement();
                game.startGame();
                glutPostRedisplay();
                break;
            case 3: //back
                gameState = 0;
                menuDif[currentIndex].setSelected(false);
                currentIndex = 0;
                menuOptions[0].setSelected(true);
                break;
        }
        //game.setDifficultyGame(currentIndex);
        //game.startGame();
        
    }else if(gameState == 2)
    {
        
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
   
    //principal
    menuOptions.push_back(Menu("Instrucciones", 0.0, 0.1 ,0.4, 0.07, 0.9999));
    menuOptions.push_back(Menu("Jugar", 0.0, 0.0 ,0.4, 0.07, 0.9999));
    menuOptions.push_back(Menu("Salir", 0.0, -0.1 ,0.4, 0.07, 0.9999));
    menuOptions[0].setSelected(true);
    
    //dificultad
    menuDif.push_back(Menu("Turista", 0.0, 0.2 ,0.4, 0.07, 0.9999));
    menuDif.push_back(Menu("Agente", 0.0, 0.1 ,0.4, 0.07, 0.9999));
    menuDif.push_back(Menu("Guru", 0.0, 0.0 ,0.4, 0.07, 0.9999));
    menuDif.push_back(Menu("Regresar", 0.0, -0.1 ,0.4, 0.07, 0.9999));
    
    //continentes
    menuContinents.push_back(Menu("AFRICA", -0.45, 0.52 ,0.23, 0.07, 0.07));
    menuContinents.push_back(Menu("AMERICA", -0.15, 0.52,0.23, 0.07, 0.07));
    menuContinents.push_back(Menu("ASIA", 0.15, 0.52 ,0.23, 0.07, 0.07));
    menuContinents.push_back(Menu("EUROPA", 0.45, 0.52,0.23, 0.07, 0.07));
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
    glGenTextures(11, texName); //Make room for our texture
    Image* image;
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/estrellas.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/map.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/Mapamundi.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/pin2.bmp");loadTexture(image,i++); //ARREGLAR
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/america.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/asia.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/europa.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/africa.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/blocks.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/madera.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/water.bmp");loadTexture(image,i++);

//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/estrellas.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/map.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/Mapamundi.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/pin2.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/america.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/asia.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/europa.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/africa.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/blocks.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/madera.bmp");loadTexture(image,i++);
//    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/water.bmp");loadTexture(image,i++);
    
    delete image;
}

void drawMenuPrincipal()
{
    for (int i = 0; i < menuOptions.size(); i++)
    {
        menuOptions[i].drawMenu(0);
    }
}
void drawMenuDificultad()
{
    for(int i = 0; i < menuDif.size(); i++)
    {
        menuDif[i].drawMenu(0);
    }

}

void drawMenuContinente()
{
    for(int i = 0; i < menuContinents.size(); i++)
    {
        menuContinents[i].drawMenu(1);
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
    glVertex3f(-2, -1, 0);
    
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2, -1, 0);
    
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2, 1, 0);
    
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, 1, 0);
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

void despliegaPines()
{
    
    for (int i = 0; i< contPaises ; i++)
    {
        glPushMatrix();
        glEnable(GL_BLEND); // Activamos la transparencia
        glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR); //funcion de blending //GL_ONE_MINUS_SRC_ALPHA
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texName[3]);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glBindTexture(GL_TEXTURE_2D, texName[3]);
        glPushMatrix();
        
        switch (currentIndex) {
            case 1: //America
                //posiciones de los pines
                posX =  continente -> _america[i].posX;
                posY = continente -> _america[i].posY;
                break;
            case 2: //Asia
                //posiciones de los pines
               // posX =  continente -> _asia[i].posX;
               // posY = continente -> _asia[i].posY;
                break;
            case 3: //Europa
                // posX =  continente -> _europa[i].posX;
                // posY = continente -> _europa[i].posY;
                break;
            case 0: //Africa
                 posX =  continente -> _africa[i].posX;
                 posY = continente -> _africa[i].posY;
                break;
            default:
                break;
        }
        
        
        glTranslatef(posX, posY, 0);
        //glColor3f(0.0f, 0.0f, 0.0f);
        glColor4f(1.0, 1.0, 1.0, 0.1); //color y alpha del cubo
        glutSolidSphere(radiusPin, 20, 20);
        
        glPopMatrix();
        
        glPopMatrix();
        glDisable(GL_BLEND); //para desactivarlo.
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    }
    
    
    /*glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
     glPointSize(1.0);
     glBegin(GL_POINTS);
     //glColor3b(1, 1, 1);
     glVertex2d(-0.22, 0.31);
     glEnd();*/
    
}

void despliegaMapa(int mapa)
{
    /*Fondo azul con negro*/
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    gluLookAt(0, 0, 3, 0, 0, 0, 0, .1, 0);//movemos camara para que se vea el mapa
    glEnable(GL_TEXTURE_2D);
    glTranslated(0.0, 0.0, -2.0);
    glMatrixMode(GL_TEXTURE);//Activar matriz de textura
    glBindTexture(GL_TEXTURE_2D, texName[10]); //Seleccion de textura
    //glLoadIdentity(); //Limpia matriz de Texturas
    glPushMatrix();
    glRotated(angulo, 0, 1, 0); //se acumula en la matriz de TEXTURE
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
    glVertex3f(-4, -2.5, 0);
    glTexCoord2f(4.0f, 0.0f);
    glVertex3f(4, -2.5, 0);
    glTexCoord2f(4.0f, 1.0f);
    glVertex3f(4, 2.5, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4, 2.5, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix(); //pop de camara
    glDisable(GL_TEXTURE_2D);
    
   
    //MAPA
    //movemos camara
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    gluLookAt(0, 0, 3.0, 0, 0, 0, 0, 1, 0);
    
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    
    //Definir textura
    switch (mapa) {
        case 1:
            glBindTexture(GL_TEXTURE_2D, texName[4]); //Textura
            //numContinente = 1;

            break;
        case 2:
            glBindTexture(GL_TEXTURE_2D, texName[5]);
            //numContinente = 2;

            break;
        case 3:
            glBindTexture(GL_TEXTURE_2D, texName[6]);
           // numContinente = 3;

            break;
        case 0:
            glBindTexture(GL_TEXTURE_2D, texName[7]);
            //numContinente = 4;
            break;
            
        default:
            break;
    }
    
    
    glTranslated(0.0, -0.11, 0.0);
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
    
    glPopMatrix();
    
    
    despliegaPines();
    
    
}

int verificaPin(float clicx, float clicy)
{
    int codigo= 0;
    //contPaises cuantos paises hay en el continente
    for (int i = 0; i <  contPaises ; i++)
    {
        
        switch (currentIndex) {
            case 1: //America
                if (clicx >= continente -> _america[i].rangoX1 && clicx <= continente -> _america[i].rangoX2 && clicy >= continente -> _america[i].rangoY1 && clicy <= continente -> _america[i].rangoY2
                    ) {
                    codigo = continente ->_america[i].countryCode;
                }
                break;
            case 2: //Asia
               /* if (clicx >= continente -> _asia[i].rangoX1 && clicx <= continente -> _asia[i].rangoX2 && clicy >= continente -> _asia[i].rangoY1 && clicy <= continente -> _asia[i].rangoY2  ) {
                    codigo = continente ->_asia[i].countryCode;
                }
                break;*/
            case 3: //Europa
                
                break;
            case 0: //Africa
                if (clicx >= continente -> _africa[i].rangoX1 && clicx <= continente -> _africa[i].rangoX2 && clicy >= continente -> _africa[i].rangoY1 && clicy <= continente -> _africa[i].rangoY2  ) {
                    codigo = continente ->_africa[i].countryCode;
                }
                break;
            default:
                break;
        }
        
    }
    return codigo ;
    
}

void callback(int x, int y)
{
    //mapear coordenadas de glut a openGL
    float openGL_X = (x - 500.00)/500.00;
    float openGL_Y = (300.00 - y) / 300.00;
    int code = 0;
    std::cout << "En donde di clic: " << openGL_X << ", " << openGL_Y <<"\n";
    
    code = verificaPin(openGL_X,openGL_Y);
    std::cout << "El codigo es: " << code << "\n";
    //Aqui se manda llamar la funcion de monste que diga si si esta correcto o no procedimiento(code)
}

void mouse(int button, int state, int x, int y){
    
    if(gameState == 2)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            if(state == GLUT_DOWN)
            {
                callback(x,y);
                glutPostRedisplay();
            }
        }
    }
    
}


void displayMain()
{
    glutSetWindow(windowID);
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
    }else if(gameState == 2)
    {
        //sale sprite y menu continentes
//        int mapa = 1; //1 america, 2 asia, 3 europa, 4 africa
//        despliegaMapa(currentIndex);
//        drawMenuContinente();
//        glutCreateSubWindow (win, 0, 0, 100, 100);
//        glutDisplayFunc(displayWindow2);
    
    }else if(gameState == 3)
    {
    
    }else if(gameState == 4)
    {
    }else if(gameState == 5)
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
                if(currentIndex < 2)
                    currentIndex++;
                else
                    currentIndex = 2;
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
                if(currentIndex < 3)
                    currentIndex++;
                else
                    currentIndex = 3;
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
    
    }else if(gameState == 2)
    {
        switch(tecla){
            case GLUT_KEY_LEFT:
                menuContinents[currentIndex].setSelected(false);
                if(currentIndex > 0)
                    currentIndex--;
                else
                    currentIndex = 0;
                menuContinents[currentIndex].setSelected(true);
                glutPostRedisplay();
                break;
        
            case GLUT_KEY_RIGHT:
                menuContinents[currentIndex].setSelected(false);
                if(currentIndex < CONTINENTS)
                    currentIndex++;
                else
                    currentIndex = CONTINENTS;
                menuContinents[currentIndex].setSelected(true);
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

void initWindows()
{
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(mouse);
    initRendering();
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(teclasUPandDown);

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(100, 400); // 100, 100
    //MAIN WINDOW
    windowID = glutCreateWindow("Hey World!");
    //DISPLAY CALLBACK
    glutDisplayFunc(displayMain);
    
    init();
    initWindows(); //KEYBOARD AND MOUSE CALLBACKS

    //cursor
     glutSetCursor(GLUT_CURSOR_INFO);
    
    //mouse
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
