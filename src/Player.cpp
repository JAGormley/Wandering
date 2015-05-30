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
    controls.move(cam);
}

void Player::draw(){
    //    for(int i = 0; i < simpleHands.size(); i++){
    //        bool isLeft        = simpleHands[i].isLeft;
    //        handPos    = simpleHands[i].handPos;
    //        handNormal = simpleHands[i].handNormal;
    //
    //
    //
    //        ofSetColor(0, 0, 255);
    //        ofDrawSphere(handPos.z, handPos.y, handPos.x, 20);
    //        ofSetColor(255, 255, 0);
    //        ofDrawArrow(handPos, handPos + 100*handNormal);
    //    }
}

ofVec3f Player::getLocation(){
    ofVec3f pos = cam.getPosition();   
    return pos;
}

void Player::startCam(){
    cam.begin();
}
void Player::stopCam(){
    cam.end();
}

