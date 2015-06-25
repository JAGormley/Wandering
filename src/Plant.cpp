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
    stem.draw();
    top.draw();
    
    
    leaves.draw();
    material.end();
    ofPopMatrix();
}

void Plant::setup(){
}