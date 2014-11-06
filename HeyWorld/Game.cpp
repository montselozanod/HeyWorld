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

}

Game::Game(int game, int diff)
{
    typeGame = game;
    difficulty = diff;
}

void Game::setDifficultyGame(int dif)
{
    difficulty = dif;
}

void Game::setTypeGame(int type)
{
    typeGame = type;
}

void Game::createDeck()
{
    std::vector<Monument> mon;
    std::vector<Flag> flag;
    std::vector<Character> chara;

    switch (typeGame)
    {
        case 0:
             mon = (std::vector<Monument>) deckLevel.getMonumentDeck(difficulty);
            for (int i = 0; i < mon.size(); i++) {
                gameSprites.push_back(new Monument(mon[i]));
            }
            
            break;
        case 1:
            flag = (std::vector<Flag>) deckLevel.getFlagDeck(difficulty);
            for (int i = 0; i < flag.size(); i++) {
                gameSprites.push_back(new Flag(flag[i]));
            }
            break;
        case 2:
            chara = (std::vector<Character>) deckLevel.getCharacterDeck(difficulty);
            for (int i = 0; i < chara.size(); i++) {
                gameSprites.push_back(new Character(chara[i]));
            }
            break;
    }
}

void Game::startGame()
{
    createDeck();
    shuffleSprites();
    
    for(int i = 0; i < gameSprites.size(); i++)
    {
        std::cout<<gameSprites[i]->myCountry.name<<std::endl;
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
    
}

bool Game::checkSprite(int codeCountry)
{
    if(gameSprites[numRondas]->myCountry.countryCode == codeCountry)
    {
        return true;
    }else{
        return false;
    }
}