//
//  Image.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 27/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef HeyWorld_Image_h
#define HeyWorld_Image_h

#include <GLUT/glut.h>

class Image
{
private:
    GLuint texture;

public:
    GLuint LoadTexture (const char * filename, int width, int height ){
        
        //    GLuint texture;
        unsigned char * data;
        FILE * file;
        texture = 0;
        
        //The following code will read in our RAW file
        file = fopen( filename, "rb" );
        if ( file == NULL ) return 0;
        data = (unsigned char *)malloc( width * height * 3 );
        fread( data, width * height * 3, 1, file );
        fclose( file );
        
        glGenTextures( 1, &texture );
        glBindTexture( GL_TEXTURE_2D, texture );
        glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        
        // select modulate to mix texture with color for shading
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        
        // when texture area is small, bilinear filter the closest mipmap
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_NEAREST );
        // when texture area is large, bilinear filter the first mipmap
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        
        //    // the texture wraps over at the edges (repeat)
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        
        // build our texture mipmaps
        gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                          GL_RGB, GL_UNSIGNED_BYTE, data );
        
        free(data);
        
        return texture; //return whether it was successful
        
    }
    
    void FreeTexture( GLuint texture ){
        glDeleteTextures( 1, &texture );
    }
    
    void cube (int angle) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture
        
        glPushMatrix();
        glRotatef( angle, 0.0f, 0.0f, 1.0f );
        glBegin( GL_QUADS );
        glTexCoord2d(0.0,0.0); glVertex2d(-1.0,-1.0);
        glTexCoord2d(1.0,0.0); glVertex2d(+1.0,-1.0);
        glTexCoord2d(1.0,1.0); glVertex2d(+1.0,+1.0);
        glTexCoord2d(0.0,1.0); glVertex2d(-1.0,+1.0);
        glEnd();
        glPopMatrix();
        //glutSolidCube(2);
    }
};
#endif
