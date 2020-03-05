//
//  MyScene.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 28/02/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___MyScene__
#define ___MyScene__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>

void setup();
void draw();
int main(int argc, char **argv);
void checkGLError();                        // Prints any OpenGL errors to console
void moveCamera(unsigned char key, int x, int y);
void setCamera(int eyeX, int eyeY, int eyeZ, int lookAtX, int lookAtY, int lookAtZ, int upX, int upY, int upZ);


#endif
#include <stdio.h>
void setup();
void draw();
int main(int argc, char **argv);
void checkGLError(); // Prints any OpenGL errors to console
void moveCamera(unsigned char key, int x, int y);
void setCamera(int eyeX, int eyeY, int eyeZ, int lookAtX, int lookAtY, int lookAtZ, int upX, int upY, int upZ);

