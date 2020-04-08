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
    
    float mat_colour[] = { 0.109, 0.690, 0.133, 1.f };         // green
    float mat_ambient[] = { 0.109, 0.690, 0.133, 1.f };        // green
    float mat_spec[] = { 0.545, 0.976, 0.564, 1.f };           // lighter green
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance
    
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
