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

void Game::startGame()
{
    createDeck();
    shuffleSprites();
    cubo.openCube();
   // cubo.rotateCube();
    
    
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
    
    cubo.drawCube();
    
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