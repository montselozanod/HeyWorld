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
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/mexico.bmp",42)); //mexico
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/eua.bmp",28)); //estados Uniods
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/canada.bmp",16)); //canada
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/francia.bmp",29)); //FRANCIA
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/espana.bmp",27)); //españa
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/brasil.bmp",14)); //Brasil
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/argentina.bmp",7)); //ARGENTINA
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/alemania.bmp",4)); //ALEMANIA
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/china.bmp",18)); //CHINA
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/rusia.bmp",53)); //RUSIA
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/chile.bmp",17)); //chile
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/egipto.bmp",25)); //egipto
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/peru.bmp",48)); //peru
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/portugal.bmp",49)); //portugal
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/inglaterra.bmp",51)); //inglaterra
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/japon.bmp",38)); //japón
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/colombia.bmp",19)); //colombia
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/ecuador.bmp",64)); //ecuador
    touristDeck.push_back(*new Flag("/Users/arianacisneros/Desktop/GraficasComputacionales/proyecto/HeyWorld/HeyWorld/banderas/venezuela.bmp",58)); //venezuela

    
    //tourist

  /*  touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/mexico.bmp",42)); //mexico
=======
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/mexico.bmp",42)); //mexico
>>>>>>> 980077a5fca7f9e6ea6dbea21ef2099bc372973f
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/eua.bmp",28)); //estados Uniods
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/canada.bmp",16)); //canada
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/francia.bmp",29)); //FRANCIA
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/espana.bmp",27)); //españa
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/brasil.bmp",14)); //Brasil
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/argentina.bmp",7)); //ARGENTINA
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/alemania.bmp",4)); //ALEMANIA
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/china.bmp",18)); //CHINA
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/rusia.bmp",53)); //RUSIA
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/chile.bmp",17)); //chile
     touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/egipto.bmp",25)); //egipto
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/peru.bmp",48)); //peru
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/portugal.bmp",49)); //portugal
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/inglaterra.bmp",51)); //inglaterra
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/japon.bmp",38)); //japón
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/colombia.bmp",19)); //colombia
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/ecuador.bmp",64)); //ecuador
    touristDeck.push_back(*new Flag("/Users/mariamontserratlozano/Documents/Carrera 7/Graficas/HeyWorld/HeyWorld/banderas/venezuela.bmp",58)); //venezuela
<<<<<<< HEAD
    */

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
    agentDeck.push_back(*new Character("Peter Pan", 51)); //internet
    agentDeck.push_back(*new Character("Walt Disney", 28)); //internet
    agentDeck.push_back(*new Character("Albert Einstein", 4)); //LISTO
    agentDeck.push_back(*new Character("Nelson Mandela", 54)); //Listo
    agentDeck.push_back(*new Character("Juan Pablo II", 50)); //internet
    agentDeck.push_back(*new Character("Fidel Castro", 23)); //Listo
    agentDeck.push_back(*new Character("Salvador Dalí", 27));//LISTO
    agentDeck.push_back(*new Character("Octavio Paz", 42)); //LISTO
    
    
    agentDeck.push_back(*new Character("Simón Bolívar", 58));
    agentDeck.push_back(*new Character("Vladimir Putin", 53)); //LIsto
    agentDeck.push_back(*new Character("Socrates", 31));
    agentDeck.push_back(*new Character("Mahatma Gandhi", 35));
    agentDeck.push_back(*new Character("Ernesto 'Che' Guevara", 7));
    agentDeck.push_back(*new Character("Eva Perón", 7));
    agentDeck.push_back(*new Character("Mario Vargas Llosa", 48));
    agentDeck.push_back(*new Character("Vincent Van Gogh", 33));
    
    agentDeck.push_back(*new Character("Nikola Tesla", 22));
    agentDeck.push_back(*new Character("Leonardo da Vinci", 36));
    agentDeck.push_back(*new Character("Malala Yousafzai", 47));
    agentDeck.push_back(*new Character("Mao ZeDong", 18));
    
    //Kim Jong Un - Corea del norte
    //Barack Obama E.U
    //Steve Jobs E.U
    //Margaret Thatcher - Inglaterra
    //Charlie Chaplin - Inglaterra Londres
    
    return agentDeck;
}

std::vector<Monument> LevelDeck::getGuruDeck()
{
   
    guruDeck.push_back(*new Monument("Estatua de la Libertad", 28));
    guruDeck.push_back(*new Monument("Torre Eiffel", 29));
    guruDeck.push_back(*new Monument("Cristo Redentor", 14));
    guruDeck.push_back(*new Monument("Big Ben", 51));
    guruDeck.push_back(*new Monument("Chichen-Itza", 42));
    guruDeck.push_back(*new Monument("Piramides de Giza", 25));
    guruDeck.push_back(*new Monument("Gran Esfinge", 25));
    guruDeck.push_back(*new Monument("Gran Muralla", 18));
    guruDeck.push_back(*new Monument("Taj Mahal", 35));
    guruDeck.push_back(*new Monument("Acropolis", 31));
    guruDeck.push_back(*new Monument("Coliseo", 36));
    
    guruDeck.push_back(*new Monument("Sagrada Familia", 27));
    guruDeck.push_back(*new Monument("Puerta de Brandenburgo", 4));
    guruDeck.push_back(*new Monument("Machu Picchu", 48));
   
    guruDeck.push_back(*new Monument("Palacio de Shönbrunn", 9));
    guruDeck.push_back(*new Monument("Monte Fuji", 38));
    guruDeck.push_back(*new Monument("Reichstag", 4));
    guruDeck.push_back(*new Monument("Stonehenge", 51));
    guruDeck.push_back(*new Monument("Puerta de Alcalá", 27));

    guruDeck.push_back(*new Monument("Torres Petronas", 41));
    guruDeck.push_back(*new Monument("Puerta Sur de Jerash", 39));

    return guruDeck;
}

