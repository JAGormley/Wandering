//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant(SpriteSeed spriteSeed) : Sprite(spriteSeed){
    // TODO: get plantSize from spriteSeed
    sSeed = spriteSeed;  
}


void Plant::update(){
}

void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){
    
    ofPushMatrix();
    material.begin();
    ofSetColor(139,69,19);
    stem.draw();
    ofSetColor(143,188,143);
    ofConePrimitive oldTop = top;
    ofVec3f tempV;
    for (int i = 0; i < 35; i++) {
        tempV = top.getMesh().getVertices()[i];
        float jimmy = noiseGen(tempV.x, tempV.y);
        tempV = ofVec3f(tempV.x+jimmy, tempV.y, tempV.z+jimmy);
        top.getMesh().getVertices()[i] = tempV;
    }
    
    top.draw();
    top = oldTop;
    leaves.draw();
    material.end();
    ofPopMatrix();
}

void Plant::setup(){
}

float Plant::noiseGen(float x, float y){
    float a = x * .03;
    float b = y * .05;
    float c = ofGetFrameNum() / 500.0;
    
    float noise = ofNoise(a,b,c) * 255;
    float color = noise>75 ? ofMap(noise,75,255,0,255) : 0;
    return color;
}