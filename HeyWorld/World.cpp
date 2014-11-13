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

    
   // _africa.push_back(Country("China", 18, "Beijing",AFRICA,0.13, -0.24, -.302,  -.246, -0.44, -0.34333));
    // _asia.push_back(Country("China", 18, "Beijing", "EA",0.0,0.0));
    // _asia.push_back(Country("Mongolia", 44, "Ulán Bator", "NAS", 0.0, 0.0));
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
