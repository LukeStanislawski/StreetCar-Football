//
//  Shapes.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Shapes.h"
#include "SubDivTriangle.h"
#include <math.h>


void circle(int edges) {
    float r = 10.0;
    float z = 0.0;
    
    glBegin(GL_LINE_LOOP);
        for (int t = 0; t < 360; t += 360 / edges)
        {
            double theta = t * 3.1415926535897932384626433832795 / 180;
            float x = cos(theta) * r;
            float y = sin(theta) * r;
            glVertex3d(x, y, z);
        }
    glEnd();
}


void square() {
    glBegin(GL_POLYGON);
        glVertex3d( -1.0, -1.0, -1.0);
        glVertex3d( -1.0,  1.0, -1.0);
        glVertex3d(  1.0,  1.0, -1.0);
        glVertex3d(  1.0, -1.0, -1.0);
    glEnd();
}


void cube() {
    glPushMatrix();
    square();
    glRotatef(90, 0, 1, 1);
    glPopMatrix();
}


void cylinder(int edges, float length) {
    float r = 10.0;
    float z = 0.0;
    
    glBegin(GL_QUAD_STRIP);
        for (int t = 0; t <= 360; t += 360 / edges)
        {
            double theta = t * 3.1415926535897932384626433832795 / 180;
            float x = cos(theta) * r;
            float y = sin(theta) * r;
            glVertex3d(x, y, z);
            glVertex3d(x, y, z + length);
        }
    glEnd();
}


void half_cylinder(int edges, float length, bool closed) {
    float r = 10.0;
    float z = 0.0;
    
    glBegin(GL_QUAD_STRIP);
        for (int t = 0; t <= 180; t += 180 / edges)
        {
            double theta = t * 3.1415926535897932384626433832795 / 180;
            float x = cos(theta) * r;
            float y = sin(theta) * r;
            glVertex3d(x, y, z);
            glVertex3d(x, y, z + length);
        }
    
        if (closed) {
            float x = cos(0) * r;
            float y = sin(0) * r;
            glVertex3d(x, y, z);
            glVertex3d(x, y, z + length);
        }
    glEnd();
}


void ring(int edges, float thickness) {
    float r = 10.0;
    float z = 0.0;
    
    glBegin(GL_QUAD_STRIP);
        for (int t = 0; t <= 360; t += 360 / edges)
        {
            double theta = t * 3.1415926535897932384626433832795 / 180;
            float x1 = cos(theta) * r;
            float y1 = sin(theta) * r;
            float x2 = cos(theta) * (r - (r * thickness));
            float y2 = sin(theta) * (r - (r * thickness));
            glVertex3d(x1, y1, z);
            glVertex3d(x2, y2, z);
            
        }
    glEnd();
}


void tetrahedon() {
//    int a [3] = {-1,-1,-1};
//    int b [3] = {1,1,-1};
//    int c [3] = {-1,1,1};
//    int d [3] = {1,-1,1};

    float faces [4][3][3] = {
        {{-10,-10,-10}, {10,10,-10}, {-10,10,10}},
        {{-10,-10,-10}, {10,10,-10},{10,-10,10}},
        {{-10,-10,-10}, {-10,10,10}, {10,-10,10}},
        {{10,10,-10}, {-10,10,10}, {10,-10,10}},
    };
    
    
    for (int i=0; i<4; i++) {
        glColor3f(i*0.2, 0.5, 0.5);
//        draw_triangle(faces[i]);]
        subdivide_triangle(faces[i], 1);
    }
}



void octahedron() {
    float faces [8][3][3] = {
        {{0,0,10}, {0,10,0}, {10,0,0}},
        {{10,0,0}, {0,10,0}, {0,0,-10}},
        {{0,0,-10}, {0,10,0}, {-10,0,0}},
        {{-10,0,0}, {0,10,0}, {0,0,10}},
        {{0,0,10}, {0,-10,0}, {10,0,0}},
        {{10,0,0}, {0,-10,0}, {0,0,-10}},
        {{0,0,-10}, {0,-10,0}, {-10,0,0}},
        {{-10,0,0}, {0,-10,0}, {0,0,10}},
    };
    
    
    for (int i=0; i<8; i++) {
        glColor3f(i*0.1, 1-(0.1*i), 0.5);
//        draw_triangle(faces[i]);
        subdivide_triangle(faces[i], 5);
    }
}


void vase(int slices, int rings, float height, float flex, float radius, float min_radius, float offset) {
    glPushMatrix();
    glRotatef(90,1,0,0);
    
    float ringsize = height / rings;
    for (int ri=offset - (ringsize * rings / 2.0); ri <= offset + (ringsize * rings / 2.0); ri += ringsize) {
        float r1 = min_radius + flex * ri * ri;
        float r2 = min_radius + flex * (ri + ringsize) * (ri + ringsize);
        
        glBegin(GL_QUAD_STRIP);
        for (int t = 0; t <= 360; t += 360 / slices) {
            double theta = t * 3.1415926535897932384626433832795 / 180;
            float x1 = cos(theta) * r1;
            float y1 = sin(theta) * r1;
            float x2 = cos(theta) * r2;
            float y2 = sin(theta) * r2;
            glVertex3d(x1, y1, ri);
            glVertex3d(x2, y2, ri + ringsize);
        }
        glEnd();
    }
    glPopMatrix();
}
