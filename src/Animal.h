//
//  Animal.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//


#pragma once
#ifndef __Wandering2__Animal__
#define __Wandering2__Animal__
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "Light.h"
#include "Sprite.h"
#endif /* defined(__Wandering2__Animal__) */



class Animal: public Sprite {
public:
    Animal(SpriteSeed spriteSeed);
    void move();
    void activate();
    void setActivated(bool activated);
    void draw();
    ofVec3f getLocation();
    vector<ofVec3f> getVerts();
    
    ofMaterial material;
    ofSpherePrimitive animal;
    
    ofColor materialColor;
    float colorHue;
};