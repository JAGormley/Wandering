//
//  Sun.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Sun.h"



Sun::Sun(Seed seed) : Light(seed){
    
    facade.set(8000, 5, 100, 1);
    facade.rotate(90, 1, 0, 0);
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    float colorHue = 42;
    materialColor.setHue(colorHue);
    material.setEmissiveColor(materialColor);
    
    lightSize = 600;
    
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,200));
    
}


void Sun::drawChild(){
    
    facade.setPosition(ofVec3f(light.getPosition().x, Player::playerLoc.y+2000, Player::playerLoc.z-15000));
    facade.draw();
    
    
    
    
    // DEBUG: ALPHA BEING WEIRD...
    //    for (int i = 0; i < 1; i++) {
    //        ofCylinderPrimitive cy = facade;
    //        cy.setPosition(light.getPosition().x, Player::playerLoc.y+2000, light.getPosition().z-1000);
    //        cy.setRadius(facade.getRadius()+1000);
    //        ofSetColor(255, 255, 255, 80);
    //        cy.draw();
    //    }
    
}