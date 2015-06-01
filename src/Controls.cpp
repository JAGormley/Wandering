//
//  Controls.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Controls.h"
#include <stdio.h>

Controls::Controls(){
    type = FLY;
};

void Controls::move(ofCamera &cam){
    leap.open();
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
    }
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        handPos    = simpleHands[i].handPos;
        handNormal = simpleHands[i].handNormal;
    }
    
    if (simpleHands.size() > 0){
        moveType(cam);
    }
    
    leap.markFrameAsOld();
}

void Controls::moveType(ofCamera &cam){
    float up;
    float down;
    float back_forth;
    float pitch_lr;
    float pitch_ud;
    
    
    if (type == FLOAT){
        // maybe this has a slow set forward z
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = handPos.y/100;
        back_forth = handPos.z/100;
    }
    else if (type == WALK){
        // TODO needs indepedent head movement!!
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = 0;
        back_forth = handPos.z/200;
    }
    else if (type == FLY){
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = handPos.y/100;
        back_forth = handPos.z/100;
    }
    
    cam.dolly(back_forth);
    cam.setPosition(ofVec3f(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z));
    cam.setOrientation(ofVec3f(cam.getOrientationEuler().x + pitch_ud,
                               cam.getOrientationEuler().y - pitch_lr,
                               cam.getOrientationEuler().z));
    
    
    
    
}