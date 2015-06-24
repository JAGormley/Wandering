//
//  Light.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Light.h"

// TODO: light placement logic for ORBIT

Light::Light(Seed seed){
    this->seed = seed;
    
    ofSetSmoothLighting(true);
    
    
//    shaderBlurX.load("shadersGL2/shaderBlurX");
//    shaderBlurY.load("shadersGL2/shaderBlurY");
    
    
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
    //    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    
    // specular color, the highlight/shininess color //
    //    light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
//    lightColor.set(lightColor.white);
//    lightColor.setBrightness( 50.f );
//    light.setAmbientColor(lightColor);
//    lightColor.setBrightness( 255.f );
//    light.setDiffuseColor(lightColor);
//    light.setSpecularColor(lightColor);
    
}

void Light::update(){
    light.setPosition(30, Player::playerLoc.y+8000, Player::playerLoc.z-20000);
//    light2.setPosition(30, Player::playerLoc.y+6000, Player::playerLoc.z-20000);
}

void Light::draw(){
    ofPushMatrix();
    ofSetColor(255,255,255);
    
    
    material.begin();
    drawChild();
    material.end();
    
    ofPopMatrix();
    light.draw();

    
}

void Light::enable(){
    light.enable();
}
void Light::disable(){
    light.disable();
}
void Light::setPosition(ofVec3f pos){
    light.setPosition(pos);
}
ofVec3f Light::getPosition(){
    light.getPosition();
}