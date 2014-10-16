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
    touristMonuments.push_back(*new Monument("Estatua de la Libertad", 0));
    touristMonuments.push_back(*new Monument("Torre Eiffel", 33));
    touristMonuments.push_back(*new Monument("Cristo Redentor", 55));
    touristMonuments.push_back(*new Monument("Big Ben", 44));
    touristMonuments.push_back(*new Monument("Chichen-Itza", 52));
    touristMonuments.push_back(*new Monument("Piramides de Giza", 20));
    touristMonuments.push_back(*new Monument("Gran Esfinge", 20));
    touristMonuments.push_back(*new Monument("Gran Muralla", 86));
    touristMonuments.push_back(*new Monument("Taj Mahal", 91));
    touristMonuments.push_back(*new Monument("Acropolis", 30));
    touristMonuments.push_back(*new Monument("Coliseo", 39));
    touristMonuments.push_back(*new Monument("Sydney Opera House", 61));
    touristMonuments.push_back(*new Monument("Sagrada Familia", 34));
    touristMonuments.push_back(*new Monument("Palacio de Shönbrunn", 43));
    touristMonuments.push_back(*new Monument("Puerta de Brandenburgo", 49));
    touristMonuments.push_back(*new Monument("Machu Picchu", 51));


}

void LevelDeck::getFlagDeck(int d)
{

}

void LevelDeck::getCharacterDeck(int d)
{
    touristCharacter.push_back(*new Character("Albert Einstein", 49));
    touristCharacter.push_back(*new Character("Nelson Mandela", 211));
    touristCharacter.push_back(*new Character("Ernesto 'Che' Guevara", 32));
    touristCharacter.push_back(*new Character("Juan Pablo II", 48));
    touristCharacter.push_back(*new Character("Fidel Castro", 53));
    touristCharacter.push_back(*new Character("Salvador Dalí", 34));
    touristCharacter.push_back(*new Character("Simón Bolívar", 58));
    touristCharacter.push_back(*new Character("Octavio Paz", 52));
    
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