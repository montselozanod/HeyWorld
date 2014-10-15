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

struct Country
{
    std::string name;
    int countryCode;
    std::string capital;
    
    Country(std::string nam, int code, std::string cap)
    {
        name = nam;
        countryCode = code;
        capital = cap;
    }
};

class World
{
    
    public:
    void drawWorld();
    

};

#endif /* defined(__HeyWorld__World__) */
