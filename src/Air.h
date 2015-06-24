//
//  Air.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#pragma once

#include <stdio.h>
#include "Medium.h"



class Air: public Medium {
public:
    Air(Seed seed);
    void draw();
    void setColor(ofColor hue);
    void update();
    vector<ofVec3f> getMeshVerts();
    ofVboMesh generateCloud();
    
    float colorHue;
    ofColor materialColor;
    ofMaterial airMaterial;
    ofVboMesh airMesh;
    vector<ofCylinderPrimitive> clouds;
    ofCylinderPrimitive testCloud;
};