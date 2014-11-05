//
//  DealGame.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//


/*
 TODO
 --- agregar difficult
 --- agregar visible
 - vector con todos los países
 - vector con monumentos
 - vector con banderas
 - vector con characters
 
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

void Game::chooseGame(int game)
{
    typeGame = game;
}

void Game::deckMonuments()
{

}

void Game::deckFlags()
{

}

void Game::deckCharacters()
{
    
}


void Game::createDeck()
{
//    switch (typeGame) {
//        case 0:
//            gameSprites = deckLevel.getMonumentDeck(difficulty);
//            break;
//        case 1:
//            gameSprites = deckLevel.getFlagDeck(difficulty);
//            break;
//        case 2:
//            gameSprites = deckLevel.getCharacterDeck(difficulty);
//            break;
//    }
}

void Game::startGame()
{
    createDeck();
}

void Game::shuffleSprites()
{

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