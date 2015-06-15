//
//  Light.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__Light__
#define __Wandering2__Light__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "Seed.h"

#endif /* defined(__Wandering2__Light__) */

class Light : public ofLight{
public:
    Light();
    Light(Seed seed);
    virtual void update();
    virtual void draw()=0;
    virtual void enable();
    virtual void disable();
    virtual void setPosition(ofVec3f pos);
    
protected:
    of3dPrimitive facade;
    ofVec3f position;
    ofColor lightColor;
    ofLight light;
    
};


