//
//  Moon.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Moon.h"


Moon::Moon(Seed seed) : Light(seed){
    
    cout << "moon" << endl;
    materialColor.setBrightness(255.f);
    materialColor.setSaturation(255);
    float colorHue = 118;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
}

void Moon::draw(){
    ofPushMatrix();
    material.begin();
    light.setPosition(0, 1200, -1990);
    ofTranslate(0, 0, -2000);
    
    light.rotate(180, 1, 0, 0);
    ofRotate(180, 1, 0, 0);
    
    ofSetCircleResolution(100);
    ofCircle(0, 0, 1200);
    material.end();
    ofPopMatrix();
    
    //    light.draw();
}