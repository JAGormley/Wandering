//
//  Player.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Player.h"

Player::Player(){};

void Player::move(){
    leap.open();
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){

        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);

        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    }
    
    if (simpleHands.size() > 0){
        cam.dolly(handPos.z/100);
        cam.setOrientation(ofVec3f(cam.getOrientationEuler().x,
                                    cam.getOrientationEuler().y  - handPos.x/100,
                                    cam.getOrientationEuler().z));
    }
}

void Player::draw(){
        for(int i = 0; i < simpleHands.size(); i++){
            bool isLeft        = simpleHands[i].isLeft;
            handPos    = simpleHands[i].handPos;
            handNormal = simpleHands[i].handNormal;
    
            ofSetColor(0, 0, 255);
            ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
            ofSetColor(255, 255, 0);
            ofDrawArrow(handPos, handPos + 100*handNormal);
        }
}

void Player::startCam(){
    cam.begin();
}
void Player::stopCam(){
    cam.end();
}
