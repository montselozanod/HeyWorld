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
    touristMonuments.push_back(*new Monument("Estatua de la Libertad", 22));
    touristMonuments.push_back(*new Monument("Torre Eiffel", 23));
    touristMonuments.push_back(*new Monument("Cristo Redentor", 8));
    touristMonuments.push_back(*new Monument("Big Ben", 44));
    touristMonuments.push_back(*new Monument("Chichen-Itza", 36));
    touristMonuments.push_back(*new Monument("Piramides de Giza", 19));
    touristMonuments.push_back(*new Monument("Gran Esfinge", 19));
    touristMonuments.push_back(*new Monument("Gran Muralla", 12));
    touristMonuments.push_back(*new Monument("Taj Mahal", 29));
    touristMonuments.push_back(*new Monument("Acropolis", 25));
    touristMonuments.push_back(*new Monument("Coliseo", 30));
    touristMonuments.push_back(*new Monument("Sydney Opera House", 8));
    touristMonuments.push_back(*new Monument("Sagrada Familia", 21));
    touristMonuments.push_back(*new Monument("Palacio de Shönbrunn", 9));
    touristMonuments.push_back(*new Monument("Puerta de Brandenburgo", 4));
    touristMonuments.push_back(*new Monument("Machu Picchu", 41));


}

void LevelDeck::getFlagDeck(int d)
{

}

void LevelDeck::getCharacterDeck(int d)
{
    touristCharacter.push_back(*new Character("Albert Einstein", 4));
    touristCharacter.push_back(*new Character("Nelson Mandela", 46));
    touristCharacter.push_back(*new Character("Ernesto 'Che' Guevara", 7));
    touristCharacter.push_back(*new Character("Juan Pablo II", 43));
    touristCharacter.push_back(*new Character("Fidel Castro", 17));
    touristCharacter.push_back(*new Character("Salvador Dalí", 21));
    touristCharacter.push_back(*new Character("Simón Bolívar", 50));
    touristCharacter.push_back(*new Character("Octavio Paz", 36));
    
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