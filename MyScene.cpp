//
//  MyScene.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 28/02/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "MyScene.h"
#include "SubDivTriangle.h"
#include "Shapes.h"
#include "Bridge.h"
#include "Tree.h"
#include "Fountain.h"
#include "Car.h"

#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <math.h>



int width  = 600;                                   // initialise global window variables
int height = 400;                                   // define in your header: int width, height;
int eyeX = 0, eyeY = 15, eyeZ = -0, lookAtX = 0, lookAtY = 12, lookAtZ = -20, upX = 0, upY = 1, upZ = 0;
int speed = 1;
int refreshmil = 250;



//void setup()
//{
//    width  = 600;                                       // initialise global window variables
//    height = 400;
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);      // enable 3D rendering and double buffering
//    glutInitWindowSize(width, height);                  // set window size
//    glutCreateWindow("My Scene");                       // create and show window (named MyScene)
//
//    Tree* tree;
//    tree = new Tree();                                  // create new Tree object pointer
//    objects["tree"] = tree;                             // add tree to map of strings to DisplayableObjects
////    reshape(width, height);                             // call reshape function to set perspective
//    setGlobalLight();
//}

//void draw()
//{
//    glClearColor(1.f, 1.f, 1.f, 1.f);                   // set white background colour
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
//    glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
//    glLoadIdentity();                                   // reset drawing
//
//    glTranslatef(0.f, -4.f, -10.f);                     // translate back and to the bottom of the screen
//    glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black
//
////    // for each pair in the objects map (in this case, one Tree called "tree")
////        // pair is type <string, DisplayableObject*> so must call on 'second' element
////    for (std::map <std::string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr)
////    {
////        itr->second->display();
////    }
//    checkGLError();
//    glutSwapBuffers();                                  // execute all commands, swap buffers
//}


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
        // draw depth lines
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
    glClear(GL_COLOR_BUFFER_BIT); // clear buffers
    glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
    glLoadIdentity();                                   // reset drawing
    glutKeyboardFunc(moveCamera);

//    glEnable(GL_CULL_FACE);                             // Enable face-culling
//    glFrontFace(GL_CCW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setCamera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, upX, upY, upZ);

    glTranslatef(0.f, 0.f, -100.f);                     // move drawing further back in the scene
    glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black

//    glutWireCube(10.f);                                 // draw outlined cube
    drawPerspective();

//    tetrahedon();
//    octahedron();
//    circle(30);
//    cylinder(20, 50);
//    half_cylinder(20, 50, true);
//    bridge();
//    tree();
//    cube();
//    fountain();
//    ring(20, 0.5);
//    vase(20, 10, 50, 0.01, 30, 10, 0);
    Car car_obj(0.5);
    
//    Tree t;
//    t.display();


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
            lookAtX--;
            break; //tilt left
        case 118:
            lookAtX++;
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

void setGlobalLight() {
    // Set lighting effect colours and positional parameter
    float ambient[]  = { .6f, .6f, .6f, 1.f };      // ambient light (20% white)
    float diffuse[]  = { .5f, .5f, .5f, 1.f };      // diffuse light (50% white)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    float position[] = { 1.f, .5f, 1.f, 0.f };      // directional light (w = 0)
    // Attach properties to single light source (GL_LIGHT0)
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, position);    // set direction vector of light source
    // Enable this lighting effects
    glEnable(GL_LIGHTING);  // enable scene lighting (required to enable a light source)
    glEnable(GL_LIGHT0);    // enable light source with attached parameters (GL_LIGHT0)
}

void setup()
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);  // enable 3D rendering and double buffering
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);              // set window size
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My Scene");                   // create and show window (named MyScene)
    setGlobalLight();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
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
