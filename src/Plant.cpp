//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant(SpriteSeed spriteSeed) : Sprite(spriteSeed){
    // TODO: get plantSize from spriteSeed
    sSeed = spriteSeed;
}


void Plant::update(){
}

void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){
    
    ofPushMatrix();
    material.begin();
    ofSetColor(139,69,19);
    stem.draw();
    ofSetColor(143,188,143);
    ofConePrimitive oldTop = top;
    ofVec3f tempV;
    vector<ofVec3f> meshVs = top.getMesh().getVertices();
    
    // TODO: move this into tree(?), test in orbit mode
//    if (stem.getPosition().distance(Player::playerLoc) < 5000)
        for (int i = 0; i < meshVs.size(); i++) {
            tempV = meshVs[i];
            float jimmy = noiseGen(tempV.x, tempV.y)/sSeed.getMoveDiv();
            tempV = ofVec3f(tempV.x+jimmy, tempV.y+jimmy, tempV.z+jimmy);
            top.getMesh().getVertices()[i] = tempV;
        }
    
    
    stem.transformGL();
    top.draw();
    stem.restoreTransformGL();
    top = oldTop;
    
    //    top.transformGL();
    //    leaves.draw();
    //    top.restoreTransformGL();
    material.end();
    ofPopMatrix();
}

void Plant::setup(){
}

