//
//  Car.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "SkyBox.h"
#include "Shapes.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


SkyBox::SkyBox() {
    Display();
}

void SkyBox::Display() {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(pos[0], 0, pos[2]);
    
    GLuint tex = Scene::GetTexture("/Users/lukestanislawski/Documents/xcode/Graphics Proj/G53GRA.Framework/Textures/background.bmp");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    float mat_colour[] = { 1.f, 1.f, 1.f, 1.f };
    float mat_ambient[] = { 1.f, 1.f, 1.f, 1.f };
    float mat_spec[] = { 0.f, 0.f, 0.f, 1.f };
    
    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance
    
//    glDisable(GL_LIGHTING);
    
    glBegin(GL_QUAD_STRIP);
    for (int i=0; i<=faces; i++) {
        double theta = i * 360.0 / faces;
        double rtheta = theta * 3.1415926535897932384626433832795 / 180;
        float x = cos(rtheta) * radius;
        float z = sin(rtheta) * radius;
        glNormal3f(-x, 0, -z);
        glTexCoord2f((1.0 / faces) * i * n_imgs, 0.f);
        glVertex3d(x, sHeight, z);
        glTexCoord2f((1.0 / faces) * i * n_imgs, 1.f);
        glVertex3d(x, sHeight + height, z);
    }
    glEnd();
    
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glPopMatrix();
    glPopAttrib();
}
