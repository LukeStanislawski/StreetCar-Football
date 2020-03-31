//
//  Car.hpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#ifndef ___Car__
#define ___Car__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"


class Car:
    public DisplayableObject,
    public Input,
    public Animation
{
public:
    Car();
    ~Car() {};
    void Display();

private:
    float wheele_rot = 0.0;
    
    void car_windscreen();
    void car_body();
    void car_wheel();
    void car_wheels();
    void car_roofbar();
    void car_roofbars();
    void car_bumper();
    void car_grill();
    void car_grill_bar();
    void car_headlight();
    void car_headlights();
    
    void car_colours(int c);
    
    void HandleKey(unsigned char key, int state, int x, int y);
    void Update(const double& deltaTime);
};

//void car_body(float length, float height, float depth);

#endif
#include <stdio.h>
