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
    
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual ofVboMesh getMesh();
    virtual void noiseGen(int meshSize);
    virtual void waterNoiseGen(int meshSize);
    virtual ~Surface();
    
    //    virtual ofPlanePrimitive getPlane();
    
    of3dPrimitive rawShape;
    ofVboMesh vboMesh;
    Seed seed;
    ofImage heightMap;
    int heightMapi[10000][10000];
    int groundID;
    int waterID;
    ofLight dLight;
};