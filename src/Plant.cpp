//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant() : Sprite(){
    
    
    plant.set(5, 50, 5);
    
    float xRand = ofRandom(2000)-1000;
    //    if (xRand < 0) xRand-=500; else xRand +=500;
    //    float yRand = ofRandom(1000)-500;;
    //    if (yRand < 0) yRand-=500; else yRand +=500;
    float zRand = ofRandom(2000)-1000;
    //    if (zRand < 0) zRand-=500; else zRand +=500;
    
    
    plant.setPosition(xRand, 25, zRand);

    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
}

void Plant::move(){
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