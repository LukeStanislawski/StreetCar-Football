//
//  Shapes.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Shapes.h"
#include "SubDivTriangle.h"


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
