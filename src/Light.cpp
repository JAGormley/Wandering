//
//  Light.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Light.h"

ofLight Light::light = *new ofLight();
Light::Light(){
    light.setPosition(600, 600, 0);
    ofSetSmoothLighting(true);
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
//    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    
    // specular color, the highlight/shininess color //
//    light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
    lightColor.setBrightness( 255.f );
    lightColor.setSaturation( 150.f );
    light.setDiffuseColor(lightColor);
    light.setSpecularColor(lightColor);
    
}

ofVec3f Light::getLightPos(){
        return Light::light.getPosition();
}