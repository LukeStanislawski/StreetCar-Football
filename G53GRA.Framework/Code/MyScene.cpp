#include "MyScene.h"

#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <math.h>
#include "Car.h"
#include "DisplayableObject.h"
#include "Triangle.h"
#include "Terrain.h"
#include "Tree.h"
#include "Environment.h"
#include "SkyBox.h"


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
//    glClearColor(0.678, 0.921, 1.0, 1.f);
    
    car = new Car();
    car->position(0, -45, 0);
    AddObjectToScene(car);
    
    skybox = new SkyBox();
    AddObjectToScene(skybox);
    
    env = new Environment();
    AddObjectToScene(env);
    
    Terrain *t = new Terrain();
    AddObjectToScene(t);
    
    Tree *tree = new Tree();
    tree->position(300,-45,0);
    AddObjectToScene(tree);
    
//    setGlobalLight();
    
//    checkGLError();                 // Check any OpenGL errors in initialisation
//    glutReshapeFunc(reshape);
//    glutTimerFunc(10, timer, 0);

}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 2500.0);
    
//  Get Camera
    Camera *c = GetCamera();

//    Update coordinates of car in camera object
    float *car_pos = car->position();
    float *car_ornt = car->orientation();
    c->update_tracker(car_pos, car_ornt);
    
    float cpx, cpy, cpz;
    c->GetEyePosition(cpx, cpy, cpz);
    skybox->position(cpx, cpy, cpz);
    env->position(cpx, cpy, cpz);
    
    
// Update light
    
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
    float ambient[]  = { .2f, .2f, .2f, 1.f };      // ambient light (20% white)
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


void setSpotLight() {
    // Set lighting effect colours and positional parameter
//    float ambient[]  = { 1.f, 1.f, 1.f, 1.f };      // ambient light (20% white)
    float diffuse[]  = { 1.f, 1.f, 1.f, 1.f };      // diffuse light (50% white)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    float position[] = { 1.f, 1.f, 1.f, 0.f };      // directional light (w = 0)
    // Attach properties to single light source (GL_LIGHT0)
//    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT1, GL_POSITION, position);    // set direction vector of light source
    glEnable(GL_LIGHT1);    // enable light source with attached parameters (GL_LIGHT0)
    
    float dir[] = {1.f,0.f,1.f};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.f);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 22.5f);
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
