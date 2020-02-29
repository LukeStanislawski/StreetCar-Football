//
//  MyScene.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 28/02/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "MyScene.h"
#include <stdlib.h>

#include <algorithm>
#include <iterator>
#include <iostream>

int width  = 600;                                   // initialise global window variables
int height = 400;                                   // define in your header: int width, height;
int eyeX = 0, eyeY = 15, eyeZ = 60, lookAtX = 0, lookAtY = 0, lookAtZ = -20, upX = 0, upY = 1, upZ = 0;
int speed = 1;
int refreshmil = 250;



void draw_triangle(float triangle [3][3]) {
    glBegin(GL_TRIANGLES);
        glVertex3f(triangle[0][0], triangle[0][1], triangle[0][2]);
        glVertex3f(triangle[1][0], triangle[1][1], triangle[1][2]);
        glVertex3f(triangle[2][0], triangle[2][1], triangle[2][2]);
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
        draw_triangle(faces[i]);
    }
}


int** subdivide_triangle(float triangle [3][3]) {
    return 0;
}


void drawPerspective() {
    glBegin(GL_LINES);
        // x-axis
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        // y-axis
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        // z-axis
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
    glEnd();
    
    float mSize = 50.f;
    float mStep = 5.f;
    float mHeight = -2.5f;
 
    glBegin(GL_LINES);
        glColor3f(0.75f, 0.75f, 0.75f);
        // draw horizontal lines
        for(float i = -mSize; i <= mSize; i += mStep)
        {
            glVertex3f(-mSize, mHeight, i);
            glVertex3f(mSize, mHeight, i);
        }
        // draw deep lines
        for(float i = -mSize; i <= mSize; i += mStep)
        {
            glVertex3f(i, mHeight, -mSize);
            glVertex3f(i, mHeight, mSize);
        }
        glEnd();
}


void draw()
{
    glClearColor(1.f, 1.f, 1.f, 1.f);                   // set background colour
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
    glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
    glLoadIdentity();                                   // reset drawing
    glutKeyboardFunc(moveCamera);
    
    setCamera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, upX, upY, upZ);

    glTranslatef(0.f, 0.f, -100.f);                     // move drawing further back in the scene
    glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black
    
//    glutWireCube(10.f);                                 // draw outlined cube
    
    tetrahedon();
    drawPerspective();
    
    checkGLError();
    glutSwapBuffers();                                  // execute all commands, swap buffers
    glFlush();
}

void moveCamera(unsigned char key, int x, int y) {
    switch (key) {
        case 119: //W move camera forward
            lookAtZ--;
            eyeZ--;
            break;
        case 115: //S move camera back
            lookAtZ++;
            eyeZ++;
            break;
        case 97: //A move camera left
            lookAtX--;
            eyeX--;
            break;
        case 100: //D move camera right
            lookAtX++;
            eyeX++;
            break;
        case 113: //Q move camera down
            lookAtY--;
            eyeY--;
            break;
        case 101: //E move camera up
            lookAtY++;
            eyeY++;
            break;
        case 122: //tilt up
            lookAtY++;
            break;
        case 120: //tilt down
            lookAtY--;
            break;
        case 99:
            lookAtX--;
            break; //tilt left
        case 118:
            lookAtX++;
            break; //tilt right
        case 32: //press space bar to exit program
            exit(0);
            break;
    }
}

void setCamera(int eyeX, int eyeY, int eyeZ, int lookAtX, int lookAtY, int lookAtZ, int upX, int upY, int upZ) {
        gluLookAt(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, upX, upY, upZ);
}

void setup()
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);  // enable 3D rendering and double buffering
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);              // set window size
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My Scene");                   // create and show window (named MyScene)
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(refreshmil, timer, 0);
}

void reshape(int _width, int _height)
{
    // update global dimension variables
    width  = _width;
    height = _height;
    // calculate new aspect ratio
    GLdouble aspect = static_cast<GLdouble>(width) / static_cast<GLdouble>(height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     // reset matrix
    gluPerspective(45.0, aspect, 1, 1000);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW); // return matrix mode to modelling and viewing
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);          // Initialise GL environment
    setup();                        // Call additional initialisation commands
    glutDisplayFunc(draw);          // Register scene to render contents of draw() function
    checkGLError();                 // Check any OpenGL errors in initialisation
    glutReshapeFunc(reshape);
    glutTimerFunc(10, timer, 0);

    glutMainLoop();                 // Begin rendering sequence
    return 0;
}

void checkGLError()
{
    int e = 0;                      // Error count
    GLenum error = glGetError();    // Get first glError
    while (GL_NO_ERROR != error)    // Loop until no errors found
    {
        e++;
        printf("GL Error %i: %s\n", e, gluErrorString(error)); // Display error string
        error = glGetError();                                  // Get next glError
    }
}
