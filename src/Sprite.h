//
//  Sprite.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

//#include "Seed.h"

#ifndef __Wandering2__Sprite__
#define __Wandering2__Sprite__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"

#endif /* defined(__Wandering2__Sprite__) */



class Sprite {
public:
    
    Sprite(){};
    virtual void move() =0;
    virtual void activate() =0;
    virtual void setActivated(bool activated) =0;
    virtual void draw() =0;
    virtual ofVec3f getLocation() =0;
    virtual vector<ofVec3f> getVerts() =0;
    
};