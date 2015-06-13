//
//  Animal.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Animal.h"


Animal::Animal() : Sprite(){
    animal.set(5, 10);
    float xRand = ofRandom(1000)-500;
//    if (xRand < 0) xRand-=500; else xRand +=500;
//    float yRand = ofRandom(1000)-500;;
//    if (yRand < 0) yRand-=500; else yRand +=500;
    float zRand = ofRandom(1000)-500;
//    if (zRand < 0) zRand-=500; else zRand +=500;
    
    
    animal.setPosition(xRand, 30, zRand);
    
    //    box.setPosition(ofVec3f(0, , ));
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 210;
    materialColor.setHue(colorHue);
//    material.setEmissiveColor(materialColor);
    
    
    material.setShininess(255);
    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
}

void Animal::move(){
    ofVec3f loc = animal.getPosition();
    animal.setPosition(loc.x-0.1f, loc.y, loc.z);
}
void Animal::activate(){
    
}
void Animal::setActivated(bool activated){
    
}

void Animal::draw(){
    material.begin();
//    ofSetColor(255, 255, 0, 100);
    animal.draw();
 
//    ofFill();
    material.end();
}
ofVec3f Animal::getLocation(){
    animal.getPosition();
}

vector<ofVec3f> Animal::getVerts(){
    return animal.getMesh().getVertices();
}