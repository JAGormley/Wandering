//
//  Sun.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Sun.h"



Sun::Sun(Seed seed) : Light(seed){
    
    facade.set(1000, 5, 100, 1);
    facade.rotate(90, 1, 0, 0);
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    float colorHue = 42;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
    lightSize = 600;
    
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,200));
    
    // Max sun distance without clipping
    lightDistance = 6200;
    
}


// TODO: fix sun movement, when flying it gradually backs out behind the clipping plane
void Sun::drawChild(){
    
    facade.setPosition(light.getPosition());
    facade.draw();
    
    
//    ofPushMatrix();
//    previousZ = Player::playerLoc.z;
//    ofTranslate(0, 0, previousZ-Player::playerLoc.z);
//    ofSetCircleResolution(100);
//    ofSetColor(255, 255, 255);
//    ofCircle(0, 0, 1200);
//    
//
//    ofPushMatrix();
//    ofTranslate(0, 0, -5);
//    ofSetColor(50, 50, 0, 100);
//    ofCircle(0, 0, 1300);
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    ofTranslate(0, 0, -10);
//    ofSetColor(50, 50, 0, 50);
//    ofCircle(0, 0, 1400);
//    ofPopMatrix();
//    ofPopMatrix();
    
    
    
    
}