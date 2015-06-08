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
    type = ORBIT;
    orbiter = 0;
    sp.set(1050, 32);
    
    sp2.set(1050, 32);
};

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
    orbitRadius = radius;
}


void Controls::moveType(){
    float up = 0;
    float down = 0;
    float back_forth = 0;
    float pitch_lr = 0;
    float pitch_ud = 0;
    float strafe = 0;
    
    
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
    else if (type == ORBIT){
        up = 1.f;
        down = 0.f;
//        pitch_lr = ;
        pitch_lr = handPos.x/100;
//        pitch_ud = handPos.y/100;
//        strafe = handPos.x*10;
//        back_forth = handPos.z/100;
//        pitch_ud = back_forth/orbitRadius*2*M_PI;
        
        
//        cam->rotateAround(-1, sp.getXAxis(), ofVec3f(0,0,0));

        sp.rotate(-handPos.x/1500, 1, 0, 0);
        sp.rotate(-handPos.z/1500, 0, 0, 1);
        
//                cout << rotated << endl;
//        ofVec3f camPos = sp.getLocalTransformMatrix() * -sp.getMesh().getVertices()[0];
        
        
        
        
//        ofVec3f camLook = sp.getLocalTransformMatrix() * -sp.getMesh().getVertices()[100];
//        cam->lookAt(camLook);
        
        ofVec3f camPos = cam->getPosition();
        float lat = atan2(camPos.z, (camPos.x*camPos.x + camPos.y*camPos.y));
        float lng = atan2(camPos.y, camPos.z);
        
        ofMatrix4x4 rotationY;
        ofMatrix4x4 rotationX;
        ofMatrix4x4 translation;
        ofMatrix4x4 matrix;
        
        rotationY.rotate(lng, 0, 1, 0);
        rotationX.rotate(-lat, 1, 0, 0);
        translation.setTranslation(0, 0, 1100);
        
//        matrix = rotationX * rotationY;
        matrix.translate(0, 0, 1100);
        cam->rotate(lng, 1, 0, 0);
//        cam->rotate(-lat, 1, 0, 0);

        
        
        
        
        cam->setPosition(sp.getUpDir()*1100);
        
        
//        cam->setOrientation(sp.getGlobalOrientation());
        
//        cam->setTransformMatrix(sp.getLocalTransformMatrix());
//        cam->lookAt(ofVec3f(0,0,0));
//        ofDrawSphere(camPos, 50);
//        ofDrawSphere(camLook, 50);
//        cam->lookAt(ofVec3f(camPos.x+1, camPos.y+1, camPos.z+1).normalize());
//
        
//        cam->orbit(10, 100, 1100, ofVec3f(0,0,0));
//        cam->
//        cam->lookAt(camLook);
//        for (int i = 0; i < sp.getMesh().getVertices().size(); i++) {
//            ofVec3f tmp = sp.getMesh().getVertices()[i];
////            cout << i << ": " << sp.getMesh().getVertices()[i].x << endl;
//            ofDrawSphere(tmp.x, tmp.y, tmp.z, 10);
//        }
        
        
        
//        cam->rotate(90, 1, 0, 0);
        
//        cam->rotate(90, 1, 0, 0);
//        cam->rotate(90, 0, 1, 0);
//        cout << sp.getUpDir() << endl;
        sp.drawWireframe();


//        cam->rotateAround(0.000001, sp.getYAxis(), ofVec3f(0,0,0));
//        cam->
//        sp.
        
        
//        cout << "x: " << cam->getPosition().x << endl;
//        cout << "y: " << cam->getPosition().y << endl;
//        cout << "z: " << cam->getPosition().z << endl;

        
        
    }
    
//    cam->dolly(back_forth);
//    
//    cam->setPosition(ofVec3f(cam->getPosition().x+strafe,
//                            cam->getPosition().y,
//                            cam->getPosition().z));
//    
//    cam->setOrientation(ofVec3f(cam->getOrientationEuler().x,
//                               cam->getOrientationEuler().y,
//                               cam->getOrientationEuler().z));
    
    
    
    
    
}