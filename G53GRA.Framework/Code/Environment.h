//
//  Car.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___Environment__
#define ___Environment__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"


class Environment:
    public DisplayableObject,
    public Input,
    public Animation
{
public:
    Environment();
    ~Environment() {};
    void Display();

private:
    float prog = 0.0;
    float cycle_speed = 0.1;
    float sun_dist = 900;
    float sun_radius = 50;
    
//    void HandleKey(unsigned char key, int state, int x, int y);
//    void HandleSpecialKey(int key, int state, int x, int y);
    void Update(const double& deltaTime);
    float mp(float a, float b, float prog);
    void sun();
    void sky();
    void sun_lighting();
};

#endif
#include <stdio.h>
