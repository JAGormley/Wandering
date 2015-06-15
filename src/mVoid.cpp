//
//  mVoid.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "mVoid.h"

mVoid::mVoid(Seed seed) : Medium(seed){
    ofBackground(0, 0, 0);
//    voidMaterial.setShininess(200);
    
//    materialColor.setBrightness(100.f);
//    materialColor.setSaturation(160);
//    materialColor.setHue(130);
//    voidMaterial.setEmissiveColor(materialColor);
//    materialColor.setBrightness(100.f);
//    materialColor.setSaturation(200);
//    materialColor.setHue(85);
//    voidMaterial.setDiffuseColor(materialColor);
//    materialColor.setBrightness(95.f);
//    materialColor.setSaturation(200);
//    voidMaterial.setSpecularColor(materialColor);
    
    
    }

void mVoid::draw(){
    
}


void mVoid::setColor(ofColor hue){
    
}
void mVoid::update(){
    
}
vector<ofVec3f> mVoid::getMeshVerts(){
    return voidMesh.getVertices();
}

//mVoid::~mVoid(){}