//
//  Crystal.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-24.
//
//

#include "Crystal.h"


Crystal::Crystal(SpriteSeed spriteSeed) : Animal(spriteSeed){
    activated = false;
    alphFill = 0;
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 200;
    materialColor.setHue(colorHue);
    material.setShininess(255);
    //    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
    
    actCol = ofColor(219,112,147);
    actCol.setBrightness(150);
    
    pos = sSeed.spritePos();
    body.set(100, 2);
    body.setPosition(pos);
    
    ring1.set(80, 15);
    ring1.setMode(OF_PRIMITIVE_LINES);
    ring1.setParent(body);
    
    ring2.set(80, 15);
    ring2.setMode(OF_PRIMITIVE_LINES);
    ring2.setParent(body);
    
    this->setup();
    body.boom(sSeed.getOrbitHeight());
    ring1.boom(40);
    ring2.boom(-40);
}



void Crystal::update(){
    body.rotate(1, body.getYAxis());
    if (activated)
        body.rotate(.5, body.getZAxis());
    if (body.getPosition().distance(Player::playerLoc) < 300){
        if (!activated) {
            player.playSE(1);
            activate();
        }
    }
}

void Crystal::draw(){
    
    ofSetColor(255,255,255,100+alphFill);
    material.begin();
    body.draw();
    ring1.draw();
    ring2.draw();
    material.end();
    
}

void Crystal::setup(){
    if (sSeed.isOrbital()){
        q.makeRotate(ofVec3f(0, sSeed.getShapeSize(), 0), pos);
        body.rotate(q);
    }
    else {
        body.rotateAround(-90, ofVec3f(1,0,0), ofVec3f(0,0,0));
    }
}