//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant(Seed seed) : Sprite(seed){
    plant.set(10, 10);
    plant.setPosition(ofVec3f(0,-100,0));
}

void Plant::move(){
    ofVec3f loc = plant.getPosition();
    plant.setPosition(loc.x, loc.y-0.1f, loc.z);
}
void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){
    material.begin();
    ofPushMatrix();
    ofSetColor(0, 255, 0, 100);
    ofRotate(90, 1, 0, 0);
    plant.drawWireframe();
    
    ofFill();
    ofPopMatrix();
    
    material.end();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}