//
//  Tree.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 06/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___Tree__
#define ___Tree__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

class Tree : public DisplayableObject       // a Tree is a DisplayableObject
{
public:
    Tree();                                 // constructor
    ~Tree() { };                            // destructor
    void display();                         // overloaded virtual display function
private:
    void branch();                          // draw branch function
};

#include <stdio.h>
#endif

//
