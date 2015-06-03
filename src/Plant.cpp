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
    plant.setPosition(ofVec3f(ofRandom(4000)-2000, ofRandom(4000)-2000, ofRandom(4000)-2000));
    
    colorHue = ofRandom(0, 250);
    materialColor.setHue(colorHue);
    // the light highlight of the material //
//    material.setSpecularColor(materialColor);
//    material.setDiffuseColor(materialColor);
    material.setEmissiveColor(materialColor);
//    materialColor.setHue(200);
//    material.setSpecularColor(materialColor);
//    material.setDiffuseColor(materialColor);
//    material.setEmissiveColor(100);
//    material.setShininess( 64 );
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
    ofFill();
//    ofSetColor(0, 255, 0, 100);
    plant.draw();
//    ofFill();
    material.end();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}