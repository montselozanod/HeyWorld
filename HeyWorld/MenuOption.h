//
//  MenuOption.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 24/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__MenuOption__
#define __HeyWorld__MenuOption__

#include <iostream>
#include <string>
class Menu{
    private:
    std::string name;
    void draw3dString (float x, float y, float z);
    
    public:
    Menu(std::string name);
    void setName(std::string name);
    std::string getName();
    void drawMenu(float ancho, float alto, float x, float y, bool selected);
};

#endif /* defined(__HeyWorld__MenuOption__) */
