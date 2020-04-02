//
//  Car.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___Tree__
#define ___Tree__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>
#include "DisplayableObject.h"


class Tree:
    public DisplayableObject
{
public:
    Tree();
    ~Tree() {};
    void Display();

private:
    void branch(int depth);

};

#endif
#include <stdio.h>
