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
#include <math.h>


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
    glEnable(GL_CULL_FACE);

    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
//    glTranslatef(0,15,0);
    glRotatef(-90,1,0,0);

    
    branches(8);
    

    glPopAttrib();
    glPopMatrix();

    // re-enable face culling for other objects in the scene
    glEnable(GL_CULL_FACE);

    // revert back to the matrix we had before we added the triangles transforms
    // in the scene are not effected by the triangles transformations so that
    // other objects
    glPopMatrix();
}


void Tree::branches(int depth) {
    branch(10, 80);
    
    if (depth > 1) {
        for (int i=0; i<n_branches; i++) {
            if (i != 3 or depth < 3 or depth > 5) {     // trim some branches
                float theta = (360 / n_branches) * i;
                
                glPushMatrix();
                glRotatef(theta, 0, 0, 1);
                glTranslatef(5,0,75);
                glRotatef(30, 0, 1, 0);
                glScalef(0.7, 0.5, 0.7);
                branches(depth - 1);
                glPopMatrix();
            }
        }
    }
}


void Tree::branch(int edges, float length) {
    float r = 10.0;
    float z = 0.0;
//    int edges_per_tex = 2;
    
    GLuint tex = Scene::GetTexture("/Users/lukestanislawski/Documents/xcode/Graphics Proj/G53GRA.Framework/Textures/bark.bmp");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    glBegin(GL_QUAD_STRIP);
    float step = 360.0 / edges;
        for (int t = 0; t <= 360; t += step) {
            double theta_a = t * 3.1415926535897932384626433832795 / 180;
//            double theta_b = (t + step) * 3.1415926535897932384626433832795 / 180;
            
            float x_a = cos(theta_a) * r;
            float y_a = sin(theta_a) * r;
//            float x_b = cos(theta_b) * r;
//            float y_b = sin(theta_b) * r;
            
            glNormal3f(x_a, y_a, 0.f);
            
            glTexCoord2f(1.f, (2.0 * t / 360));
            glVertex3d(x_a, y_a, z + length);
            glTexCoord2f(0.f, (2.0 * t / 360));
            glVertex3d(x_a, y_a, z);
//            glTexCoord2f(0.f, 0.f);
//            glVertex3d(x_b, y_b, z + length);
//            glTexCoord2f(1.f, 0.f);
//            glVertex3d(x_b, y_b, z);
        }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
