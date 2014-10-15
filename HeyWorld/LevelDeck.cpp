//
//  LevelDeck.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "LevelDeck.h"

void LevelDeck::getMonumentDeck(int d)
{

}

void LevelDeck::getFlagDeck(int d)
{

}

void LevelDeck::getCharacterDeck(int d)
{

}

// 0 monuments, 1 flags, 2 characters
void LevelDeck::getLevelDeck(int gameId, int difficult)
{
    switch(gameId)
    {
        case 0:
            getMonumentDeck(difficult);
            break;
        case 1:
            getFlagDeck(difficult);
            break;
        case 2:
            getCharacterDeck(difficult);
            break;
    }
}