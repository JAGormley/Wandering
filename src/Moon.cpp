//
//  Moon.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Moon.h"


Moon::Moon(Seed seed) : Light(seed){
    
    materialColor.setBrightness(255.f);
    materialColor.setSaturation(180);
    float colorHue = 110;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
    lightSize = 600;
    lightDistance = 2500;
    
}

//void Moon::draw(){
//    ofPushMatrix();
//    
//    ofSetColor(255,255,255);
//    material.begin();
//    
//    ofRotate(90, 1, 0, 0);
//    
//    light.setPosition(0, lightSize, -lightDistance+400);
//    light.rotateAround(90, ofVec3f(1,0,0), ofVec3f(0,0,0));
//    ofTranslate(0, 0, -lightDistance);
//    
//    // flip moon so material faces light
//    ofRotate(180, 1, 0, 0);
//    ofSetCircleResolution(100);
//    ofCircle(0, 0, lightSize);
//    material.end();
//    
//    ofPopMatrix();
////    light.draw();
//}

void Moon::drawChild(){
    ofSetCircleResolution(100);
    ofCircle(0, 0, lightSize);
}