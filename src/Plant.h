//
//  Plant.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#pragma once

#ifndef __Wandering2__Plant__
#define __Wandering2__Plant__
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#endif /* defined(__Wandering2__Plant__) */

#ifndef __Wandering2__Sprite__
#define __Wandering2__Sprite__
#include "Sprite.h"
#endif /* defined(__Wandering2__Sprite__) */

class Plant: public Sprite {
public:
    Plant();
    void move();
    void activate();
    void setActivated(bool activated);
    void draw();
    ofVec3f getLocation();
    vector<ofVec3f> getVerts();
    
    ofMaterial material;
    ofSpherePrimitive plant;
    ofColor materialColor;
    float colorHue;
    
};