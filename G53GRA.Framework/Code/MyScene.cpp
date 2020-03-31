#include "MyScene.h"

#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <math.h>
#include "Car.h"
#include "DisplayableObject.h"

#include "Triangle.h"

int width  = 600;                                   // initialise global window variables
int height = 400;
int refreshmil = 250;

int iter = 0;


MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
    glClearColor(1.f, 1.f, 1.f, 1.f);
    
    Car *car_obj = new Car();
    AddObjectToScene(car_obj);
    
    
//    checkGLError();                 // Check any OpenGL errors in initialisation
//    glutReshapeFunc(reshape);
//    glutTimerFunc(10, timer, 0);

}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}


//void draw() {
//    glClearColor(1.f, 1.f, 1.f, 1.f);                   // set background colour
//    glClear(GL_COLOR_BUFFER_BIT); // clear buffers
//    glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
//    glLoadIdentity();                                   // reset drawing
////    glutKeyboardFunc(moveCamera);
//
////    glEnable(GL_CULL_FACE);                             // Enable face-culling
////    glFrontFace(GL_CCW);
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
////    setCamera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, upX, upY, upZ);
//
//    glTranslatef(0.f, 0.f, -100.f);                     // move drawing further back in the scene
//    glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black
//
////    glutWireCube(10.f);                                 // draw outlined cube
//    drawPerspective();
//
////    Car car_obj;
////    AddObjectToScene(car_obj);
//
//    checkGLError();
//    glutSwapBuffers();                                  // execute all commands, swap buffers
//    glFlush();
////    std::cout << "draw " << iter++ << std::endl;
//}


//void setup()
//{
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);  // enable 3D rendering and double buffering
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(width, height);              // set window size
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("My Scene");                   // create and show window (named MyScene)
//    setGlobalLight();
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
//}

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


//void timer(int value) {
//    glutPostRedisplay();
//    glutTimerFunc(refreshmil, timer, 0);
//}

void reshape(int _width, int _height) {
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


void checkGLError() {
    int e = 0;                      // Error count
    GLenum error = glGetError();    // Get first glError
    while (GL_NO_ERROR != error)    // Loop until no errors found
    {
        e++;
        printf("GL Error %i: %s\n", e, gluErrorString(error)); // Display error string
        error = glGetError();                                  // Get next glError
    }
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
        // draw depth lines
        for(float i = -mSize; i <= mSize; i += mStep)
        {
            glVertex3f(i, mHeight, -mSize);
            glVertex3f(i, mHeight, mSize);
        }
    glEnd();
}
