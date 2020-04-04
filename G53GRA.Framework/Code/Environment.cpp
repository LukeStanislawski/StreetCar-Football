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
    
}

void Environment::Update(const double& deltaTime) {
    prog += cycle_speed * static_cast<float>(deltaTime);
    
    while (prog >= 1.0) {
        prog = prog - 1.0;
    }
    
    float night[3] = {0.0, 0.0, 0.0};
    float redV[3] = {0.980, 0.466, 0.039};
    float blueV[3] = {0.678, 0.921, 1.0};
    
    if (prog >= 0 && prog < 0.2) {
        float mult = (prog - 0) * (1.0 / 0.2);
        glClearColor(mp(night[0],redV[0],mult), mp(night[1],redV[1],mult), mp(night[2],redV[2],mult), 1.f);
    } else if (prog >= 0.2 && prog < 0.5) {
        float mult = (prog - 0.2) * (1.0 / 0.3);
        glClearColor(mp(redV[0],blueV[0],mult), mp(redV[1],blueV[1],mult), mp(redV[2],blueV[2],mult), 1.f);
    } else if (prog >= 0.5 && prog < 0.8) {
        float mult = (prog - 0.5) * (1.0 / 0.3);
        glClearColor(mp(blueV[0],redV[0],mult), mp(blueV[1],redV[1],mult), mp(blueV[2],redV[2],mult), 1.f);
    } else if (prog >= 0.8 && prog < 1.0) {
        float mult = (prog - 0.8) * (1.0 / 0.2);
        glClearColor(mp(redV[0],night[0],mult), mp(redV[1],night[1],mult), mp(redV[2],night[2],mult), 1.f);
    }
    
}

float Environment::mp(float a, float b, float mult) {
    // 0 <= mult <= 1.0
    
    float dist = b - a;
    return a + (mult * dist);
    
}
