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
vector<Menu> menuContinents;
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
float contPaises = 0; //Variable para utilizar.. tiene la cantidad de paises en base al país seleccionado
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
                game = Game(currentIndex);
                break;
            case 1: //agente
                game = Game(currentIndex);
                break;
            case 2: //guru
                game = Game(currentIndex);
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
    menuOptions.push_back(Menu("Instrucciones", 0.0, 0.1));
    menuOptions.push_back(Menu("Jugar", 0.0, 0.0));
    menuOptions.push_back(Menu("Salir", 0.0, -0.1));
    menuOptions[0].setSelected(true);
    
    //dificultad
    menuDif.push_back(Menu("Turista", 0.0, 0.2));
    menuDif.push_back(Menu("Agente", 0.0, 0.1));
    menuDif.push_back(Menu("Guru", 0.0, 0.0));
    menuDif.push_back(Menu("Regresar", 0.0, -0.1));
    
    //continentes
    menuContinents.push_back(Menu("AMERICA", 0.0, 0.2));
    menuContinents.push_back(Menu("AFRICA", 0.0, 0.2));
    menuContinents.push_back(Menu("ASIA", 0.0, 0.2));
    menuContinents.push_back(Menu("EUROPA", 0.0, 0.2));
}

void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    initMenus();
    gameState = 3;
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
    glGenTextures(8, texName); //Make room for our texture
    Image* image;
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/estrellas.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/map.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/Mapamundi.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/pin.bmp");loadTexture(image,i++); //ARREGLAR
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/america.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/asia.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/europa.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/africa.bmp");loadTexture(image,i++);
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

void drawMenuContinente()
{
    for(int i = 0; i < menuContinents.size(); i++)
    {
        menuContinents[i].drawMenu();
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

void despliegaPines()
{
    
    for (int i = 0; i< 10/*contPaises*/ ; i++)
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
        
        switch (numContinente) {
            case 1: //America
                //posiciones de los pines
                posX =  continente -> _america[i].posX;
                posY = continente -> _america[i].posY;
                break;
            case 2: //Asia
                //posiciones de los pines
                posX =  continente -> _asia[i].posX;
                posY = continente -> _asia[i].posY;
                break;
            case 3: //Europa
                // posX =  continente -> _europa[i].posX;
                // posY = continente -> _europa[i].posY;
                break;
            case 4: //Africa
                // posX =  continente -> _africa[i].posX;
                // posY = continente -> _africa[i].posY;
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
            numContinente = 1;
            contPaises = continente -> _america.capacity();
            //cout << contPaises;
            break;
        case 2:
            glBindTexture(GL_TEXTURE_2D, texName[5]);
            numContinente = 2;
            contPaises = continente -> _asia.capacity();
            break;
        case 3:
            glBindTexture(GL_TEXTURE_2D, texName[6]);
            numContinente = 3;
            //contPaises = continente -> _europa.capacity();
            break;
        case 4:
            glBindTexture(GL_TEXTURE_2D, texName[7]);
            numContinente = 4;
            // contPaises = continente -> _africa.capacity();
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
        
        switch (numContinente) {
            case 1: //America
                if (clicx >= continente -> _america[i].rangoX1 && clicx <= continente -> _america[i].rangoX2 && clicy >= continente -> _america[i].rangoY1 && clicy <= continente -> _america[i].rangoY2
                    ) {
                    codigo = continente ->_america[i].countryCode;
                }
                break;
            case 2: //Asia
                if (clicx >= continente -> _asia[i].rangoX1 && clicx <= continente -> _asia[i].rangoX2 && clicy >= continente -> _asia[i].rangoY1 && clicy <= continente -> _asia[i].rangoY2  ) {
                    codigo = continente ->_asia[i].countryCode;
                }
                break;
            case 3: //Europa
                
                break;
            case 4: //Africa
                
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
    float openGL_X = (x - 400.00)/400.00;
    float openGL_Y = (300.00 - y) / 300.00;
    int code = 0;
    cout << "En donde di clic: " << openGL_X << ", " << openGL_Y <<"\n";
    
    code = verificaPin(openGL_X,openGL_Y);
    cout << "El codigo es: " << code << "\n";
    //Aqui se manda llamar la funcion de monste que diga si si esta correcto o no procedimiento(code)
}

void mouse(int button, int state, int x, int y){
    
    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            callback(x,y);
            glutPostRedisplay();
        }
    }
    
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
    }else if(gameState == 2)
    {
        //sale sprite y menu continentes
    
    }else if(gameState == 3)
    {
        int mapa = 1; //1 america, 2 asia, 3 europa, 4 africa
        despliegaMapa(mapa);
    
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

void displayWindow2()
{

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
    glutMouseFunc(mouse);
    initRendering();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutSpecialFunc(teclasUPandDown);

    //mouse
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}