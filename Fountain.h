//
//  Fountain.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 09/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___House__
#define ___House__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>

void fountain();
void inc_colour();

#endif
#include <stdio.h>
