//
//  Void.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "Void.h"

Void::Void(Seed seed) : Domain(seed){
    type = VOID;
    
    outer.set(1200, 32);
    inner.set(400, 32);
    voidMaterial.setShininess(200);
    voidMesh = outer.getMesh();
    
    materialColor.setBrightness(100.f);
    materialColor.setSaturation(160);
    materialColor.setHue(130);
    voidMaterial.setEmissiveColor(materialColor);
    materialColor.setBrightness(100.f);
    materialColor.setSaturation(200);
    materialColor.setHue(85);
    voidMaterial.setDiffuseColor(materialColor);
    materialColor.setBrightness(95.f);
    materialColor.setSaturation(200);
    voidMaterial.setSpecularColor(materialColor);
    
    
    }

void Void::draw(){
    
    ofSetColor(0,0,0);
    voidMesh.draw();
    ofSetColor(0,120,255);
    voidMaterial.begin();
    inner.draw();
    voidMaterial.end();
}


void Void::setColor(ofColor hue){
    
}
void Void::update(){
    
}
vector<ofVec3f> Void::getMeshVerts(){
    return voidMesh.getVertices();
}
