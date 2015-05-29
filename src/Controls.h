//
//  Controls.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#ifndef __Wandering2__Controls__
#define __Wandering2__Controls__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofxLeapMotion2.h"

#endif /* defined(__Wandering2__Controls_) */


class Controls {
public:
    Controls();
    
    void move(ofCamera &cam);
    
    enum Type {FLOAT, WALK, FLY};
    
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    ofPoint handPos;
    ofPoint handNormal;
    
};