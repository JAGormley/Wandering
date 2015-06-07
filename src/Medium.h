//
//  Medium.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__Medium__
#define __Wandering2__Medium__
#include <stdio.h>
#include "ofMain.h"
#endif /* defined(__Wandering2__Medium__) */

#ifndef __Wandering2__Seed__
#include "Seed.h"
#define __Wandering2__Seed__
#endif /* defined(__Wandering2__Seed__) */

class Medium {
public:
    Medium(Seed seed){};
    enum Type {WATER, VOID, AIR};
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts()=0;
    Type getType();
    Type type;
};