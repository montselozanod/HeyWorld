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
    
    public:
    Menu(std::string name);
    void setName(std::string name);
    std::string getName();
    void drawMenu(int ancho, int alto, int x, int y);
};

#endif /* defined(__HeyWorld__MenuOption__) */
