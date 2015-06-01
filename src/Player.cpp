//
//  Player.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Player.h"


Player::Player(){
    cam.setPosition(0, 2020, 0);
};

void Player::move(){
    controls.move(cam);
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

