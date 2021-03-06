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
        
        leap.setMappingX(-230, 230, -ofGetWidth(), ofGetWidth());
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -800, 800);
    }
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        handPos    = simpleHands[i].handPos;
        handNormal = simpleHands[i].handNormal;
    }
    
    if (simpleHands.size() > 0){

        moveType();
        roller = simpleHands[0].roll/5;
    }
    
    leap.markFrameAsOld();
}

void Controls::setOrbitRadius(float radius){
    sp.resetTransform();
    sp.set(radius, 32);
    orbitRadius = radius;
}
void Controls::moveType(){
    float up = 0;
    float down = 0;
    float back_forth = 0;
    float pitch_lr = 0;
    float pitch_ud = 0;
    
    if (type == Seed::FLOAT){
        moveHelper(handPos.z/200, handPos.x/800, 0, handPos.y/100, 0);
    }
    
    else if (type == Seed::WALK){
        //                cout << "WALK" << endl;
        moveHelper(handPos.z/200, handPos.x/800, 0, 0, 0);
    }
    
    else if (type == Seed::ORBIT){
        //        cout << "ORBIT" << endl;
        sp.rotate(handPos.z/6000, sp.getXAxis());
        sp.rotate(-handPos.x/6000, sp.getZAxis());
        
        
        transformer = sp.getLocalTransformMatrix();
        transformer.setTranslation(sp.getUpDir()*orbitRadius);
        
        cam->setTransformMatrix(transformer);
        cam->boom(handPos.y/5.0);
        cam->tilt(-20);
    }
    
    
    else if (type == Seed::FLY){
        
        up = 1.f;
        down = 0.f;
        pitch_lr = handPos.x/1000;
        pitch_ud = handPos.y/1000;
        back_forth = handPos.z/20;
        
        
        // FLIGHT CORRAL: limit the player's travel to a "tube"
        ofVec3f camPos = cam->getPosition();
        int clampX = ofClamp(camPos.x, -2000, 2000);
        int clampY = ofClamp(camPos.y, 400, 2000);
        cam->setPosition(clampY, 400, camPos.z);
        
        
        if (back_forth > 0) back_forth = 0;
        cam->dolly(back_forth);
        
        if (cam->getRoll() < 30 && cam->getRoll() > -30)
            cam->roll(roller);
        
        if ((cam->getLookAtDir().x > -.5f && pitch_lr < 0)){
            cam->pan(-pitch_lr);
        }
        else if ((cam->getLookAtDir().x < .5f && pitch_lr > 0)){
            cam->pan(-pitch_lr);
        }
        if ((cam->getLookAtDir().y < .5f && pitch_ud > 0)){
            cam->tilt(pitch_ud);
        }
        else if ((cam->getLookAtDir().y > -.5f && pitch_ud < 0)){
            cam->tilt(pitch_ud);
        }
    }
}



void Controls::moveHelper(float dolly, float pan, float tilt, float boom, float truck){
    cam->dolly(dolly);
    cam->pan(-pan);
    cam->tilt(tilt);
    cam->boom(boom);
    //    cam->truck(-truck);
}