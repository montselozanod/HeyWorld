//
//  DealGame.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//


/*
 TODO
 --- agregar visible 
 */

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
}

Game::Game(int diff)
{
    user = User();
    difficulty = diff;
    endGame = false;
    win = false;
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
    
    glGenTextures(11, textures); //Make room for our texture
   Image* image;
    for(int i = 0; i < gameSprites.size(); i++)
    {
        std::cout<<gameSprites[i]->getImgName()<<std::endl;
        
        image = loadBMP(gameSprites[i]->getImgName());loadTexture(image,i++);
    }
}

void Game::startGame()
{
    createDeck();
    shuffleSprites();
    initRenderImages();
    //cubo.openCube();
   cubo.rotateCube();

    for(int i = 0; i < gameSprites.size(); i++)
    {
        std::cout<<gameSprites[i]->countryCode<<std::endl;
        //std::cout<<mon->getName()<<std::endl;
    }
    
    
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

void Game::showSprite()
{
    if(!gameSprites.empty())
    {
        gameSprites.pop_back();
    }
    else
    {
        endGame = true;
        win = true;
    }
        
}

void Game::playGame()
{
    while(!endGame)
    {
        if(user.isPlayerAlive())
        {
            showSprite();
            
            
            //llamar a checkSprite
            
            numRondas++;
        }else
        {
            endGame = true;
        }
    
    }
    
    finishGame();
}

bool Game::checkSprite(int codeCountry)
{
    if(gameSprites[numRondas]->countryCode == codeCountry)
    {
        user.numberPoints++;
        return true;
    }else{
        user.deleteVisa();
        return false;
    }
}

void Game::draw()
{
    
    cubo.drawCube(); //Dibujar cubo del lado derecho
    
    //Mandar llamar una bandera
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    gameSprites[0] -> drawSprite();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Game::finishGame()
{
    if(win)
    {
    
    }
    else
    {
    
    }
}