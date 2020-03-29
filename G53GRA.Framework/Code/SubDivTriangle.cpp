//
//  SubDivTriangle.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "SubDivTriangle.h"
#include <math.h>
//#include "MyScene.cpp"


void draw_triangle(float triangle [3][3]) {
    glBegin(GL_TRIANGLES);
        glVertex3f(triangle[0][0], triangle[0][1], triangle[0][2]);
        glVertex3f(triangle[1][0], triangle[1][1], triangle[1][2]);
        glVertex3f(triangle[2][0], triangle[2][1], triangle[2][2]);
    glEnd();
}


void subdivide_triangle(float triangle [3][3], int divs) {
    if (divs == 0) {
        draw_triangle(triangle);
    } else {
        float r = sqrt(pow(triangle[0][0], 2) + pow(triangle[0][1], 2) + pow(triangle[0][2], 2));
        
        float mid1[3] = { (triangle[0][0] + triangle[1][0])/2, (triangle[0][1] + triangle[1][1])/2, (triangle[0][2] + triangle[1][2])/2};
        float mid2[3] = { (triangle[0][0] + triangle[2][0])/2, (triangle[0][1] + triangle[2][1])/2, (triangle[0][2] + triangle[2][2])/2};
        float mid3[3] = { (triangle[1][0] + triangle[2][0])/2, (triangle[1][1] + triangle[2][1])/2, (triangle[1][2] + triangle[2][2])/2};
        
        float nr;
        for (int i=0; i<3; i++) {
            nr = sqrt(pow(mid1[0], 2) + pow(mid1[1], 2) + pow(mid1[2], 2));
            mid1[i] = mid1[i] * (r / nr);

            nr = sqrt(pow(mid2[0], 2) + pow(mid2[1], 2) + pow(mid2[2], 2));
            mid2[i] = mid2[i] * (r / nr);

            nr = sqrt(pow(mid3[0], 2) + pow(mid3[1], 2) + pow(mid3[2], 2));
            mid3[i] = mid3[i] * (r / nr);
        }
        
        float a [3][3] = {{mid1[0], mid1[1], mid1[2]}, {mid2[0], mid2[1], mid2[2]}, {mid3[0], mid3[1], mid3[2]}};
        subdivide_triangle(a, divs - 1);
        float b [3][3] = {{mid1[0], mid1[1], mid1[2]}, {mid2[0], mid2[1], mid2[2]}, {triangle[0][0], triangle[0][1], triangle[0][2]}};
        subdivide_triangle(b, divs - 1);
        float c [3][3] = {{mid1[0], mid1[1], mid1[2]}, {mid3[0], mid3[1], mid3[2]}, {triangle[1][0], triangle[1][1], triangle[1][2]}};
        subdivide_triangle(c, divs - 1);
        float d [3][3] = {{mid2[0], mid2[1], mid2[2]}, {mid3[0], mid3[1], mid3[2]}, {triangle[2][0], triangle[2][1], triangle[2][2]}};
        subdivide_triangle(d, divs - 1);
    }
    
}
