//
//  World.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 13/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "World.h"


World::World()
{
    _america.push_back(Country("Canada", 16, "Ottawa", AMERICA, -0.22, 0.31, -0.64, -0.582, 0.45, 0.54));
    _america.push_back(Country("Mexico", 42, "Ciudad de México", AMERICA, -0.22, 0.0, -.64, -0.582, -0.05333, .036));
    _america.push_back(Country("Estados Unidos", 28, "Washington D.C.", AMERICA, -0.29, 0.15, -.708, -.65, .18, .28 ));
    _america.push_back(Country("Colombia", 19, "Bogotá", AMERICA, 0.04, -0.09, -.39,  -.34, -.1966, -0.11 ));
    _america.push_back(Country("Venezuela", 58, "Caracas", AMERICA, 0.13, -0.1, -.302,  -.25, -0.2066, -.1233 ));
    _america.push_back(Country("Cuba", 23, "La Habana", AMERICA, 0, .010, -.428,  -.376, -0.0233, 0.06666 ));
    _america.push_back(Country("Perú", 48, "Lima", AMERICA, 0.02, -0.2, -.41,  -.35, -0.37333, -0.276667 ));
    _america.push_back(Country("Brasil", 14, "Brasilia", AMERICA, 0.3, -0.25, -.14,  -.08, -0.46, -0.363333 ));
    _america.push_back(Country("Argentina", 7, "Buenos Aires", AMERICA, 0.13, -0.36, -.304,  -.244, -0.636667, -0.54 ));
    _america.push_back(Country("Chile", 17, "Santiago de Chile", AMERICA, 0.07, -0.36, -0.356,  -0.318, -0.63, -0.5266 ));
    _america.push_back(Country("Ecuador", 64, "Quito", AMERICA, 0.0, -0.16, -.428,  -.376, -0.2933, -0.22 ));
    
    _africa.push_back(Country("Angola", 3, "Luanda", AFRICA, 0,-0.24,-0.426,-0.372,-0.446,-0.343));
    _africa.push_back(Country("Argelia", 6, "Argel", AFRICA, -0.15,0.28,-0.576,-0.512,0.3933,0.493));
    _africa.push_back(Country("Egipto", 25, "Cairo", AFRICA, 0.14,0.32,-0.292,-0.24,0.46333,0.5666));
    _africa.push_back(Country("Marruecos",  43, "Rabat", AFRICA, -0.3,0.39,-0.72,-0.66,0.57333,0.67));
    _africa.push_back(Country("Sudáfrica", 54, "Pretoria", AFRICA, 0.1,-0.45,-0.332,-0.276,-0.7866,-0.68));
    _africa.push_back(Country("Zambia", 59, "Lusaka", AFRICA, 0.15,-0.24,-0.286,-0.226,-0.4433,-0.3433));
    _africa.push_back(Country("Sudan", 60, "Jarthum", AFRICA, 0.14,0.18,-0.294,-0.234,0.23,0.34));
    _africa.push_back(Country("Congo", 61, "Brazzaville", AFRICA, 0.13,-0.12,-0.3,-0.246,-0.25,-0.153));
    _africa.push_back(Country("Ghana", 62, "Acra", AFRICA, -0.26,0.06,-0.676,-0.622,0.0433,0.13));
    _africa.push_back(Country("Nigeria", 63, "Abuya", AFRICA, -0.15,0.08,-0.57,-0.518,0.09,0.17667));
    
    _europa.push_back(Country("Francia", 29, "Paris", EUROPE, -0.25,-0.16,-0.674,-0.612,-0.31333,-0.216667));
    _europa.push_back(Country("España", 27, "Madrid", EUROPE, -0.37,-0.22,-0.792,-0.734,-0.4033,-0.31));
    _europa.push_back(Country("Alemania", 4, "Berlin", EUROPE , -0.14,-0.09,-0.568,-0.504,-0.196667,-0.09));
    _europa.push_back(Country("Portugal", 49, "Lisboa", EUROPE, -0.45,-0.22,-0.86,-0.81,-0.4,-0.3133));
    _europa.push_back( Country("Inglaterra", 51, "Londres", EUROPE, -0.28,0.05,-0.698,-0.644,0.02333,0.13333));
    _europa.push_back(Country("Italia", 36, "Roma", EUROPE , -0.11,-0.27,-0.534,-0.48,-0.4866,-0.396667));
    _europa.push_back(Country("Noruega", 45, "Oslo", EUROPE , -0.11,0.2,-0.542,-0.476,0.27333,0.37));
    _europa.push_back(Country("Finlandia", 30, "Helsinki", EUROPE , 0.07,0.25,-0.366,-0.304,0.343333,0.446667));
    
    //    Country("Polonia", 50, "Varsovia", EUROPE, 0,0,0,0,0,0),
    //    Country("Grecia", 31, "Atenas", EUROPE, 0,0,0,0,0,0),
    //    Country("Holanda", 33, "Amsterdam", EUROPE, 0,0,0,0,0,0),
    //    Country("Croacia", 22, "Zagreb", EUROPE, 0,0,0,0,0,0),
    
    _asia.push_back(Country("China", 18, "Beijing", ASIA,0.1,0.01,-0.334,-0.266,-0.05,0.0566667));
    _asia.push_back(Country("Mongolia", 44, "Ulán Bator", ASIA, 0.05, 0.1,-0.386,-0.324,0.113333,0.206667));
    _asia.push_back(Country("Rusia", 53, "Moscú", ASIA, -0.11,0.25,-0.546,-0.462,0.313333,0.466667));
    _asia.push_back(Country("Japón", 38, "Tokio", ASIA, 0.37,-0.01,-0.07,-0.01,-0.07,0.02));
    _asia.push_back(Country("India", 35, "Nueva Delhi", ASIA, -0.05,-0.15, -0.488,-0.418,-0.29,-0.18));
    _asia.push_back(Country("Arabia Saudita", 5, "Riad", ASIA, -0.3,-0.15,-0.726,-0.66,-0.293333,-0.19));
    _asia.push_back(Country("Pakistán", 47, "Islamabad", ASIA, -0.13,-0.06,-0.552,-0.498,-0.146667,-0.0533333));
    _asia.push_back(Country("Malasia", 41, "Kuala Lumpur", ASIA,0.14,-0.35,-0.296,-0.24,-0.62,-0.51));
    _asia.push_back(Country("Corea del Sur", 20, "Seúl", ASIA, 0.27,-0.01,-0.166,-0.116,-0.0633333,0.0366667));


};


/*std::string World::getName(int k)
 {
 return _america[k].name;
 }
 
 int World::getCode(int k)
 {
 return _america[k].countryCode;
 }
 
 std::string World::getCap(int k)
 {
 return _america[k].capital;
 }
 
 std::string World::getContCode(int k)
 {
 return _america[k].continentCode;
 }
 
 float World::getX(int k)
 {
 return _america[k].posX;
 }
 
 float World::getY(int k)
 {
 return _america[k].posY;
 }*/
