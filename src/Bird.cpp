//
//  Bird.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-26.
//
//

#include "Bird.h"

Bird::Bird(SpriteSeed spriteSeed) : Animal(spriteSeed){
    activated = false;
    alphFill = 0;
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 128;
    materialColor.setHue(colorHue);
    material.setShininess(255);
    //    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
    
    actCol = ofColor(176,224,230);
    actCol.setBrightness(150);
    
    pos = sSeed.animalPos();
    body.set(100, 15);
    body.setPosition(pos);
    body.setScale(1.0, .3, .3);
    body.rotate(90, body.getYAxis());
//
//    ring1.set(80, 15);
//    ring1.setMode(OF_PRIMITIVE_LINES);
//    ring1.setParent(body);
//    
//    ring2.set(80, 15);
//    ring2.setMode(OF_PRIMITIVE_LINES);
//    ring2.setParent(body);
//    
    this->setup();
    body.boom(sSeed.getOrbitHeight());
//    ring1.boom(40);
//    ring2.boom(-40);
}


void Bird::update(){
//    body.move(0, 0, -1*noiseGen(body.getPosition().x, body.getPosition().y)/10);
    
    body.move(0, 0, -30);
    
    if (activated)

    if (body.getPosition().distance(Player::playerLoc) < 300){
        if (!activated) {
            player.playSE(1);
            activate();
        }
    }
}

void Bird::draw(){
    
    ofSetColor(255,255,255,200);
    material.begin();
    body.draw();
    material.end();
    
}

void Bird::setup(){
    if (sSeed.isOrbital()){
        q.makeRotate(ofVec3f(0, sSeed.getShapeSize(), 0), pos);
        body.rotate(q);
    }
    else {
        body.rotateAround(-90, ofVec3f(1,0,0), ofVec3f(0,0,0));
    }
}