//
//  Environment.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//


#pragma once

#include <stdio.h>
#include "Light.h"
#include "Medium.h"
#include "Surface.h"

//#include "ofApp.h"

class Environment {
public:
    Environment();
    Environment(Light &light, Surface &surface, Medium &medium);
    void update();
    
    
    enum Type {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN};
    Type type;
    
    void draw();
    int getType();
    
    Medium * medium;
    Surface * surface;
    Light * light;
};