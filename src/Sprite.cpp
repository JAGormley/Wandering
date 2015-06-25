//
//  Sprite.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Sprite.h"


//Sprite::Sprite(Seed seed){};




float Sprite::noiseGen(float x, float y){
    float a = x * .03;
    float b = y * .05;
    float c = ofGetFrameNum() / 500.0;
    
    float noise = ofNoise(a,b,c) * 255;
    float color = noise>75 ? ofMap(noise,75,255,0,255) : 0;
    return color;
}