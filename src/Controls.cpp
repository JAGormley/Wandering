//
//  Controls.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Controls.h"
#include <stdio.h>

Controls::Controls(){};

void Controls::setCam(ofCamera &cam) {
    this->cam = &cam;
}

void Controls::move(){
    
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
        moveType();
    }
    
    leap.markFrameAsOld();
}

void Controls::setOrbitRadius(float radius){
    sp.set(radius, 32);
}

void Controls::moveType(){
    
//    cout << type << endl;
    float up = 0;
    float down = 0;
    float back_forth = 0;
    float pitch_lr = 0;
    float pitch_ud = 0;
    float strafe = 0;
    
    if (type == Seed::FLOAT){
//        cout << "FLOAT" << endl;
        // maybe this has a slow set forward z
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = handPos.y/100;
        back_forth = handPos.z/100;
    }
    else if (type == Seed::WALK){
//        cout << "WALK" << endl;
        // TODO needs indepedent head movement!!
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = 0;
        back_forth = handPos.z/200;
    }
    else if (type == Seed::FLY){
//        cout << "FLY" << endl;
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/100;
        pitch_ud = handPos.y/100;
        back_forth = handPos.z/100;
    }
    else if (type == Seed::ORBIT){
//        cout << "ORBIT" << endl;
        sp.rotate(handPos.z/1000, sp.getXAxis());
        sp.rotate(-handPos.x/1000, sp.getZAxis());
        
        transformer = sp.getLocalTransformMatrix();
        transformer.setTranslation(sp.getUpDir()*(sp.getRadius()));
        
        cam->setTransformMatrix(transformer);

        
        // DEBUG:
        sp.drawWireframe();
    }
    
    if (type != Seed::ORBIT){
        cam->dolly(back_forth);
        
        cam->setPosition(ofVec3f(cam->getPosition().x+strafe,
                                 cam->getPosition().y,
                                 cam->getPosition().z));
        
        cam->setOrientation(ofVec3f(cam->getOrientationEuler().x,
                                    cam->getOrientationEuler().y-pitch_lr,
                                    cam->getOrientationEuler().z));
    }
}