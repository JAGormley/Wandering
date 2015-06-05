//
//  Domain.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__Domain__
#define __Wandering2__Domain__
#include <stdio.h>
#include "ofMain.h"
#endif /* defined(__Wandering2__Domain__) */

#ifndef __Wandering2__Seed__
#include "Seed.h"
#define __Wandering2__Seed__
#endif /* defined(__Wandering2__Seed__) */

class Domain {
public:
    Domain(Seed seed){};
    enum Type {GROUND, WATER, VOID, AIR};
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts()=0;
    Type getType();
    Type type;
};