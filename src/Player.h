//
//  Player.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

#ifndef __Wandering2__Player__
#define __Wandering2__Player__

#include "ofxLeapMotion2.h"
#include "Controls.h"
#include "Light.h"

#include <stdio.h>

#endif /* defined(__Wandering2__Player__) */


class Player {
public:
    
    Player();
    
    void move();
    ofVec3f getLocation();
    void startCam();
    void stopCam();
    void setMovementType(Controls::Type type);
    void setLocation(ofVec3f location);
    Controls::Type getMovementType();
    
    ofCamera cam;
    
private:
    Controls controls;
    
    
};