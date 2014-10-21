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
    
    Country()
    {
    }
    
    Country(std::string nam, int code, std::string cap, std::string contCode)
    {
        name = nam;
        countryCode = code;
        capital = cap;
        continentCode = contCode;
    }
};

class World
{
    
    public:
    Country worldCountries[60]=
    {
        
#pragma mark Countries A
        Country("Afganistán", 0, "Kabul", "WA"),
        Country("Albania", 1, "Tirana", "E"),
        Country("Andorra", 2, "Andorra la Vieja", "E"),
        Country("Angola", 3, "Luanda", "A"),
        Country("Alemania", 4, "Berlin", "E"),
        Country("Arabia Saudita", 5, "Riad", "WA"),
        Country("Argelia", 6, "Argel", "A"),
        Country("Argentina", 7, "Buenos Aires", "SA"),
        Country("Australia", 8, "Canberra", "O"),
        Country("Austria", 9, "Vienna", "E"),
        
#pragma mark Countries B
        Country("Bélgica", 4, "Bruselas", "E"),
        Country("Belice", 5, "Belmopán", "CA"),
        Country("Bielorrusia", 6, "Minsk", "E"),
        Country("Bolivia", 7, "La Paz", "SA"),
        Country("Brasil", 8, "Brasilia", "SA"),
        Country("Bulgaria", 9, "Sofía", "E"),
        
        
#pragma mark Countries C
        Country("Canada", 10, "Ottawa", "NA"),
        Country("Chile", 11, "Santiago de Chile", "SA"),
        Country("China", 12, "Beijing", "EA"),
        Country("Colombia", 13, "Bogotá", "SA"),
        Country("Corea del Sur", 14, "Seúl", "EA"),
        Country("Costa Rica", 15, "San José", "CA"),
        Country("Croacia", 16, "Zagreb", "E"),
        Country("Cuba", 17, "La Habana", "CN"),
        
#pragma mark Countries D
        Country("Dinamarca", 18, "Copenhague", "E"),
        
#pragma mark Countries E
        Country("Egipto", 19, "Cairo", "WA"),
        Country("Emiratos Árabes Unidos", 20, "Abu Dabi", "WA"),
        Country("España", 21, "Madrid", "E"),
        Country("Estados Unidos", 22, "Washington D.C.", "NA"),
        
#pragma mark Countries F
        Country("Francia", 23, "Paris", "E"),
        Country("Finlandia", 24, "Helsinki", "NE"),
        
#pragma mark Countries G
        Country("Grecia", 25, "Atenas", "E"),
        Country("Guatemala", 26, "Guatemala", "CA"),
        
#pragma mark Countries H
        Country("Holanda", 27, "Amsterdam", "E"),
        Country("Hungría", 28, "Budapest", "E"),
        
#pragma mark Countries I
        Country("India", 29, "Nueva Delhi", "SAS"),
        Country("Italia", 30, "Roma", "E"),
        Country("Irlanda", 31, "Dublin", "E"),
        
#pragma mark Countries J
        Country("Japón", 32, "Tokio", "WA"),
        Country("Jordanía", 33, "Amán", "WA"),
        
#pragma mark Countries L
        Country("Líbano", 34, "Beirut", "EA"),
        
#pragma mark Countries M
        Country("Malasia", 35, "Kuala Lumpur", "EA"),
        Country("Mexico", 36, "Ciudad de México", "NA"),
        Country("Marruecos", 37, "Rabat", "A"),
        Country("Mongolia", 38, "Ulán Bator", "NAS"),
        
        
#pragma mark Countries N
        Country("Noruega", 39, "Oslo", "NE"),
        
#pragma mark Countries P
        Country("Panamá", 40, "Panamá", "CA"),
        Country("Perú", 41, "Lima", "SA"),
        Country("Portugal", 42, "Lisboa", "E"),
        Country("Polonia", 43, "Varsovia", "E"),
        
#pragma mark Countries R
        Country("Reino Unido", 44, "Londres", "E"),
        Country("República Checa", 45, "Praga", "E"),
        Country("Rusia", 7, "Moscú", "NAS"),
        
#pragma mark Countries S
        Country("Sudáfrica", 46, "Pretoria", "AF"),
        Country("Suiza", 47, "Berna", "E"),
        
#pragma mark Countries T
        Country("Turquía", 48, "Ankara", "WA"),
        
#pragma mark Countries U
        Country("Uruguay", 49, "Montevideo", "SA"),
        
#pragma mark Countries V
        Country("Venezuela", 50, "Caracas", "SA"),
        
    };
    void drawWorld();

};

#endif /* defined(__HeyWorld__World__) */
