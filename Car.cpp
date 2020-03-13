//
//  Car.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Car.h"
#include "Shapes.h"


void car() {
    glPushMatrix();
    
    glTranslatef(0,15,0);
//    glRotatef(45,0,1,0);

    car_body();
    car_windscreen();
    car_wheels();
    car_roofbars();
    car_bumper();
    car_grill();
    car_headlights();

    glPopMatrix();
}

void car_headlights() {
    glPushMatrix();
    
    glRotatef(90,0,1,0);
    glTranslatef(10,4,-26);
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    car_headlight();
    glPopMatrix();
    
    glTranslatef(-20, 0, 0);
    glScalef(0.2,0.2,0.2);
    car_headlight();
    
    glPopMatrix();
}

void car_headlight() {
    glPushMatrix();
    car_colours(3);
    ring(20, 0.1);
    car_colours(5);
    glScalef(0.9,0.9,0.9);
    circle(20);
    glPopMatrix();
}

void car_grill() {
    glPushMatrix();
    glTranslatef(-25,6,0);
    glRotatef(90, 0,1,0);
    
    
    glPushMatrix();
    car_grill_bar();
    glTranslatef(0, -10, 0);
    car_grill_bar();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-4.5, -5, 0);
    glRotatef(90, 0, 0, 1);
    
    for (int i=0; i < 6; i++) {
        car_grill_bar();
        glTranslatef(0, -1.8, 0);
    }
    glPopMatrix();
    
    glPopMatrix();
}

void car_grill_bar() {
    glPushMatrix();
    glScalef(10,1,1);
    cube();
    glPopMatrix();
}

void car_bumper() {
    car_colours(1);
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0,-5,-25);
    glScalef(28,2,1);
    cube();
    
    glPopMatrix();
}

void car_roofbars() {
    car_colours(3);
    glPushMatrix();
    glTranslatef(-10,25,12);
    car_roofbar();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10,25,-12);
    car_roofbar();
    glPopMatrix();
}

void car_roofbar() {
    //Main bar
    glScalef(0.1,0.1,0.1);
    glRotatef(90,0,1,0);
    cylinder(20, 380);
    
    // First stump
    glPushMatrix();
    glTranslatef(0,0,50);
    glRotatef(90,1,0,0);
    cylinder(20,30);
    glPopMatrix();
    
    // Second stump
    glPushMatrix();
    glTranslatef(0,0,320);
    glRotatef(90,1,0,0);
    cylinder(20,30);
    glPopMatrix();
}

void car_wheels() {
    glPushMatrix();
    
    // Rear Left
    glTranslatef(16,-9,13);
    car_wheel();
    
    // Rear Right
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(0,0,26);
    car_wheel();
    glPopMatrix();
    
    // Front left
    glTranslatef(-32,0,0);
    car_wheel();
    
    // Front Right
    glRotatef(180,0,1,0);
    glTranslatef(0,0,26);
    car_wheel();

    glPopMatrix();
}

void car_wheel() {
    glPushMatrix();
    glScalef(0.8, 0.8, 0.8);
    car_colours(3);
    cylinder(20, 5);
    glTranslatef(0,0,5);
    ring(20, 0.3);
    
    car_colours(1);
    glScalef(0.7, 0.7, 0.7);
    circle(20);
    
    
    glPushMatrix();
    car_colours(4);
    int spokes = 4;
    for (int i=0; i < spokes; i++) {
        glRotatef(180.0 / spokes, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(1, 10, 0.1);
        glVertex3d(-1, 10, 0.1);
        glVertex3d(-1, -10, 0.1);
        glVertex3d(1, -10, 0.1);
        glEnd();
    }
    glPopMatrix();
    
    glPopMatrix();
}

void car_windscreen() {
    car_colours(1);
    glPushMatrix();
    glScalef(35,15,30);
    glRotatef(90,0,1,0);
    glRotatef(5,1,0,0);
    glTranslatef(0,0.96,0.09);
    square();
    glPopMatrix();
    
    
    // side windscreen 1
    car_colours(1);
    glPushMatrix();
    glTranslatef(-10,7.4,15);
    glScalef(2.7,15,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();
    
    // side windscreen 2
    glPushMatrix();
    glTranslatef(-10,7.4,-15);
    glScalef(2.7,15,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();
}


void car_body() {
    car_colours(0);
    glPushMatrix();
    glScalef(50,15,30);
    cube();
    car_colours(3);
    wire_cube();
    car_colours(0);
    glPopMatrix();

    glPushMatrix();
    glScalef(35,15,30);
    glTranslatef(0.22,1,0);
    cube();
    car_colours(3);
    wire_cube();
    car_colours(0);
    glPopMatrix();
}





void car_colours(int c) {
    if (c == 0) {
        // 0 - Green
        glColor3f(0,0.31,0);
    } else if (c == 1) {
        // 1 - Light grey
        glColor3f(0.83,0.83,0.83);
    } else if (c == 2) {
        // 2 - Light green
        glColor3f(0.5,0.83,0.4);
    } else if (c == 3) {
        // 3 - Black
        glColor3f(0,0,0);
   } else if (c == 4) {
        // 4 - Dark grey
        glColor3f(0.65,0.65,0.65);
   } else if (c == 5) {
          // 5 - Yellow
          glColor3f(0.8,0.8,0);
     }
}
