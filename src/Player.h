//
//  Player.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

#include "ofxLeapMotion2.h"
#include "Controls.h"
#include "Light.h"
#include <stdio.h>

class Player {
public:
    
    Player();
    
    void move();
    ofVec3f getLocation();
    void draw();
    void startCam();
    void stopCam();
    void setMovementType(Seed lSeed);
    void setLocation(Seed lSeed);
    Seed::Traversal getMovementType();
    
    ofCamera cam;

private:
    Controls controls;
    
};