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
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    GLuint tex = Scene::GetTexture("/Users/lukestanislawski/Documents/xcode/Graphics Proj/G53GRA.Framework/Textures/grass.bmp");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    float emit[] = {1.f,1.f,1.f,1.f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emit);
    
    float y = -50;
    float sl = size / sections;
    for (int i=(-0.5 * sections); i < 0.5 * sections; i++) {
        for (int ii=(-0.5 * sections); ii < 0.5 * sections; ii++) {
            draw_section(i * sl, y, ii * sl);
        }
    }
    glPopAttrib();
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_CULL_FACE);
}


void Terrain::draw_section(float x, float y, float z) {
    float sl = size / sections;
    glNormal3f(0.f, 1.f, 0.f);
    glBegin(GL_POLYGON);
        glTexCoord2f(1.f,1.f);
        glVertex3f(x-sl, y, z-sl);       // P1
        glTexCoord2f(1.f,0.f);
        glVertex3f(x-sl, y, z+sl);       // P2
        glTexCoord2f(0.f,0.f);
        glVertex3f(x+sl, y, z+sl);       // P3
        glTexCoord2f(0.f,1.f);
        glVertex3f(x+sl, y, z-sl);       // P4
    glEnd();
}
