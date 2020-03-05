//
//  SubDivTriangle.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___SubDivTriangle__
#define ___SubDivTriangle__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

void draw_triangle(float triangle [3][3]);
void subdivide_triangle(float triangle [3][3], int divs);

#include <stdio.h>
#endif


void draw_triangle(float triangle [3][3]);
void subdivide_triangle(float triangle [3][3], int divs);
