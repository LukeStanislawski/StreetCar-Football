//
//  Tree.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 06/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Tree.h"
#include "Shapes.h"


void tree() {
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glScalef(0.3, 0.3, 0.3);
    
    tree_rec(8);
    
    glPopMatrix();
}


void tree_rec(int depth) {
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
                tree_rec(depth - 1);
                glPopMatrix();
            }
        }
    }
}
