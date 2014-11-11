//
//  Pin.cpp
//  HeyWorld
//
//  Created by Ariana Cisneros on 04/11/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Pin.h"


Pin:: Pin(float xx, float yy)
{
    x = xx;
    y = yy;
}

// metodos modificadores
void Pin::setX(float xx)
{
    x=xx;
}
void Pin::setY(float yy)
{
    y=yy;
}


float Pin::getX()
{
    return x;
}

float Pin::getY()
{
    return y;
}






