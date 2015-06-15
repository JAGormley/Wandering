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
    ~Environment();
    Environment(Surface &surface, Medium &medium);
    void update();
    vector<ofVec3f> getSurfaceVerts();
    vector<ofVec3f> getSurfaceNorms();
    void draw();
    
    Medium * medium;
    Surface * surface;
};