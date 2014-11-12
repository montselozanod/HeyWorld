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
    _america.push_back(Country("Bolivia", 13, "La Paz", AMERICA, 0.13, -0.24, -.302,  -.246, -0.44, -0.34333 ));
    
    
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