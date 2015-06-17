//
//  Surface.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#pragma once


#include <stdio.h>
#include "ofMain.h"
#include "Seed.h"


class Surface {
public:
    Surface(Seed seed);
    virtual void generate();
    
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts();
    virtual void noiseGen(int meshSize);
    virtual ~Surface();
    
    of3dPrimitive rawShape;
    ofVboMesh vboMesh;
    Seed seed;
    ofImage img;
    
    
};