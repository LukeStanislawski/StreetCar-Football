//
//  Bridge.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Bridge.h"
#include "Shapes.h"


void bridge() {
//    glPushMatrix();
//    glScalef(0.1, 0.1, 0.1);
//    half_cylinder(20, 500, true);
//    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -90, 0);
    
    int planks = 47;
    for (float t = -30; t <= 30; t += 60.0 / planks)
    {
        glPushMatrix();
        glScalef(0.1, 0.1, 0.1);
        glRotatef(t, 0, 0, 1);
        glTranslatef(0, 900, 0);
        half_cylinder(20, 500, true);
        glPopMatrix();
    }
    
    glPopMatrix();
    
}
