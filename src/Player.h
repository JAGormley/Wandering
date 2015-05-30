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
#include "Controls.h"

#include <stdio.h>

#endif /* defined(__Wandering2__Player__) */


class Player {
public:
    
    Player();
    
    void move();
    ofVec3f getLocation();
    void draw();
    void startCam();
    void stopCam();
    
    
    ofCamera cam;
    Controls controls;
    int k;
    
};