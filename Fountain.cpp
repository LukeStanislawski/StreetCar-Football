//
//  Fountain.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 09/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Fountain.h"
#include "Shapes.h"

#include <math.h>


float inc_colour(float xc) {
    xc += 0.13; // Must be < 1
    if (xc > 1) {
        xc = xc - 1;
    }
    
    glColor3f(xc, 0.75f, 0.75f);
    return xc;
}


void fountain() {
    float xc = 0.75;
    glPushMatrix();
    
    glRotatef(90,1,0,0);
    glScalef(4,4,4);
    cylinder(20, 2);
    xc = inc_colour(xc);
    
//    Draw decorations around outside
    int decorations = 8;
    for (int t = 0; t < 360; t += 360 / decorations) {
        glPushMatrix();
        double theta = t * 3.1415926535897932384626433832795 / 180;
        glTranslatef(10.01 * cos(theta), 10.01 * sin(theta), 1);
        glRotatef(t, 0,0,1);
        glScalef(0, 0.5, 0.8);
        glBegin(GL_QUADS);
            glVertex3d(0, 0, 1);
            glVertex3d(0, 1, 0);
            glVertex3d(0, 0, -1);
            glVertex3d(0, -1, 0);
        glEnd();
        xc = inc_colour(xc);
        glPopMatrix();
    }
    
    
    glPushMatrix();
//    glTranslatef(0,0,-0.2);
    glScalef(1.05,1.05,0);
    ring(20, 0.1);
    glPopMatrix();
    
    
    glPopMatrix();
}


void decorations() {
    
}
