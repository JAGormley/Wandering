//
//  Sun.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Sun.h"



Sun::Sun(Seed seed) : Light(seed){
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    float colorHue = 42;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
    lightSize = 600;
    
    // Max sun distance without clipping
    lightDistance = 6410;
    
}

void Sun::drawChild(){
    ofSetCircleResolution(100);
    ofSetColor(255, 255, 255);
    ofCircle(0, 0, 1200);
    ofTranslate(0, 0, -5);
    ofSetColor(50, 50, 0, 100);
    ofCircle(0, 0, 1300);
    ofTranslate(0, 0, -5);
    ofSetColor(50, 50, 0, 50);
    ofCircle(0, 0, 1400);
}