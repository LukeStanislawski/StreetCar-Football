//
//  Car.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Tree.h"
#include "Shapes.h"
#include <stdlib.h>
#include <iostream>


Tree::Tree() {
    Display();
}

void Tree::Display() {
    glPushMatrix();

    glTranslatef(pos[0], pos[1], pos[2]);

    // rotate the triangle by the given degrees
    glRotatef(rotation[0], 0.0f, 0.0f, 1.0f);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glRotatef(rotation[2], 1.0f, 0.0f, 0.0f);

    // scale the traingle
    glScalef(scale[0], scale[1], scale[2]);

    // disable culling (removal) of backface triangles so that when we look at
    // triangle to does not disappearthe back of the
    glDisable(GL_CULL_FACE);

    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
//    glTranslatef(0,15,0);
    glRotatef(-90,1,0,0);

    
    branch(8);
    

    glPopAttrib();
    glPopMatrix();

    // re-enable face culling for other objects in the scene
    glEnable(GL_CULL_FACE);

    // revert back to the matrix we had before we added the triangles transforms
    // in the scene are not effected by the triangles transformations so that
    // other objects
    glPopMatrix();
}


void Tree::branch(int depth) {
    cylinder(10, 80);
    
    if (depth > 1) {
        int branches = 4;
        
        for (int i=0; i<branches; i++) {
            if (i != 3 or depth < 3 or depth > 5) {     // trim some branches
                float theta = (360 / branches) * i;
                
                glPushMatrix();
                glRotatef(theta, 0, 0, 1);
                glTranslatef(5,0,75);
                glRotatef(30, 0, 1, 0);
                glScalef(0.7, 0.5, 0.7);
                branch(depth - 1);
                glPopMatrix();
            }
        }
    }
}
