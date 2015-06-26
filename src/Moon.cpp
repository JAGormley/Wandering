//
//  Moon.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Moon.h"


Moon::Moon(Seed seed) : Light(seed){
    
    facade.set(3000, 5, 100, 1);
    facade.rotate(90, 1, 0, 0);
    
    materialColor.setBrightness(255.f);
    materialColor.setSaturation(180);
    float colorHue = 110;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
    ofColor moonCol(50,90,120);
    moonCol.setBrightness(255);
    light.setDiffuseColor(moonCol);
//    light.setSpecularColor(ofColor(0,0,255));

    lightSize = 600;
    
}


void Moon::drawChild(){
    facade.setPosition(ofVec3f(light.getPosition().x, Player::playerLoc.y+2000, Player::playerLoc.z-15000));
    facade.draw();
}