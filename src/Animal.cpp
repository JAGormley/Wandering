//
//  Animal.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Animal.h"


Animal::Animal() : Sprite(){
    
    
    
    box.set(5,5,10,5,5,10);
//    box.setPosition(ofVec3f(0, , ));
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    //    colorHue = ofRandom(0, 250);
    colorHue = 100;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(100);
    
    
    
}

void Animal::move(){
    
}
void Animal::activate(){
    
}
void Animal::setActivated(bool activated){
    
}

void Animal::draw(){
    material.begin();
//    ofSetColor(255, 255, 0, 100);
    box.draw();
 
//    ofFill();
    material.end();
}
ofVec3f Animal::getLocation(){
    box.getPosition();
}

