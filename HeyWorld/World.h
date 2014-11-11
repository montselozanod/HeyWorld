//
//  World.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 13/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__World__
#define __HeyWorld__World__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <vector>
#include <list>


/*continentCode
 NA = North America
 CN = Caribbean Nations
 CA = Central America
 SA = South America
 E = Europe
 NE = North Europe
 A = Africa
 O = Oceania
 EA = East Asia
 WA = West Asia
 SAS = South Asia
 NAS = North ASia
 AF = Africa
 */





struct Country
{
    std::string name;
    int  countryCode;
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
    
    Country(std::string nam, int code, std::string cap, std::string contCode, float x, float y, float xx, float xx2, float yy, float yy2)
    {
        name = nam;
        countryCode = code;
        capital = cap;
        continentCode = contCode;
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
    // Constructor
    World();
    int cont;
    /*std::string getName(int k);
    int getCode(int k);
    std::string getCap(int k);
    std::string getContCode(int k);
    float getX(int k);
    float getY(int k);*/
    std::vector <Country> _america;
    std::vector <Country> _asia;
    Country worldCountries[2]=
    {
        
#pragma mark Countries A
     /*   Country("Afganistán", 0, "Kabul", "WA"),
        Country("Albania", 1, "Tirana", "E"),
        Country("Andorra", 2, "Andorra la Vieja", "E"),
        Country("Angola", 3, "Luanda", "A"),
        Country("Alemania", 4, "Berlin", "E"),
        Country("Arabia Saudita", 5, "Riad", "WA"),
        Country("Argelia", 6, "Argel", "A"),
        Country("Argentina", 7, "Buenos Aires", "SA"),
        Country("Australia", 8, "Canberra", "O"),
        Country("Austria", 9, "Vienna", "E"),*/
        
#pragma mark Countries B
       /* Country("Bélgica", 10, "Bruselas", "E"),
        Country("Belice", 11, "Belmopán", "CA"),
        Country("Bielorrusia", 12, "Minsk", "E"),
        Country("Bolivia", 13, "La Paz", "SA"),
        Country("Brasil", 14, "Brasilia", "SA"),
        Country("Bulgaria", 15, "Sofía", "E"),*/
        
        
#pragma mark Countries C
      //  Country("Canada", 16, "Ottawa", "NA", -1.40, 0.60),
        /*Country("Chile", 17, "Santiago de Chile", "SA"),
        Country("China", 18, "Beijing", "EA"),
        Country("Colombia", 19, "Bogotá", "SA"),
        Country("Corea del Sur", 20, "Seúl", "EA"),
        Country("Costa Rica", 21, "San José", "CA"),
        Country("Croacia", 22, "Zagreb", "E"),
        Country("Cuba", 23, "La Habana", "CN"),*/
        
#pragma mark Countries D
        /*Country("Dinamarca", 24, "Copenhague", "E"),
        
#pragma mark Countries E
        Country("Egipto", 25, "Cairo", "WA"),
        Country("Emiratos Árabes Unidos", 26, "Abu Dabi", "WA"),
        Country("España", 27, "Madrid", "E"),
        Country("Estados Unidos", 28, "Washington D.C.", "NA"),
        
#pragma mark Countries F
        Country("Francia", 29, "Paris", "E"),
        Country("Finlandia", 30, "Helsinki", "NE"),
        
#pragma mark Countries G
        Country("Grecia", 31, "Atenas", "E"),
        Country("Guatemala", 32, "Guatemala", "CA"),
        
#pragma mark Countries H
        Country("Holanda", 33, "Amsterdam", "E"),
        Country("Hungría", 34, "Budapest", "E"),
        
#pragma mark Countries I
        Country("India", 35, "Nueva Delhi", "SAS"),
        Country("Italia", 36, "Roma", "E"),
        Country("Irlanda", 37, "Dublin", "E"),
        
#pragma mark Countries J
        Country("Japón", 38, "Tokio", "WA"),
        Country("Jordanía", 39, "Amán", "WA"),
        
#pragma mark Countries L
        Country("Líbano", 40, "Beirut", "EA"),
        
#pragma mark Countries M
        Country("Malasia", 41, "Kuala Lumpur", "EA"),*/
 //       Country("Mexico", 42, "Ciudad de México", "NA", -1.55, 0.16),
      /*  Country("Marruecos", 43, "Rabat", "A"),
        Country("Mongolia", 44, "Ulán Bator", "NAS"),
        
        
#pragma mark Countries N
        Country("Noruega", 45, "Oslo", "NE"),
        
#pragma mark Countries P
        Country("Panamá", 46, "Panamá", "CA"),
        Country("Pakistán", 47, "Islamabad", "WA"),
        Country("Perú", 48, "Lima", "SA"),
        Country("Portugal", 49, "Lisboa", "E"),
        Country("Polonia", 50, "Varsovia", "E"),
        
#pragma mark Countries R
        Country("Reino Unido", 51, "Londres", "E"),
        Country("República Checa", 52, "Praga", "E"),
        Country("Rusia", 53, "Moscú", "NAS"),
        
#pragma mark Countries S
        Country("Sudáfrica", 54, "Pretoria", "AF"),
        Country("Suiza", 55, "Berna", "E"),
        
#pragma mark Countries T
        Country("Turquía", 56, "Ankara", "WA"),
        
#pragma mark Countries U
        Country("Uruguay", 57, "Montevideo", "SA"),
        
#pragma mark Countries V
        Country("Venezuela", 58, "Caracas", "SA"),*/
        
    };
    void drawWorld();

};

#endif /* defined(__HeyWorld__World__) */
