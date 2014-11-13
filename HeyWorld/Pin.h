//
//  Pin.h
//  HeyWorld
//
//  Created by Ariana Cisneros on 04/11/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef HeyWorld_Pin_h
#define HeyWorld_Pin_h

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Pin
{
public:
    // Constructor
    Pin(float xx, float yy);
    
    // metodos modificadores
    void setX(float xx);
    void setY(float yy);
    
    // metodos de acceso
    float getX();
    float getY();

    
private:
    // Atributos
    float x, y;
};


#endif
