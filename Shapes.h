//
//  Shapes.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 05/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___Shapes__
#define ___Shapes__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

void tetrahedon();
void octahedron();
void circle(int edges);
void cylinder(int edges, float length);
void half_cylinder(int edges, float length, bool closed);

#include <stdio.h>
#endif

void tetrahedon();
void octahedron();
void circle(int edges);
void cylinder(int edges, float length);
void half_cylinder(int edges, float length, bool closed);
