//
//  Terrain.hpp
//  G53GRA.Framework
//
//  Created by Luke Stanislawski on 29/03/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Terrain_h
#define Terrain_h

#include <stdio.h>
#include "DisplayableObject.h"

class Terrain:
    public DisplayableObject
{
public:
    Terrain();
    ~Terrain() {};
    void Display();

private:
    int sections = 20;
    float size = 1000;
    
    void draw_section(float x, float y, float z);
};

#endif /* Terrain_hpp */
