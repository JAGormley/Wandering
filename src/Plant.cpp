//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant(Seed seed) : Sprite(seed){
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(250);
    
    plant.set(10, 10);
    plant.setPosition(ofVec3f(ofRandom(2000)-1000, ofRandom(2000)-1000, ofRandom(2000)-1000));
    
    colorHue = ofRandom(0, 250);
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
}

void Plant::move(){
    ofVec3f loc = plant.getPosition();
    plant.setPosition(loc.x-0.1f, loc.y, loc.z);
}
void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){
    material.begin();
//    ofFill();
//    ofSetColor(0, 255, 0, 100);
    plant.draw();
    material.end();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}

vector<ofVec3f> Plant::getVerts(){
    return plant.getMesh().getVertices();
}