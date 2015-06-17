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


void Moon::drawChild(){

    ofSetCircleResolution(100);
    ofCircle(0, 0, lightSize);

}