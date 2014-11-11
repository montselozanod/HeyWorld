//
//  World.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 13/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//


#include <string.h>
#include "World.h"


World::World()
{

    _america.push_back(Country("Canada", 16, "Ottawa", "NA", -0.22, 0.31, -0.30, -0.23, 0.45, 0.54));
    _america.push_back(Country("Mexico", 42, "Ciudad de México", "NA", -0.22, 0.0, -0.30, -0.23, -0.05, 0.036));
    _america.push_back(Country("Estados Unidos", 28, "Washington D.C.", "NA", -0.29, 0.15, -0.385, -0.3125, 0.186667, 0.286667 ));
    _america.push_back(Country("Colombia", 19, "Bogotá", "SA", 0.04, -0.09, 0.015,  0.0825, -0.2, -0.10333 ));
    _america.push_back(Country("Venezuela", 58, "Caracas", "SA", 0.13, -0.1, 0.1275,  0.19, -0.2066, -0.1166 ));
    _america.push_back(Country("Cuba", 23, "La Habana", "CN", 0, .010, -0.0275,  0.035, -0.0233, 0.06666 ));
    _america.push_back(Country("Perú", 48, "Lima", "SA", 0.02, -0.2, -0.0125,  0.06, -0.37333, -0.276667 ));
    _america.push_back(Country("Brasil", 14, "Brasilia", "SA", 0.3, -0.25, 0.3275,  0.4025, -0.46, -0.363333 ));
    _america.push_back(Country("Argentina", 7, "Buenos Aires", "SA", 0.13, -0.36, 0.1225,  0.1925, -0.636667, -0.54 ));
    _america.push_back(Country("Bolivia", 13, "La Paz", "SA", 0.13, -0.24, 0.12,  0.1925, -0.44, -0.34333 ));

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