//
//  GameObjects.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "GameObjects.h"
#include <math.h>
#define VALMAY 45
#define VALMEN 44
#define VALMENDEC 44.0f
#define SIZE 8
#pragma mark Sprite

char* Sprite::getImgName()
{
    return imgPathName;
}

void Sprite::setImgName(char* name)
{
    imgPathName = name;
}

void Sprite::drawSprite()
{
    
}

GLfloat Sprite::getPosX()
{
    return x;
}

GLfloat Sprite::getPosY()
{
    return y;
}

void Sprite::changePosX(GLfloat posX)
{
    x = posX;
}

void Sprite::changePosY(GLfloat posY)
{
    y = posY;
}

#pragma mark MONUMENT
void Monument::setName(std::string nam)
{
    monumentName = nam;
}

std::string Monument::getName()
{
    return monumentName;
}

//override
void Monument::drawSprite()
{
    
}

//FLAG
#pragma mark FLAG

//override
void Flag::drawSprite()
{
 
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    glPolygonMode( GL_BACK, GL_FILL ); //cara solida
    glPolygonMode( GL_FRONT, GL_LINE ); //lineas enfrente
    
    for(int k=0; k<VALMAY; k++)
    {
        for(int z=0; z<VALMAY; z++)
        {
            points[k][z][0]=float((k/5.0f)-4.5f);
            points[k][z][1]=float((z/5.0f)-4.5f);
            points[k][z][2]=float(sin((((k/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
        }
    }
    
    int x, y;
    float float_x, float_y, float_xb, float_yb;
    
    glTranslatef(0.0f, 0.0f, -12.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(zrot, 0.0f, 0.0f, 1.0f);
    
  
    glBegin(GL_QUADS);
    for(x = 0; x < VALMEN; x ++)
    {
        for( y = 0; y < VALMEN; y++ )
        {
            float_x = float(x)/VALMENDEC;
            float_y = float(y)/VALMENDEC;
            float_xb = float(x+1)/VALMENDEC;
            float_yb = float(y+1)/VALMENDEC;
            
            glTexCoord2f( float_x, float_y);
            glVertex3f( points[x][y][0], points[x][y][1], points[x][y][2]+25);
            
            glTexCoord2f( float_x, float_yb );
            glVertex3f( points[x][y+1][0], points[x][y+1][1], points[x][y+1][2]+25);
            
            glTexCoord2f( float_xb, float_yb );
            glVertex3f( points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2]+25);
            
            glTexCoord2f( float_xb, float_y );
            glVertex3f( points[x+1][y][0], points[x+1][y][1], points[x+1][y][2]+25);
        }
    }
    
    glEnd();
    
    if( wiggle== 2 )
    {
        for( y = 0; y < VALMAY; y++ )
        {
            hold=points[0][y][2];
            for( x = 0; x < VALMEN; x++)
            {
                points[x][y][2] = points[x+1][y][2];
            }
            points[VALMAY][y][2]=hold;
        }
        wiggle = 0;
    }
    
    wiggle++;
    
    //xrot+=0.3f;
    //yrot+=0.2f;
    //zrot+=0.4f;
    if(yrot >= 10 && dirRight)
    {
        yrot = 10;
        dirRight = false;
    }else if(yrot <= -1 && !dirRight)
    {
        yrot = -1;
        dirRight = true;
    }else if(dirRight)
    {
        yrot+= 0.2f;
    }else if(!dirRight)
    {
        yrot-=0.2f;
    }
   

//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
//    glVertex3f(-0.5, -0.5, 0);
//    glTexCoord2f(1.0f, 0.0f);
//    glVertex3f(0.5, -0.5, 0);
//    glTexCoord2f(1.0f, 1.0f);
//    glVertex3f(0.5, 0.5, 0);
//    glTexCoord2f(0.0f, 1.0f);
//    glVertex3f(-0.5, 0.5, 0);
//    glEnd();
    
}


#pragma mark Character
//Character

//override
void Character::drawSprite()
{
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); //se pega la textura con
    glVertex3f(-SIZE, -SIZE, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(SIZE, -SIZE, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(SIZE, SIZE, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-SIZE, SIZE, 0);
    glEnd();
}
