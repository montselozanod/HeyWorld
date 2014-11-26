//
//  LevelDeck.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "LevelDeck.h"

std::vector<Flag> LevelDeck::getTouristDeck()
{
    //tourist

    touristDeck.push_back(*new Flag("banderas/mexico.bmp",42)); //mexico
    touristDeck.push_back(*new Flag("banderas/eua.bmp",28)); //estados Uniods
    touristDeck.push_back(*new Flag("banderas/canada.bmp",16)); //canada
    touristDeck.push_back(*new Flag("banderas/francia.bmp",29)); //FRANCIA
    touristDeck.push_back(*new Flag("banderas/espana.bmp",27)); //españa
    touristDeck.push_back(*new Flag("banderas/brasil.bmp",14)); //Brasil
    touristDeck.push_back(*new Flag("banderas/argentina.bmp",7)); //ARGENTINA
    touristDeck.push_back(*new Flag("banderas/alemania.bmp",4)); //ALEMANIA
    touristDeck.push_back(*new Flag("banderas/china.bmp",18)); //CHINA
    touristDeck.push_back(*new Flag("banderas/rusia.bmp",53)); //RUSIA
    touristDeck.push_back(*new Flag("banderas/chile.bmp",17)); //chile
     touristDeck.push_back(*new Flag("banderas/egipto.bmp",25)); //egipto
    touristDeck.push_back(*new Flag("banderas/peru.bmp",48)); //peru
    touristDeck.push_back(*new Flag("banderas/portugal.bmp",49)); //portugal
    touristDeck.push_back(*new Flag("banderas/inglaterra.bmp",51)); //inglaterra
    touristDeck.push_back(*new Flag("banderas/japon.bmp",38)); //japón
    touristDeck.push_back(*new Flag("banderas/colombia.bmp",19)); //colombia
    touristDeck.push_back(*new Flag("banderas/ecuador.bmp",64)); //ecuador
    touristDeck.push_back(*new Flag("banderas/venezuela.bmp",58)); //venezuela

//    touristDeck.push_back(*new Flag(50)); //polonia
//    touristDeck.push_back(*new Flag(55)); //suiza
//    touristDeck.push_back(*new Flag(23)); //cuba
//    touristDeck.push_back(*new Flag(21)); //costa rica
//    touristDeck.push_back(*new Flag(36)); //italia
//
//    touristDeck.push_back(*new Flag(35)); //india
//    touristDeck.push_back(*new Flag(37)); //irlanda
//    touristDeck.push_back(*new Flag(31)); //grecia
//    
//    touristDeck.push_back(*new Flag(47)); //pakistan
//    touristDeck.push_back(*new Flag(45)); //noruega
//    touristDeck.push_back(*new Flag(40)); //libano
//  
//  
//    touristDeck.push_back(*new Flag(39)); //jordanía
//    touristDeck.push_back(*new Flag(30)); //finlandia
//    touristDeck.push_back(*new Flag(54)); //sudafrica
//    touristDeck.push_back(*new Flag(56)); //turquia
    //touristDeck.push_back(*new Flag(57)); //uruguay
    return touristDeck;
}

std::vector<Character>  LevelDeck::getAgentDeck()
{
    agentDeck.push_back(*new Character("personajes/peter.bmp","Peter Pan", 51));
    agentDeck.push_back(*new Character("personajes/walt.bmp","Walt Disney", 28));
    agentDeck.push_back(*new Character("personajes/albert.bmp","Albert Einstein", 4));
    agentDeck.push_back(*new Character("personajes/mandela.bmp","Nelson Mandela", 54));
    agentDeck.push_back(*new Character("personajes/juanpablo.bmp","Juan Pablo II", 50));
    agentDeck.push_back(*new Character("personajes/fidel.bmp","Fidel Castro", 23));
    agentDeck.push_back(*new Character("personajes/dali.bmp","Salvador Dalí", 27));
    agentDeck.push_back(*new Character("personajes/octaviopaz.bmp", "Octavio Paz", 42));
    
    agentDeck.push_back(*new Character("personajes/simon.bmp","Simón Bolívar", 58));
    agentDeck.push_back(*new Character("personajes/vladimir.bmp","Vladimir Putin", 53));
    agentDeck.push_back(*new Character("personajes/socrates.bmp","Socrates", 31));
    agentDeck.push_back(*new Character("personajes/gandhi.bmp","Mahatma Gandhi", 35));
    agentDeck.push_back(*new Character("personajes/guevara.bmp","Ernesto 'Che' Guevara", 7));
    agentDeck.push_back(*new Character("personajes/evaperon.bmp","Eva Perón", 7));
    agentDeck.push_back(*new Character("personajes/mariovargas.bmp","Mario Vargas Llosa", 48));
    agentDeck.push_back(*new Character("personajes/van.bmp","Vincent Van Gogh", 33));
    
    agentDeck.push_back(*new Character("personajes/tesla.bmp","Nikola Tesla", 22));
    agentDeck.push_back(*new Character("personajes/leo.bmp","Leonardo da Vinci", 36));
    agentDeck.push_back(*new Character("personajes/malala.bmp","Malala Yousafzai", 47));
    agentDeck.push_back(*new Character("personajes/mao.bmp","Mao ZeDong", 18));
    
    agentDeck.push_back(*new Character("personajes/barack.bmp","Barack Obama", 28));
    agentDeck.push_back(*new Character("personajes/steve.bmp","Steve Jobs", 28));
    agentDeck.push_back(*new Character("personajes/chaplin.bmp","Charlie Chaplin", 51));

    
    return agentDeck;
}

std::vector<Monument> LevelDeck::getGuruDeck()
{
   
    guruDeck.push_back(*new Monument("3DModels/empire.obj","Empire State", 28));
    guruDeck.push_back(*new Monument("3DModels/eiffel.obj","Torre Eiffel", 29));
    //guruDeck.push_back(*new Monument("Cristo Redentor", 14));
    //guruDeck.push_back(*new Monument("Big Ben", 51));
    guruDeck.push_back(*new Monument("3DModels/sun.obj","Piramide del Sol", 42));
    //guruDeck.push_back(*new Monument("Piramides de Giza", 25));
    //guruDeck.push_back(*new Monument("Gran Esfinge", 25));
    guruDeck.push_back(*new Monument("3DModels/Greatwall.obj","Gran Muralla", 18));
    guruDeck.push_back(*new Monument("3DModels/Taj-Mahal.obj","Taj Mahal", 35));
    guruDeck.push_back(*new Monument("3DModels/acropolis.obj","Acropolis", 31));
    //guruDeck.push_back(*new Monument("Coliseo", 36));
    
   // guruDeck.push_back(*new Monument("3DModels/guell.obj","Parc Guell", 27));
    guruDeck.push_back(*new Monument("3DModels/Brandenburg.obj","Puerta de Brandenburgo", 4));
     guruDeck.push_back(*new Monument("3DModels/blue.obj","Blue Mosque", 56));
    //guruDeck.push_back(*new Monument("Machu Picchu", 48));
   
    //guruDeck.push_back(*new Monument("Palacio de Shönbrunn", 9));
    //guruDeck.push_back(*new Monument("Monte Fuji", 38));
    //guruDeck.push_back(*new Monument("Reichstag", 4));
    //guruDeck.push_back(*new Monument("Stonehenge", 51));
    //guruDeck.push_back(*new Monument("Puerta de Alcalá", 27));

    guruDeck.push_back(*new Monument("3DModels/petronas.obj", "Torres Petronas", 41));
    //guruDeck.push_back(*new Monument("Puerta Sur de Jerash", 39));

    return guruDeck;
}

