//
//  Terrain.cpp
//  G53GRA.Framework
//
//  Created by Luke Stanislawski on 29/03/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Terrain.h"
#include<iostream>

Terrain::Terrain() {
    Display();
}

void Terrain::Display() {
    glDisable(GL_CULL_FACE);
    
    GLuint tex = Scene::GetTexture("/Users/lukestanislawski/Documents/xcode/Graphics Proj/G53GRA.Framework/Textures/grass.bmp");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    float x = 500.0;
    float y = -50;
    float z = 500.0;
    glBegin(GL_POLYGON);
        glTexCoord2f(10.f,10.f);
        glVertex3f( x,  y, z);       // P1
        glTexCoord2f(0.f,10.f);
        glVertex3f( x, y, -z);       // P2
        glTexCoord2f(0.f,0.f);
        glVertex3f(-x, y, -z);       // P3
        glTexCoord2f(10.f,0.f);
        glVertex3f(-x,  y, z);       // P4
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_CULL_FACE);
}

