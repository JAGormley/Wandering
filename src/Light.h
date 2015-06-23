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
#include "Player.h"

#endif /* defined(__Wandering2__Light__) */

class Light : public ofLight{
public:
    Light();
    Light(Seed seed);
    virtual void update();
    virtual void draw();
    virtual void enable();
    virtual void disable();
    virtual void drawChild()=0;
    
    void setPosition(ofVec3f pos);
    ofVec3f getPosition();
    
protected:
    ofCylinderPrimitive facade;
    ofVec3f position;
    ofColor lightColor;
    ofLight light;
    ofMaterial material;
    ofColor materialColor;
    int lightSize;
    int lightDistance;
    float previousZ;
    
    
    ofQuaternion q;
    ofShader shaderBlurX;
    ofShader shaderBlurY;
    ofFbo fboBlurOnePass;
    ofFbo fboBlurTwoPass;
    Seed seed;
    
    
};


