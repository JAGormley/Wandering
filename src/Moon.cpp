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
    
    ofColor moonCol(20,80,100);
    moonCol.setBrightness(255);
    light.setDiffuseColor(moonCol);
//    light.setSpecularColor(ofColor(0,0,255));

    lightSize = 600;
    
}


void Moon::drawChild(){
    ofPushMatrix();
//    ofRotate(90);
    previousZ = Player::playerLoc.z;
    ofTranslate(0, 0, previousZ-Player::playerLoc.z);
    ofSetCircleResolution(100);
    ofCircle(0, 0, lightSize);
    ofPopMatrix();

}