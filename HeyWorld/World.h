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

Country worldCountries[]=
{
  
    #pragma mark Countries A
    Country("Alemania", 49, "Berlin", "E"),
    Country("Argentina", 32, "Buenos Aires", "SA"),
    Country("Australia", 61, "Canberra", "O"),
    Country("Austria", 43, "Vienna", "E"),
    
     #pragma mark Countries B
    Country("Bélgica", 32, "Bruselas", "E"),
    Country("Brasil", 55, "Brasilia", "SA"),
    
     #pragma mark Countries C
    Country("Canada", 1, "Ottawa", "NA"),
    Country("Chile", 56, "Santiago de Chile", "SA"),
    Country("China", 86, "Beijing", "EA"),
    Country("Colombia", 57, "Bogotá", "SA"),
    Country("Costa Rica", 506, "San José", "CA"),
    Country("Croacia", 385, "Zagreb", "E"),
    Country("Cuba", 53, "La Habana", "CN"),
    
     #pragma mark Countries D
    Country("Dinamarca", 45, "Copenhague", "E"),
    
     #pragma mark Countries E
    Country("Egipto", 20, "Cairo", "WA"),
    Country("España", 34, "Madrid", "E"),
    
     #pragma mark Countries F
    Country("Francia", 33, "Paris", "E"),
    Country("Finlandia", 358, "Helsinki", "NE"),
    
     #pragma mark Countries G
    Country("Grecia", 30, "Atenas", "E"),

     #pragma mark Countries H
    Country("Holanda", 31, "Amsterdam", "E"),
    
     #pragma mark Countries I
    Country("India", 91, "Nueva Delhi", "SAS"),
    Country("Italia", 39, "Roma", "E"),
    Country("Irlanda", 353, "Dublin", "E"),

     #pragma mark Countries J
    Country("Japón", 81, "Tokio", "WA"),
    
     #pragma mark Countries M
    Country("Malasia", 60, "Kuala Lumpur", "EA"),
    Country("Mexico", 52, "Ciudad de México", "NA"),
    
     #pragma mark Countries N
    Country("Noruega", 47, "Oslo", "NE"),
    
     #pragma mark Countries P
    Country("Panamá", 507, "Panamá", "CA"),
    Country("Perú", 51, "Lima", "SA"),
    Country("Portugal", 35, "Lisboa", "E"),
    Country("Polonia", 48, "Varsovia", "E"),
    
     #pragma mark Countries R
    Country("Reino Unido", 44, "Londres", "E"),
    Country("República Checa", 357, "Praga", "E"),
    Country("Rusia", 7, "Moscú", "NAS"),
    
     #pragma mark Countries S
    Country("Sudáfrica", 211, "Pretoria", "AF"),
    Country("Suiza", 41, "Berna", "E"),
    
     #pragma mark Countries T
    Country("Turquía", 90, "Ankara", "WA"),
    
     #pragma mark Countries U
    Country("United States", 0, "Washington D.C.", "NA"),
    Country("Uruguay", 598, "Montevideo", "SA"),
    
     #pragma mark Countries V
    Country("Venezuela", 58, "Caracas", "SA"),
    
};

class World
{
    
    public:
    void drawWorld();
    

};

#endif /* defined(__HeyWorld__World__) */
