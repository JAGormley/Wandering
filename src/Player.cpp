//
//  Player.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Player.h"


Player::Player(){
    controls.setCam(cam);
};

void Player::move(){
    controls.move();
    // debug: lock camera in place:
//    cam.setPosition(ofVec3f(Light::getLightPos().x+10, Light::getLightPos().y+30,Light::getLightPos().z+10));
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

void Player::draw(){
    cam.draw();
}

void Player::setMovementType(Controls::Type type){
    controls.type = type;
}
Controls::Type Player::getMovementType(){
    return controls.type;
}

void Player::setLocation(ofVec3f location){
    cam.setPosition(location);
    controls.setOrbitRadius(location.y);
}

