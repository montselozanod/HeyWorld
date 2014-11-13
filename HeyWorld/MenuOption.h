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
    bool selected;
    
    double x;
    double y;
    double z;
    
    double width;
    double height;
    double volume;
    void draw3dString (int type,float x, float y, float z);
    void renderBitmapString(std::string name, float x,float y,float z);
    
    public:

    Menu(std::string, double x, double y, double dimX, double dimY, double zPos);
    Menu();
    
    void setPosition(double x,double y ,double z);
    void setDimensions(double w,double h,double v);
    void setSelected(bool s);
    bool getSelected();
    
    void drawMenu(int type);

};

#endif /* defined(__HeyWorld__MenuOption__) */
