//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    
}

void Water::draw(){
    ofSetColor(0, 200, 255);
    ofPushMatrix();
    ofRotate(-90, 1, 0, 0);
    rawShape.draw();
    ofPopMatrix();
}