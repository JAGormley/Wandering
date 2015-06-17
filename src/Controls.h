//
//  Controls.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

#include <math.h>
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofxLeapMotion2.h"



#ifndef __Wandering2__Seed__
#include "Seed.h"
#define __Wandering2__Seed__
#endif /* defined(__Wandering2__Seed__) */


class Controls {
public:
    Controls();
    
    void setCam(ofCamera &cam);
    void move();
    void moveType();
    void setOrbitRadius(float radius);
    void moveHelper(float dolly, float pan, float tilt, float boom, float truck);
    
    Seed::Traversal type;
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    ofCamera * cam;
    ofPoint handPos;
    ofPoint handNormal;
    float orbitRadius;
    ofSpherePrimitive sp;
    ofSpherePrimitive sp2;
    ofVec3f rotated;
    float roller;
    
    
private:
    ofMatrix4x4 transformer;
};