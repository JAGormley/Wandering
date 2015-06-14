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

#ifndef __Wandering2__Seed__
#include "Seed.h"
#define __Wandering2__Seed__
#endif /* defined(__Wandering2__Seed__) */


class Surface {
public:
    Surface(Seed seed);
    virtual void generate();
    
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts();
    vector<ofVec3f> getMeshNorms();

    of3dPrimitive rawShape;
    ofVboMesh rawMesh;
    Seed seed;
    
    
};