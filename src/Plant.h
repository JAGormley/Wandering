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
    Plant(SpriteSeed spriteSeed);
    virtual void update();
    virtual void activate();
    virtual void setActivated(bool activated);
    virtual void draw();
    virtual void setup();
    
    ofMaterial material;
    ofBoxPrimitive stem;
    ofBoxPrimitive top;
    ofColor materialColor;
    float colorHue;
    ofVec3f pos;
    SpriteSeed sSeed;
    of3dPrimitive nodePlant;
    
};