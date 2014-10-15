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

#include "DealGame.h"

DealGame::DealGame(int game, int diff)
{
    typeGame = game;
    difficulty = diff;
}

void DealGame::chooseGame(int game)
{
    typeGame = game;
}

void createDeck()
{
    
}

void DealGame::startGame()
{

}

void DealGame::showSprite()
{

}

bool DealGame::checkSprite()
{
    return true;
}