//
//  Controls.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

#ifndef __Wandering2__Controls__
#define __Wandering2__Controls__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include <math.h>

#endif /* defined(__Wandering2__Controls_) */


class Controls {
public:
    Controls();
    
    void setCam(ofCamera &cam);
    void move();
    void moveType();
    void setOrbitRadius(float radius);
    
    
    
    enum Type {FLOAT, WALK, FLY, ORBIT};
    Type type;
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    ofCamera * cam;
    ofPoint handPos;
    ofPoint handNormal;
    float orbitRadius;
    float orbiter;
    float orbiter2;
    ofSpherePrimitive sp;
    ofSpherePrimitive sp2;
    ofVec3f rotated;
    
private:
    ofMatrix4x4 transformer;
};