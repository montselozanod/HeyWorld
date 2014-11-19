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

    glGenTextures(30, textures); //Make room for our texture
   Image* image;
    for(int j = 0; j < gameSprites.size(); j++)
    {
        std::cout<<gameSprites[j]->getImgName()<<std::endl;
        
        image = loadBMP(gameSprites[j]->getImgName());loadTexture(image,i++);
    }
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

void Game::timerQuestion(int v)
{
    if(v == numSprite)
    {
        if(countTimer < 10 && !answeredCorrect && !endGame)
        {
            countTimer++;
            std::cout<<countTimer<<std::endl;
            glutTimerFunc(1000, timerQuestion, numSprite);
        }else if(countTimer == 10 && !answeredCorrect && !endGame)
        {
            Game* game;
            game->lostQuestion(1);
        }
    }
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
    if(win)
    {
    
    }
    else
    {
    
    }
}