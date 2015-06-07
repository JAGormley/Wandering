//
//  Environment.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//


#pragma once
#ifndef __Wandering2__Environment__
#define __Wandering2__Environment__

#include <stdio.h>
#include "Light.h"
#include "Medium.h"
#include "Surface.h"

#endif /* defined(__Wandering2__Environment__) */

//#include "ofApp.h"

class Environment {
public:
    Environment();
    Environment(Light light, Surface &surface, Medium &medium);
    
    enum Type {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN};
    Type type;
    
    void draw();
    int getType();
    
    Medium * medium;
    Surface * surface;
    Light light;
};