//
//  Animal.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Animal.h"


Animal::Animal(Seed seed) : Sprite(seed){
    box.set(5,5,10,5,5,10);
    box.setPosition(ofVec3f(0,-100,0));
}

void Animal::move(){
    ofVec3f loc = box.getPosition();
    box.setPosition(loc.x, loc.y+0.1f, loc.z);
}
void Animal::activate(){
    
}
void Animal::setActivated(bool activated){
    
}

void Animal::draw(){
    material.begin();
    ofPushMatrix();
    ofSetColor(255, 0, 0, 100);
    ofRotate(90, 1, 0, 0);
    box.draw();
 
    ofFill();
    ofPopMatrix();
    
    material.end();
}
ofVec3f Animal::getLocation(){
    box.getPosition();
}

