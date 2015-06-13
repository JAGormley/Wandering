//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant() : Sprite(){
    plant.set(5, 50, 5);
    
    float xRand = ofRandom(2000)-1000;
    float zRand = ofRandom(2000)-1000;
    
    
    plant.setPosition(xRand, 25, zRand);

    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
//    material.setEmissiveColor(materialColor);
    
    material.setShininess(255);
    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
}

Plant::Plant(ofVec3f pos, ofVec3f orient) : Sprite(){
    plant.set(5, 50, 5);
    
    plant.setPosition(pos.x, pos.y+25, pos.z);
    
    orientt = orient;
    ofQuaternion quat;
    quat.makeRotate(plant.getOrientationEuler(), orient);
    plant.rotate(quat);
    cout << quat.getEuler() << endl;
//    ofVec3f upDir = plant.getUpDir();
//    ofVec3f rAxis = upDir * orient;
//    float rAmt = upDir.dot(orient);
//    plant.rotate(rAmt, rAxis);
//    cout << "NORMAL: " << orient << endl;
//    cout << "ORIENT: " << plant.getOrientationEuler() << endl;
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
    //    material.setEmissiveColor(materialColor);
    
    material.setShininess(255);
    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
}


void Plant::move(){
}
void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){

    ofDrawArrow(orientt, orientt*1200);
    material.begin();
//    ofFill();
//    ofSetColor(0, 255, 0, 100);
    plant.draw();
    material.end();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}

vector<ofVec3f> Plant::getVerts(){
    return plant.getMesh().getVertices();
}