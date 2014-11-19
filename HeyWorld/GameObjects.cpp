//
//  GameObjects.cpp
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "GameObjects.h"
#include <math.h>

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
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    glPolygonMode( GL_BACK, GL_FILL );					// Back Face Is Solid
    glPolygonMode( GL_FRONT, GL_LINE );					// Front Face Is Made Of Lines
    
    for(int k=0; k<45; k++)
    {
        for(int z=0; z<45; z++)
        {
            points[k][z][0]=float((k/5.0f)-4.5f);
            points[k][z][1]=float((z/5.0f)-4.5f);
            points[k][z][2]=float(sin((((k/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
        }
    }
    
    int x, y;
    float float_x, float_y, float_xb, float_yb;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -12.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(zrot, 0.0f, 0.0f, 1.0f);
    
  
    glBegin(GL_QUADS);
    for(x = 0; x < 44; x ++)
    {
        for( y = 0; y < 44; y++ )
        {
            float_x = float(x)/44.0f;
            float_y = float(y)/44.0f;
            float_xb = float(x+1)/44.0f;
            float_yb = float(y+1)/44.0f;
            
            glTexCoord2f( float_x, float_y);
            glVertex3f( points[x][y][0], points[x][y][1], points[x][y][2] );
            
            glTexCoord2f( float_x, float_yb );
            glVertex3f( points[x][y+1][0], points[x][y+1][1], points[x][y+1][2] );
            
            glTexCoord2f( float_xb, float_yb );
            glVertex3f( points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2] );
            
            glTexCoord2f( float_xb, float_y );
            glVertex3f( points[x+1][y][0], points[x+1][y][1], points[x+1][y][2] );
        }
    }
    
    glEnd();
    
    if( wiggle== 2 )
    {
        for( y = 0; y < 45; y++ )
        {
            hold=points[0][y][2];
            for( x = 0; x < 44; x++)
            {
                points[x][y][2] = points[x+1][y][2];
            }
            points[44][y][2]=hold;
        }
        wiggle = 0;
    }
    
    wiggle++;
    
    //xrot+=0.3f;
    if(yrot >= 45 && dirRight)
    {
        yrot = 45;
        dirRight = false;
    }else if(yrot <= 0 && !dirRight)
    {
        yrot = 0;
        dirRight = true;
    }else if(dirRight)
    {
        yrot+= 0.2f;
    }else if(!dirRight)
    {
        yrot-=0.2f;
    }
    //yrot+=0.2f;
    
    //zrot+=0.4f;

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
    glVertex3f(-0.5, -0.5, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5, -0.5, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5, 0.5, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5, 0.5, 0);
    glEnd();
}
