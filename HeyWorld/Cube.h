//
//  Cube.h
//  LightsBox
//
//  Created by Maria Montserrat Lozano on 15/11/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __LightsBox__Cube__
#define __LightsBox__Cube__
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
static int angleBox = 0;
static int angleTop = 90;
class Cube
{
private:
    static void animationBox(int v);
    static void openCube();
public:
    Cube();
    void drawCube();
    //void openCube();
    void closeCube();
    void rotateCube();
};
#endif /* defined(__LightsBox__Cube__) */
