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
//    float dir = cam.getHeading();
//    ofVec3f jimmy(dir.x+100, dir.y+100, dir.z+1000);
//    ofDrawArrow(dir, jimmy);
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
    return cam.getPosition();
}

void Player::startCam(){
    cam.begin();
}
void Player::stopCam(){
    cam.end();
}

