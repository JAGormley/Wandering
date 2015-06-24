//
//  Medium.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "Player.h"
#include "Seed.h"


class Medium {
public:
    Medium(Seed seed);
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts()=0;
    virtual ~Medium();
};