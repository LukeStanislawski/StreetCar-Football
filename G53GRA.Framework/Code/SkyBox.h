//
//  Car.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___SkyBox__
#define ___SkyBox__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"


class SkyBox:
    public DisplayableObject
//    public Input,
//    public Animation
{
public:
    SkyBox();
    ~SkyBox() {};
    void Display();
private:
    double radius = 1900;
    double height = 1200;
    float sHeight = -200;
    int faces = 40;
    int n_imgs = 1;
    
//    void HandleKey(unsigned char key, int state, int x, int y);
//    void HandleSpecialKey(int key, int state, int x, int y);
//    void Update(const double& deltaTime);
};

#endif
#include <stdio.h>
