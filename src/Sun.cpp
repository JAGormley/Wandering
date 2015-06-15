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
    lightDistance = 2500;
    
}


void Sun::drawChild(){
    ofSetCircleResolution(100);
    ofCircle(0, 0, 1200);
}