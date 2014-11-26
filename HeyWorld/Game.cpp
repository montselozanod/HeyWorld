//
//  DealGame.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//


/*
    Monumentos = 0
    Banderas = 1
    Personajes = 2
 */

#include "Game.h"


Game::Game()
{
    endGame = false;
    win = false;
    cubo = Cube();
 
    answeredCorrect = false;
}

Game::Game(int diff)
{
    user = User();
    difficulty = diff;
    endGame = false;
    win = false;
    answeredCorrect = false;
}

void Game::setDifficultyGame(int dif)
{
    difficulty = dif;
}

//void Game::setTypeGame(int type)
//{
//    typeGame = type;
//}

void Game::createDeck()
{
    std::vector<Monument> mon;
    std::vector<Flag> flag;
    std::vector<Character> chara;

    switch (difficulty)
    {
        case 0:
            flag = (std::vector<Flag>) deckLevel.getTouristDeck();
            for (int i = 0; i < flag.size(); i++) {
                gameSprites.push_back(new Flag(flag[i]));
            }
            break;
            
        case 1:
            chara = (std::vector<Character>) deckLevel.getAgentDeck();
            for (int i = 0; i < chara.size(); i++) {
                gameSprites.push_back(new Character(chara[i]));
            }
            break;
        case 2:
            mon = (std::vector<Monument>) deckLevel.getGuruDeck();
            for (int i = 0; i < mon.size(); i++) {
                gameSprites.push_back(new Monument(mon[i]));
            }
            
            break;
    }
}

