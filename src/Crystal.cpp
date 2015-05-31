//
//  Crystal.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Crystal.h"


Crystal::Crystal(Seed seed) : Sprite(seed){}

void Crystal::move(){
    std::cout << "yuuss";
}
void Crystal::activate(){
    
}
void Crystal::setActivated(bool activated){
    
}

void Crystal::draw(){
    material.begin();
    ofPushMatrix();
    ofSetColor(0, 0, 255, 100);
    ofRotate(90, 1, 0, 0);
    ofBoxPrimitive box(5,5,10,5,5,10);
    box.setPosition(ofVec3f(0,-100,0));
    box.draw();
 
    ofFill();
    ofPopMatrix();
    
    material.end();
}
ofVec3f Crystal::getLocation(){
    
}

