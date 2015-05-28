//
//  Player.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#ifndef __Wandering2__Player__
#define __Wandering2__Player__

#include "ofxLeapMotion2.h"

#include <stdio.h>

#endif /* defined(__Wandering2__Player__) */


class Player {
public:
    Player();
    Player(ofCamera *cam);
    
    void move();
    void draw();
    
    ofCamera cam;
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    ofPoint handPos;
    ofPoint handNormal;
};