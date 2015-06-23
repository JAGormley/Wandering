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
#include "Player.h"


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
    
    void addVRow();
    void stitch();
    ofVec3f setNoiseHeight(ofVec3f temp);
    
    of3dPrimitive rawShape;
    ofVboMesh vboMesh;
    Seed seed;
    
    
    ofImage heightMap;
    int heightMapi[10000][10000];
    
    int surfaceID;
    int surfaceRes;
    int surfaceHeightMult;
    
    
    // debug
    ofLight dLight;
    
    bool newRow;
    bool even;
};