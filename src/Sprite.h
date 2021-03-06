//
//  Sprite.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//


// sprite placement and movement based on movement type
// if flying, sprites populate close to player
// if floating, random
// if orbiting, set orbit height



#pragma once

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "SpriteSeed.h"
#include "Sound.h"


class Sprite {
public:
    
    Sprite(SpriteSeed spriteSeed){};
    virtual void update() =0;
    virtual void activate();
    virtual void setActivated(bool activated) =0;
    virtual void draw() =0;
    virtual float noiseGen(float x, float y);
    
    ofMaterial material;
    int alphFill;
    Sound player;
    bool activated;
    ofColor actCol;
};