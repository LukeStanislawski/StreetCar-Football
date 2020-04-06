//
//  Car.cpp
//  Graphics Proj
//
//  Created by Luke Stanislawski on 12/03/2020.
//  Copyright © 2020 Luke Stanislawski. All rights reserved.
//

#include "Environment.h"
#include "Shapes.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


Environment::Environment() {
    Display();
}

void Environment::Display() {
    sun();
    sky();
}

void Environment::Update(const double& deltaTime) {
    prog += cycle_speed * static_cast<float>(deltaTime);
    
    while (prog >= 1.0) {
        prog = prog - 1.0;
    }
}

float Environment::mp(float a, float b, float mult) {
    // 0 <= mult <= 1.0
    
    float dist = b - a;
    return a + (mult * dist);
    
}


void Environment::sun() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_CULL_FACE);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    
    double theta = (prog * 360 * 3.1415926535897932384626433832795 / 180) - 90;
    glTranslatef(sun_dist * cos(theta), sun_dist * sin(theta), 0);
    glColor3f(1, 0.960, 0.019);
    glRotatef(90,1,0,0);
    glRotatef(prog * 360, 0, 1, 0);
    glScalef(5,5,5);
    circle(20);
    
    glPopAttrib();
    
    sun_lighting();
    
    glEnable(GL_CULL_FACE);
    glPopMatrix();
}


void Environment::sun_lighting() {
    std::cout << prog << "\n";
    GLfloat position[] = {0, 0, 0, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    if (prog < 0.25 || prog > 0.75) {
        GLfloat ambience[] = {0.02f, 0.02f, 0.02f, 1.0f};
        GLfloat diffuse[] = {0.08f, 0.08f, 0.08f, 1.0f};
        GLfloat specular[] = {0.10f, 0.10f, 0.10f, 1.0f};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambience);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    } else {
        float range = (prog - 0.25) * 2;
        float mult = sin(M_PI * range);
        GLfloat ambience[] = {0.2f*mult, 0.2f*mult, 0.2f*mult, 1.0f};
        GLfloat diffuse[] = {0.8f*mult, 0.8f*mult, 0.8f*mult, 1.0f};
        GLfloat specular[] = {1.0f*mult, 1.0f*mult, 1.0f*mult, 1.0f};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambience);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    }
}

void Environment::sky() {
    float night[3] = {0.0, 0.0, 0.0};
    float redV[3] = {0.980, 0.466, 0.039};
    float blueV[3] = {0.678, 0.921, 1.0};
    
    if (prog >= 0 && prog < 0.25) {
        float mult = (prog - 0) * (1.0 / 0.25);
        glClearColor(mp(night[0],redV[0],mult), mp(night[1],redV[1],mult), mp(night[2],redV[2],mult), 1.f);
    } else if (prog >= 0.25 && prog < 0.5) {
        float mult = (prog - 0.25) * (1.0 / 0.25);
        glClearColor(mp(redV[0],blueV[0],mult), mp(redV[1],blueV[1],mult), mp(redV[2],blueV[2],mult), 1.f);
    } else if (prog >= 0.5 && prog < 0.8) {
        float mult = (prog - 0.5) * (1.0 / 0.25);
        glClearColor(mp(blueV[0],redV[0],mult), mp(blueV[1],redV[1],mult), mp(blueV[2],redV[2],mult), 1.f);
    } else if (prog >= 0.75 && prog < 1.0) {
        float mult = (prog - 0.75) * (1.0 / 0.25);
        glClearColor(mp(redV[0],night[0],mult), mp(redV[1],night[1],mult), mp(redV[2],night[2],mult), 1.f);
    }
}
