//
//  LevelDeck.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "LevelDeck.h"

std::vector<Monument> LevelDeck::getMonumentDeck(int d)
{
    switch(d){
    case 0:
    //tourist
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
    touristMonuments.push_back(*new Monument("Puerta de Brandenburgo", 4));
    touristMonuments.push_back(*new Monument("Machu Picchu", 48));
            return touristMonuments;
            break;
    
        case 1:
    //agent
    agentMonuments.push_back(*new Monument("Palacio de Shönbrunn", 9));
    agentMonuments.push_back(*new Monument("Monte Fuji", 38));
    agentMonuments.push_back(*new Monument("Reichstag", 4));
    agentMonuments.push_back(*new Monument("Stonehenge", 51));
    agentMonuments.push_back(*new Monument("Puerta de Alcalá", 27));
            return agentMonuments;
            break;

    case 2:
    //guru
    guruMonuments.push_back(*new Monument("Torres Petronas", 41));
    guruMonuments.push_back(*new Monument("Puerta Sur de Jerash", 39));
    return guruMonuments;
    break;
    }
    
    return touristMonuments;
}

std::vector<Flag> LevelDeck::getFlagDeck(int d)
{
    switch(d)
    {
        case 0:
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
            return touristFlag;
            break;
    
    //agent
        case 1:
    agentFlag.push_back(*new Flag(50)); //polonia
    agentFlag.push_back(*new Flag(55)); //suiza
    agentFlag.push_back(*new Flag(23)); //cuba
    agentFlag.push_back(*new Flag(21)); //costa rica
    agentFlag.push_back(*new Flag(36)); //italia
    agentFlag.push_back(*new Flag(38)); //japón
    agentFlag.push_back(*new Flag(35)); //india
    agentFlag.push_back(*new Flag(37)); //irlanda
    agentFlag.push_back(*new Flag(31)); //grecia
            return agentFlag;
            break;
    
    //guru
        case 2:
    guruFlag.push_back(*new Flag(47)); //pakistan
    guruFlag.push_back(*new Flag(45)); //noruega
    guruFlag.push_back(*new Flag(40)); //libano
    guruFlag.push_back(*new Flag(49)); //portugal
    guruFlag.push_back(*new Flag(48)); //peru
    guruFlag.push_back(*new Flag(39)); //jordanía
    guruFlag.push_back(*new Flag(30)); //finlandia
    guruFlag.push_back(*new Flag(54)); //sudafrica
    guruFlag.push_back(*new Flag(56)); //turquia
            return guruFlag;
            break;
    }
    return touristFlag;
}

std::vector<Character>  LevelDeck::getCharacterDeck(int d)
{
    switch(d){
    //tourist
        case 0:
    touristCharacter.push_back(*new Character("Peter Pan", 51));
    touristCharacter.push_back(*new Character("Walt Disney", 28));
    touristCharacter.push_back(*new Character("Albert Einstein", 4));
    touristCharacter.push_back(*new Character("Nelson Mandela", 54));
    touristCharacter.push_back(*new Character("Juan Pablo II", 50));
    touristCharacter.push_back(*new Character("Fidel Castro", 23));
    touristCharacter.push_back(*new Character("Salvador Dalí", 27));
    touristCharacter.push_back(*new Character("Octavio Paz", 42));
            return touristCharacter;
            break;
    
        case 1:
    //agent
    agentCharacter.push_back(*new Character("Simón Bolívar", 58));
    agentCharacter.push_back(*new Character("Vladimir Putin", 53));
    agentCharacter.push_back(*new Character("Socrates", 31));
    agentCharacter.push_back(*new Character("Mahatma Gandhi", 35));
    agentCharacter.push_back(*new Character("Ernesto 'Che' Guevara", 7));
    agentCharacter.push_back(*new Character("Eva Perón", 7));
    agentCharacter.push_back(*new Character("Mario Vargas Llosa", 48));
    agentCharacter.push_back(*new Character("Vincent Van Gogh", 33));
            return agentCharacter;
            break;
    
        case 2:
    //guru
    guruCharacter.push_back(*new Character("Nikola Tesla", 22));
    guruCharacter.push_back(*new Character("Leonardo da Vinci", 36));
    guruCharacter.push_back(*new Character("Malala Yousafzai", 47));
    guruCharacter.push_back(*new Character("Mao ZeDong", 18));
            return guruCharacter;
            break;
    }
    return touristCharacter;
}
