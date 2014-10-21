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
    touristMonuments.push_back(*new Monument("Estatua de la Libertad", 28));
    touristMonuments.push_back(*new Monument("Torre Eiffel", 29));
    touristMonuments.push_back(*new Monument("Cristo Redentor", 14));
    touristMonuments.push_back(*new Monument("Big Ben", 51));
    touristMonuments.push_back(*new Monument("Chichen-Itza", 42));
    touristMonuments.push_back(*new Monument("Piramides de Giza", 25));
    touristMonuments.push_back(*new Monument("Gran Esfinge", 25));
    touristMonuments.push_back(*new Monument("Gran Muralla", 18));
    touristMonuments.push_back(*new Monument("Taj Mahal", 35));
    touristMonuments.push_back(*new Monument("Acropolis", 31));
    touristMonuments.push_back(*new Monument("Coliseo", 36));
    touristMonuments.push_back(*new Monument("Sydney Opera House", 8));
    touristMonuments.push_back(*new Monument("Sagrada Familia", 27));
    touristMonuments.push_back(*new Monument("Palacio de Shönbrunn", 9));
    touristMonuments.push_back(*new Monument("Puerta de Brandenburgo", 4));
    touristMonuments.push_back(*new Monument("Machu Picchu", 48));


}

void LevelDeck::getFlagDeck(int d)
{
    //tourist
    touristFlag.push_back(*new Flag(42)); //mexico
    touristFlag.push_back(*new Flag(28)); //estados Uniods
    touristFlag.push_back(*new Flag(16)); //canada
    touristFlag.push_back(*new Flag(29)); //FRANCIA
    touristFlag.push_back(*new Flag(27)); //españa
    touristFlag.push_back(*new Flag(14)); //Brasil
    touristFlag.push_back(*new Flag(7)); //ARGENTINA
    touristFlag.push_back(*new Flag(4)); //ALEMANIA
    touristFlag.push_back(*new Flag(18)); //CHINA
    touristFlag.push_back(*new Flag(53)); //RUSIA
    touristFlag.push_back(*new Flag(17)); //chile
      touristFlag.push_back(*new Flag(57)); //uruguay
    
    //agent
    
    touristFlag.push_back(*new Flag(50)); //polonia
    touristFlag.push_back(*new Flag(55)); //suiza
    touristFlag.push_back(*new Flag(23)); //cuba
    touristFlag.push_back(*new Flag(21)); //costa rica
    touristFlag.push_back(*new Flag(36)); //italia
    touristFlag.push_back(*new Flag(38)); //japón
    touristFlag.push_back(*new Flag(35)); //india
    touristFlag.push_back(*new Flag(37)); //irlanda
    touristFlag.push_back(*new Flag(31)); //grecia

    
    //guru
    touristFlag.push_back(*new Flag(47)); //pakistan
    touristFlag.push_back(*new Flag(45)); //noruega
    touristFlag.push_back(*new Flag(40)); //libano
    touristFlag.push_back(*new Flag(49)); //portugal
    touristFlag.push_back(*new Flag(48)); //peru
    touristFlag.push_back(*new Flag(39)); //jordanía
    touristFlag.push_back(*new Flag(30)); //finlandia
    touristFlag.push_back(*new Flag(54)); //sudafrica
    touristFlag.push_back(*new Flag(56)); //turquia

}

void LevelDeck::getCharacterDeck(int d)
{
    //tourist
    touristCharacter.push_back(*new Character("Peter Pan", 51));
    touristCharacter.push_back(*new Character("Walt Disney", 28));
    touristCharacter.push_back(*new Character("Albert Einstein", 4));
    touristCharacter.push_back(*new Character("Nelson Mandela", 54));
    touristCharacter.push_back(*new Character("Juan Pablo II", 50));
    touristCharacter.push_back(*new Character("Fidel Castro", 23));
    touristCharacter.push_back(*new Character("Salvador Dalí", 27));
    touristCharacter.push_back(*new Character("Octavio Paz", 42));
    
    //agent
    touristCharacter.push_back(*new Character("Simón Bolívar", 58));
    touristCharacter.push_back(*new Character("Vladimir Putin", 53));
    touristCharacter.push_back(*new Character("Socrates", 31));
    touristCharacter.push_back(*new Character("Mahatma Gandhi", 35));
    touristCharacter.push_back(*new Character("Ernesto 'Che' Guevara", 7));
    touristCharacter.push_back(*new Character("Eva Perón", 7));
    touristCharacter.push_back(*new Character("Mario Vargas Llosa", 48));
    touristCharacter.push_back(*new Character("Vincent Van Gogh", 33));
    
    //guru
    touristCharacter.push_back(*new Character("Nikola Tesla", 22));
    touristCharacter.push_back(*new Character("Leonardo da Vinci", 36));
    touristCharacter.push_back(*new Character("Malala Yousafzai", 47));
    touristCharacter.push_back(*new Character("Mao ZeDong", 18));
    
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