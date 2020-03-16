//
//  Tree.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 06/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//
#ifndef ___Tree__
#define ___Tree__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include <cmath>
#include <string>

using namespace std;

string sequence = "f^<f-f^|f&f+|f-f";
float angle = 90.f;



class Tree : public DisplayableObject       // a Tree is a DisplayableObject
{
public:
    Tree();                                 // constructor
    ~Tree() { };                            // destructor
    void display();                         // overloaded virtual display function
private:
    void branch();                          // draw branch function
};
#endif
#include "Tree.h"

Tree::Tree()
{
}


void Tree::branch()
{
    float res = 0.1f*M_PI;                  // resolution (in radians: equivalent to 18 degrees)
    float r = 0.15f;                        // ratio of radius to height
    float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
    float t = 0.f;                          // initialise angle as 0
    float mat_colour[]                      // colour reflected by diffuse light
        = { 0.58f, 0.27f, 0.21f, 1.f };         // mid brown
    float mat_ambient[]                     // ambient colour
        = { 0.29f, 0.14f, 0.11f, 1.f };         // dark brown
    float mat_spec[]                        // specular colour
        = { 0.f, 0.f, 0.f, 1.f };               // no reflectance (black)
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance

    do
    {                                     // create branch with multiple QUADS
        glBegin(GL_QUADS);
            // Create first points (with normals)
            glNormal3f(x, 0.f, z);          // define a normal facing out from the centre (0,0,0)
            glVertex3f(x, 0.f, z);          // bottom (with normal (x,0,z))
            glVertex3f(x, 1.f, z);          // top (with normal (x,0,z))
            // Iterate around circle
            t += res;                       // add increment to angle
            x = r*cos(t);                   // move x and z around circle
            z = r*sin(t);
            // Close quad (with new vertex normals)
            glNormal3f(x, 0.f, z);          // define a new normal now that x,z have moved around
            glVertex3f(x, 1.f, z);          // top
            glVertex3f(x, 0.f, z);          // bottom
        glEnd();
    } while (t <= 2 * M_PI);                // full rotation around circle
    
    glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
    glutSolidSphere(r,5,5);                 // add a sphere to cap cylinders and create 'joints'
    glPopAttrib();                          // restore style attributes
}


void Tree::display()
{
    // Project from Object Space to World Space
    glTranslatef(pos[0], pos[1], pos[2]);            // Position
    glScalef(scale[0], scale[1], scale[2]);            // Scale
    glRotatef(rotation[1], 0.f, 1.f, 0.f);            // Set orientation (Y - roll)
    glRotatef(rotation[2], 0.f, 0.f, 1.f);            // Set orientation (Z - yaw)
    glRotatef(rotation[0], 1.f, 0.f, 0.f);            // Set orientation (X - pitch)
    
    char curr;
    
    for (unsigned int i = 0; i < sequence.size(); i++)
    {
        curr = sequence[i];             // for each char in sequence
        switch (curr){                  // check current char command
            case 'f':                   // draw branch, move forward
                branch();
                break;
            case '+':                   // yaw clockwise
                glRotatef(-angle, 0.f, 0.f, 1.f);
                break;
            case '-':                   // yaw counter-clockwise
                glRotatef(angle, 0.f, 0.f, 1.f);
                break;
            case '^':                   // pitch clockwise
                glRotatef(-angle, 1.f, 0.f, 0.f);
                break;
            case '&':                   // pitch counter-clockwise
                glRotatef(angle, 1.f, 0.f, 0.f);
                break;
            case '<':                   // roll clockwise
                glRotatef(-angle, 0.f, 1.f, 0.f);
                break;
            case '>':                   //roll counter-clockwise
                glRotatef(angle, 0.f, 1.f, 0.f);
                break;
            case '|':                   // roll upside-down
                glRotatef(180.f, 0.f, 1.f, 0.f);
                break;
        }
    }
}
