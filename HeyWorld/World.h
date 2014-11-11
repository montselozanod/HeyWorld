//
//  World.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 13/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__World__
#define __HeyWorld__World__

#include <iostream>
#include <vector>

/*continentCode
 America = 0
 Europa = 1
 África = 2
 Asia = 3
 Oceanía = 4
 Antártica = 5
 */


enum Continent
{
    AFRICA, //0
    AMERICA, //1
    ASIA, //2
    EUROPE, //3
    OCEANIA,
    
};

struct Country
{
    std::string name;
    int  countryCode;
    Continent continent;
    std::string capital;
    std::string continentCode;
    float posX;
    float posY;
    float rangoX1;
    float rangoX2;
    float rangoY1;
    float rangoY2;
    
    Country()
    {
    }
    
    Country(std::string nam, int code, std::string cap, Continent cont, float x, float y, float xx, float xx2, float yy, float yy2)
    {
        name = nam;
        countryCode = code;
        capital = cap;
        continent = cont;
        posX = x;
        posY = y;
        rangoX1 = xx;
        rangoX2 = xx2;
        rangoY1 = yy;
        rangoY2 = yy2;
    }
};

class World
{
    
    public:
    World();
    int cont;
    std::vector <Country> _america;
    std::vector <Country> _asia;
    Country worldCountries[60]=
    {
        
#pragma mark Countries A
        Country("Afganistán", 0, "Kabul", ASIA, 0,0,0,0,0,0),
        Country("Albania", 1, "Tirana", EUROPE, 0,0,0,0,0,0),
        Country("Andorra", 2, "Andorra la Vieja", EUROPE,0,0,0,0,0,0),
        Country("Angola", 3, "Luanda", AFRICA, 0,0,0,0,0,0),
        Country("Alemania", 4, "Berlin", EUROPE , 0,0,0,0,0,0),
        Country("Arabia Saudita", 5, "Riad", ASIA, 0,0,0,0,0,0),
        Country("Argelia", 6, "Argel", AFRICA, 0,0,0,0,0,0),
        Country("Argentina", 7, "Buenos Aires", AMERICA,0.13, -0.36, 0.1225,  0.1925, -0.636667, -0.54),
        Country("Australia", 8, "Canberra", OCEANIA, 0,0,0,0,0,0),
        Country("Austria", 9, "Vienna", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries B
        Country("Bélgica", 10, "Bruselas", EUROPE, 0,0,0,0,0,0),
        Country("Belice", 11, "Belmopán", AMERICA, 0,0,0,0,0,0),
        Country("Bielorrusia", 12, "Minsk", EUROPE, 0,0,0,0,0,0),
        Country("Bolivia", 13, "La Paz", AMERICA, 0.13, -0.24, 0.12,  0.1925, -0.44, -0.34333),
        Country("Brasil", 14, "Brasilia", AMERICA,  0.3, -0.25, 0.3275,  0.4025, -0.46, -0.363333),
        Country("Bulgaria", 15, "Sofía", EUROPE, 0,0,0,0,0,0),
        
        
#pragma mark Countries C
        Country("Canada", 16, "Ottawa", AMERICA,-0.22, 0.31, -0.30, -0.23, 0.45, 0.54),
        Country("Chile", 17, "Santiago de Chile", AMERICA, 0,0,0,0,0,0),
        Country("China", 18, "Beijing", ASIA, 0,0,0,0,0,0),
        Country("Colombia", 19, "Bogotá", AMERICA, 0.04, -0.09, 0.015,  0.0825, -0.2, -0.10333),
        Country("Corea del Sur", 20, "Seúl", ASIA, 0,0,0,0,0,0),
        Country("Costa Rica", 21, "San José", AMERICA, 0,0,0,0,0,0),
        Country("Croacia", 22, "Zagreb", EUROPE, 0,0,0,0,0,0),
        Country("Cuba", 23, "La Habana", AMERICA,0, .010, -0.0275,  0.035, -0.0233, 0.06666 ),
        
#pragma mark Countries D
        Country("Dinamarca", 24, "Copenhague", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries E
        Country("Egipto", 25, "Cairo", AFRICA, 0,0,0,0,0,0),
        Country("Emiratos Árabes Unidos", 26, "Abu Dabi", ASIA, 0,0,0,0,0,0),
        Country("España", 27, "Madrid", EUROPE, 0,0,0,0,0,0),
        Country("Estados Unidos", 28, "Washington D.C.", AMERICA,  -0.29, 0.15, -0.385, -0.3125, 0.186667, 0.286667),
        
#pragma mark Countries F
        Country("Francia", 29, "Paris", EUROPE, 0,0,0,0,0,0),
        Country("Finlandia", 30, "Helsinki", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries G
        Country("Grecia", 31, "Atenas", EUROPE, 0,0,0,0,0,0),
        Country("Guatemala", 32, "Guatemala", AMERICA, 0,0,0,0,0,0),
        
#pragma mark Countries H
        Country("Holanda", 33, "Amsterdam", EUROPE, 0,0,0,0,0,0),
        Country("Hungría", 34, "Budapest", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries I
        Country("India", 35, "Nueva Delhi", ASIA, 0,0,0,0,0,0),
        Country("Italia", 36, "Roma", EUROPE, 0,0,0,0,0,0),
        Country("Irlanda", 37, "Dublin", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries J
        Country("Japón", 38, "Tokio", ASIA, 0,0,0,0,0,0),
        Country("Jordanía", 39, "Amán", ASIA, 0,0,0,0,0,0),
        
#pragma mark Countries L
        Country("Líbano", 40, "Beirut", ASIA, 0,0,0,0,0,0),
        
#pragma mark Countries M
        Country("Malasia", 41, "Kuala Lumpur", ASIA, 0,0,0,0,0,0),
        Country("Mexico", 42, "Ciudad de México", AMERICA, -0.22, 0.0, -0.30, -0.23, -0.05, 0.036),
        Country("Marruecos", 43, "Rabat", AFRICA, 0,0,0,0,0,0),
        Country("Mongolia", 44, "Ulán Bator", ASIA, 0,0,0,0,0,0),
        
        
#pragma mark Countries N
        Country("Noruega", 45, "Oslo", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries P
        Country("Panamá", 46, "Panamá", AMERICA, 0,0,0,0,0,0),
        Country("Pakistán", 47, "Islamabad", ASIA, 0,0,0,0,0,0),
        Country("Perú", 48, "Lima",  AMERICA,  0.02, -0.2, -0.0125,  0.06, -0.37333, -0.276667),
        Country("Portugal", 49, "Lisboa", EUROPE, 0,0,0,0,0,0),
        Country("Polonia", 50, "Varsovia", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries R
        Country("Reino Unido", 51, "Londres", EUROPE, 0,0,0,0,0,0),
        Country("República Checa", 52, "Praga", EUROPE, 0,0,0,0,0,0),
        Country("Rusia", 53, "Moscú", ASIA, 0,0,0,0,0,0),
        
#pragma mark Countries S
        Country("Sudáfrica", 54, "Pretoria", AFRICA, 0,0,0,0,0,0),
        Country("Suiza", 55, "Berna", EUROPE, 0,0,0,0,0,0),
        
#pragma mark Countries T
        Country("Turquía", 56, "Ankara", AFRICA, 0,0,0,0,0,0),
        
#pragma mark Countries U
        Country("Uruguay", 57, "Montevideo", AMERICA, 0,0,0,0,0,0),
        
#pragma mark Countries V
        Country("Venezuela", 58, "Caracas", AMERICA ,0.13, -0.1, 0.1275,  0.19, -0.2066, -0.1166),
        
    };
    void drawWorld();

};

#endif /* defined(__HeyWorld__World__) */