//Makes the image into a texture, and returns the id of the texture
void Game::loadTexture(Image* image,int k)
{
    
    glBindTexture(GL_TEXTURE_2D, textures[k]); //Tell OpenGL which texture to edit
    
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

void Game::initRenderImages()
{
    GLuint i=0;
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glEnable(GL_DEPTH_TEST);

    glGenTextures(40, textures); //Make room for our texture
   Image* image;
    for(int j = 0; j < gameSprites.size(); j++)
    {
        std::cout<<gameSprites[j]->getImgName()<<std::endl;
        
        image = loadBMP(gameSprites[j]->getImgName());loadTexture(image,i++);
    }
    
    image = loadBMP("gameoverColor.bmp");loadTexture(image,30);
    //image = loadBMP("carafeliz1.bmp");loadTexture(image,32);

    
}

void Game::startGame()
{
    createDeck();
    shuffleSprites();
    numSprite = (int)gameSprites.size()-1;
    initRenderImages();
    gameSprites[numSprite]->visibility = true;
    playGame();
    
}

void Game::instruccionesTeclado()
{
// pintar instrucciones de teclado
    sprintf(instrucciones, "P-Pausar, R-Reiniciar, S-Sonido");
    //sprintf(instrucciones, "I-Iniciar, P-Pausar, R-Reiniciar, S-Sound");
    glPushMatrix();
    glTranslated(-0.3, -0.6, 0);
    glColor3f(100, 24, 100);
    glRasterPos2d(0, 0);
    for(int i= 0; instrucciones[i]!='\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instrucciones[i]);
    }
    glPopMatrix();
}


void Game::initReloj()
{
    _num = 0;
    displayTiempo();
}


void Game::displayTiempo()
{

    glPushMatrix();
    glTranslated(-0.6, -0.6, 0);
    glColor3f(100, 24, 100);
    glRasterPos2d(0, 0);
    for(int i= 0; tiempo[i]!='\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tiempo[i]);
    }
    glPopMatrix();
}

void Game::shuffleSprites()
{
    srand (time(NULL) );
    int size = (int)gameSprites.size();
    
    for(int i = 0; i < size; i++)
    {
        int j = rand()% size;
        Sprite *tmp = gameSprites[i];
        gameSprites[i] = gameSprites[j];
        gameSprites[j] = tmp;
    }
}


void Game::playGame()
{
    if(!endGame)
      {

        if(user.isPlayerAlive())
        {
            cubo.closeCube();
            showSprite();
            displayTiempo();
            cubo.rotateCube();
            answeredCorrect = false;
            countTimer = 0;
            glutTimerFunc(1000, timerQuestion, numSprite);

        }else
        {
            endGame = true;
            std::cout<<"LOST ALL GAMEEE::: AM SORRY!!! TRY AGAIN"<<std::endl;
        }
    
      }else
          finishGame();

}

void Game::showSprite()
{
    gameSprites[numSprite]->visibility = false;
    if(numSprite - 1 < 0)
    {
        endGame = true;
        win = true;
        return;
    }else
    {
        numSprite--;
        gameSprites[numSprite]->visibility = true;
    }
}

bool Game::mapClick(int codeCountry)
{
    if(!endGame)
    {

        if(checkSprite(codeCountry))
        {
            playGame();
            return true;
        }else
        {
        return false;
        }
    }else
    {
        return false;
    }
}

bool Game::checkSprite(int codeCountry)
{
    Sprite *current = gameSprites[numSprite];
    if(current->countryCode == codeCountry)
    {
        user.numberPoints++;
        std::cout<<"correct"<<std::endl;
        answeredCorrect = true;
        return true;
    }else{
        lostQuestion(0);
        return false;
    }
}

void Game::draw()
{

    if(!endGame){
    cubo.drawCube(); //Dibujar cubo del lado derecho
    
    Sprite *current;
    for(int j = 0; j < gameSprites.size(); j++)
    {
        current = gameSprites[j];
        if(current->visibility)
        {
            
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textures[j]);
            gameSprites[j]-> drawSprite();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
    }
    }else
    {
        finishGame();
    }
}


void formato()
{
    int mili = _num % 10;
    int seg = (_num/10)%60;
    int min = (_num/10)/60;
    
    if(seg < 10)
    {
        sprintf(tiempo, "%d : 0%d : %d", min, seg, mili);
    }
    else
    {
        sprintf(tiempo, "%d : %d : %d", min, seg, mili);
    }
    
}


void Game::timerQuestion(int v)
{
    if(v == numSprite)
    {
        if(countTimer < 10 && !answeredCorrect && !endGame)
        {
            countTimer++;
            _num = countTimer;
            //sprintf(tiempo, "%d : 0%d : %d", 0, 0, _num);
            std::cout<<countTimer<<std::endl;
            formato();
            std::cout<<tiempo<<"\n";
            glutPostRedisplay();
            glutTimerFunc(1000, timerQuestion, numSprite);
        }else if(countTimer == 10 && !answeredCorrect && !endGame)
        {
            Game* game;
            game->lostQuestion(1);
        }
    }
}

void Game::timerFinishGame(int v)
{
    
    rot_angle = (rot_angle > 360.0)?0:rot_angle + 2;
    rot_angle_y = (rot_angle_y > 180.0)?0:rot_angle_y + 1;
    rot_angle_x = (rot_angle_x > 180.0)?0:rot_angle_x + 1.0/(2*3.1416);
    glutPostRedisplay();
    
    glutTimerFunc(10, timerFinishGame, 1);
}


void Game::lostQuestion(int type)
{
    user.deleteVisa();
    
    if(type == 1)
    {
        std::cout<<"wrong -- lost time"<<std::endl;
        playGame();
    }else if(type == 0)
    {
        std::cout<<"wrong -- wrong answer.. you still have time"<<std::endl;
    }
}

//void Game::waitForAnswer()
//{
//    while(!answeredCorrect && countTimer < 10)
//    {
//        countTimer++;
//    }
//    
//    if(countTimer == 10 && !answeredCorrect)
//    {
//        lostQuestion(1);
//    }
//}

void Game::finishGame()
{
    float mat_ambient_diffuse [] = {1,1,1.0,1.0};
    float mat_specular [] = {0.0,0.2,0.7,1.0};
    float mat_emission [] = {1.0,0.0,0.0,1.0};
    float light_ambient [] = {0.0,0.2,0.0,1.0};
    float light_diffuse_specular [] = {1,1,1,1.0};
    float light_diffuse_specular2 [] = {1,0,0,1.0};
    float light_pos [] = {1.0,0.0,2.0,1.0};
    float light_pos2 [] = {0.0,0.0,2.0,1.0};
    float mat_shininess = 0.1;
    float focus_emission [] = {0.8,0.8,0.8,1.0};
    float focus_emission2 [] = {0,1,0,1.0};
    float spot_dir [] = {0.0,0.0,-1.0};
    float spot_cutoff = 20.0;
    float spot_exponent = 1.0;
    glutTimerFunc(0, timerFinishGame, 1);
    
    if(win)
    {
    
        /*TEXTURA YOU WON!*/
        float mat_emissionG [] = {1.0,1.0,1.0,1.0};
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
        glLoadIdentity();//que no tenga ninguna transformación
        gluLookAt(0, 0, 1, 0, 0, 0, 0, .1, 0);//movemos camara para que se vea el mapa
    
    
        glEnable(GL_BLEND); // Activamos la transparencia
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //GL_DST_COLOR, GL_ONE
        glEnable(GL_TEXTURE_2D);
        glColor4fv(mat_emissionG);
        glMatrixMode(GL_TEXTURE);//Activar matriz de textura
        glBindTexture(GL_TEXTURE_2D, textures[30]); //Seleccion de textura
        
        glPushMatrix();
        glRotated(rot_angle, 1, 1, 1); //se acumula en la matriz de TEXTURE
        glColor3f(1.0f, 1.0f, 1.0f);
        
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); //se pega la textura con
        glVertex3f(-0.3, -0.3, 0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.3, -0.3, 0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.3, 0.3, 0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.3, 0.3, 0);
        glEnd();
        glPopMatrix();
        glPopMatrix(); //pop de camara
        glDisable(GL_BLEND); //para desactivarlo.
        glDisable(GL_TEXTURE_2D);
    
        //FONDO DE COLORES
        
        glShadeModel(GL_FLAT);
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
        glLoadIdentity();//que no tenga ninguna transformación
        gluLookAt(0, 0, 1, 0, 0, 0, 0, .1, 0);
        
        glPushMatrix();
        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0,1.0,1.0,0.0);
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
        glEnable(GL_LIGHTING);
        glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse_specular);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light_diffuse_specular);
        glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,spot_cutoff);
        glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,spot_exponent);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
        glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse_specular2);
        glLightfv(GL_LIGHT1,GL_SPECULAR,light_diffuse_specular2);
        glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,spot_cutoff);
        glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,spot_exponent);
        glEnable(GL_LIGHT1);
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
        glMaterialf(GL_FRONT,GL_SHININESS,mat_shininess);
        
        glPushMatrix();
        glRotatef(rot_angle_y,0.0,1.0,0.0);
        glRotatef(rot_angle_x,1.0,0.0,0.0);
        glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
        glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_dir);
        glTranslatef(light_pos[0],light_pos[1],light_pos[2]);
        glColorMaterial(GL_FRONT,GL_EMISSION);
        glEnable(GL_COLOR_MATERIAL);
        glColor4fv(focus_emission);
        glColor4fv(mat_emission);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
        
        glPushMatrix();
        glPushMatrix();
        glRotatef(-90.0,0.0,0.0,1.0);
        glRotatef(rot_angle_y,0.0,1.0,0.0);
        glRotatef(rot_angle_x,1.0,0.0,0.0);
        glLightfv(GL_LIGHT1,GL_POSITION,light_pos);
        glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_dir);
        //glTranslatef(light_pos2[0],light_pos2[1],light_pos2[2]);
        glColorMaterial(GL_FRONT,GL_EMISSION);
        glEnable(GL_COLOR_MATERIAL);
        glColor4fv(focus_emission2);
        glColor4fv(mat_emission);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
        glutSolidSphere(1.0,30,30);
        glPopMatrix();
        
        glPopMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
    }
    else
    {
        /*TEXTURA GAME OVER*/
        float mat_emissionG [] = {1.0,1.0,1.0,1.0};
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
        glLoadIdentity();//que no tenga ninguna transformación
        gluLookAt(0, 0, 1, 0, 0, 0, 0, .1, 0);//movemos camara para que se vea el mapa
        
        glEnable(GL_BLEND); // Activamos la transparencia
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //GL_DST_COLOR, GL_ONE
        glEnable(GL_TEXTURE_2D);
        glColor4fv(mat_emissionG);
        glMatrixMode(GL_TEXTURE);//Activar matriz de textura
        glBindTexture(GL_TEXTURE_2D, textures[30]); //Seleccion de textura
        
        glPushMatrix();
        glRotated(rot_angle, 1, 1, 1); //se acumula en la matriz de TEXTURE
        glColor3f(1.0f, 1.0f, 1.0f);
        
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); //se pega la textura con
        glVertex3f(-0.3, -0.3, 0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.3, -0.3, 0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.3, 0.3, 0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.3, 0.3, 0);
        glEnd();
        glPopMatrix();
        
        glPopMatrix(); //pop de camara
        glDisable(GL_BLEND); //para desactivarlo.
        glDisable(GL_TEXTURE_2D);
        
        
        //FONDO DE COLORES
        
        //glShadeModel(GL_FLAT);
        
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
        glLoadIdentity();//que no tenga ninguna transformación
        gluLookAt(0, 0, 1, 0, 0, 0, 0, .1, 0);
        
    
        glPushMatrix();
        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0,1.0,1.0,0.0);
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
        glEnable(GL_LIGHTING);
        glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse_specular);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light_diffuse_specular);
        glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,spot_cutoff);
        glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,spot_exponent);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
        glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse_specular2);
        glLightfv(GL_LIGHT1,GL_SPECULAR,light_diffuse_specular2);
        glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,spot_cutoff);
        glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,spot_exponent);
        glEnable(GL_LIGHT1);
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
        glMaterialf(GL_FRONT,GL_SHININESS,mat_shininess);
        
        glPushMatrix();
        glRotatef(rot_angle_y,0.0,1.0,0.0);
        glRotatef(rot_angle_x,1.0,0.0,0.0);
        glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
        glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_dir);
        glTranslatef(light_pos[0],light_pos[1],light_pos[2]);
        glColorMaterial(GL_FRONT,GL_EMISSION);
        glEnable(GL_COLOR_MATERIAL);
        glColor4fv(focus_emission);
        glColor4fv(mat_emission);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
        
        glPushMatrix();
        glPushMatrix();
        glRotatef(-90.0,0.0,0.0,1.0);
        glRotatef(rot_angle_y,0.0,1.0,0.0);
        glRotatef(rot_angle_x,1.0,0.0,0.0);
        glLightfv(GL_LIGHT1,GL_POSITION,light_pos);
        glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_dir);
        //glTranslatef(light_pos2[0],light_pos2[1],light_pos2[2]);
        glColorMaterial(GL_FRONT,GL_EMISSION);
        glEnable(GL_COLOR_MATERIAL);
        glColor4fv(focus_emission2);
        glColor4fv(mat_emission);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
        glutSolidSphere(1.0,30,30);
        glPopMatrix();
        
        glPopMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_COLOR_MATERIAL);
        glPopMatrix();
    
    }
    
        glFlush();
}