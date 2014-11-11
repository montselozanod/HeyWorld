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
#include <math.h>
#include "Imageloader.h"
#include "MenuOption.h"
#include "Pin.h"
#include "World.h"

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
int gameState = 0;
GLuint texture = 0;
static GLuint texName[8];
int currentIndex = 0; //current indes for menus;
bool selectMenuPrincipal[4] = {true, false, false, false};
bool selectMenuDificultad[4] = {true, false, false, false};
int angulo=45;
/*Variables para dibujar los pines*/
bool arrPines[2]={false,false};
float radiusPin = .03;
float posX = 0.0;
float posY = 0.0;
int numContinente = 0; //1.America 2.Asia 3.Europa 4.Africa.. Esto es para saber qué vector agarramos
float contPaises = 0; //Variable para utilizar.. tiene la cantidad de paises en base al país seleccionado
World *continente = new World();
/**/


//Estados
// Escoger Opcion De Juego = 0
// Escoger Dificultad = 1
// Jugar = 3
// FIn = 4


void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    
    switch (theKey)
    {
            
            
        case 27: //esc
            exit(0);
            break;

        default:
        break;		          }
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

void init()
{
    glClearColor(1.0,.6,0,0); //background del display naranja
    gameState = 4; //lo cambie a 4 solo para ver el mapa
    currentIndex = 0;
    continente = new World();

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
   // glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_NORMALIZE); ///Users/mariaroque/Imagenes
    
    //glEnable(GL_TEXTURE_2D);
    
    //glClearColor(1.0,1.0,1.0,1.0);
    
    // glEnable(GL_COLOR_MATERIAL);
    glGenTextures(8, texName); //Make room for our texture
    Image* image;
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/estrellas.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/map.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/Mapamundi.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/pin.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/america.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/asia.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/europa.bmp");loadTexture(image,i++);
    image = loadBMP("/Users/arianacisneros/Desktop/Fotos/africa.bmp");loadTexture(image,i++);
     delete image;
}

void menuPrincipal()
{
    //void Menu::drawMenu(int ancho, int alto, int x, int y, bool selected)
    Menu menu1 = Menu("Instrucciones");
    menu1.drawMenu(0.4, 0.07, 0.0, 0.2, selectMenuPrincipal[0]);
    Menu menu = Menu("Monumentos");
    menu.drawMenu(0.4, 0.07, 0.0, 0.1, selectMenuPrincipal[1]);
    Menu menu2 = Menu("Banderas");
    menu2.drawMenu(0.4, 0.07, 0.0, 0.0, selectMenuPrincipal[2]);
    Menu menu3 = Menu("Personajes");
    menu3.drawMenu(0.4, 0.07, 0.0, -0.1, selectMenuPrincipal[3]);
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
        
        
        
        /*Menu principal*/
        menuPrincipal();
        
    }else if(gameState == 1)
    {
        
        menuDificultad();
    }else if(gameState == 3)
    {
    
    }else if (gameState == 4)
    {
        int mapa = 1; //1 america, 2 asia, 3 europa, 4 africa
        despliegaMapa(mapa);
        
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