//
//  Light.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Light.h"




Light::Light(Seed seed){
    //    light.setSpotlight();
    light.setPosition(0, 1500, 0);
    ofSetSmoothLighting(true);
    //    light.set
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
    //    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    
    // specular color, the highlight/shininess color //
    //    light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
    lightColor.set(lightColor.white);
    lightColor.setBrightness( 255.f );
    light.setDiffuseColor(lightColor);
    light.setSpecularColor(lightColor);


}


Light::Light(){
//    light.setSpotlight();
light.setPosition(0, 1500, 0);
    ofSetSmoothLighting(true);
    //    light.set
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
    //    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    
    // specular color, the highlight/shininess color //
    //    light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
    lightColor.set(lightColor.white);
    lightColor.setBrightness( 255.f );
    light.setDiffuseColor(lightColor);
    light.setSpecularColor(lightColor);
    
}

void Light::update(){
//    int newPos;
////    newPos = light.getPosition().y + 1;
////    newPos = newPos%1050;
//    light.setPosition(0, 1500, 0);
}

//void Light::draw(){
//    light.draw();
//}
void Light::enable(){
    light.enable();
}
void Light::disable(){
    light.disable();
}
void Light::setPosition(ofVec3f pos){
    light.setPosition(pos);
}