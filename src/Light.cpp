//
//  Light.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Light.h"

// TODO: check sphere light now

Light::Light(Seed seed){
    this->seed = seed;
    
    
    light.setPosition(0, 1500, 0);
    ofSetSmoothLighting(true);
    
    
    shaderBlurX.load("shadersGL2/shaderBlurX");
    shaderBlurY.load("shadersGL2/shaderBlurY");
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
    //    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    
    // specular color, the highlight/shininess color //
    //    light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
    lightColor.set(lightColor.white);
    lightColor.setBrightness( 50.f );
    light.setAmbientColor(lightColor);
    lightColor.setBrightness( 255.f );
    light.setDiffuseColor(lightColor);
    light.setSpecularColor(lightColor);
    
}

void Light::update(){
    
}

void Light::draw(){
    ofPushMatrix();
    ofSetColor(255,255,255);
    material.begin();
    
    ofRotate(160, 1, 0, 0);

    light.setPosition(0, lightSize, -lightDistance-Player::playerLoc.z+200);
    // TODO: tie light rotation to sun rotation for movement
    light.rotateAround(150, ofVec3f(1,0,0), ofVec3f(0,0,0));
    
    if (seed.traversal == Seed::ORBIT) {
        ofTranslate(0, 0, -seed.shapeSize);
    }
    else {
        ofTranslate(0, 0, -lightDistance-Player::playerLoc.z);
    }
    ;
    // flip facade so material faces light
    ofRotate(180, 1, 0, 0);
    
    drawChild();
    
    material.end();
    
    ofPopMatrix();
    light.draw();
    //    }
    
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