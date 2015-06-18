//
//  mVoid.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "mVoid.h"

mVoid::mVoid(Seed seed) : Medium(seed){
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
    //    material.setEmissiveColor(materialColor);
    
    voidMaterial.setShininess(255);
    voidMaterial.setDiffuseColor(materialColor);
    voidMaterial.setSpecularColor(materialColor);
    
    ofBackground(0, 0, 0);
    for (int i = 0; i < 10000; i++) {
    
        ofMesh tempMesh;
        tempMesh = ofMesh::sphere(3);
        
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        
        float randoX = ofRandom(12000)-6000;
        float randoY = ofRandom(12000)-6000;
        float randoZ = ofRandom(12000)-6000;
        
        // move the sphere's vertices to new location
        for (int j = 0; j < tempVerts.size(); j++) {
            
            ofVec3f tempster = ofVec3f(tempVerts[j].x+randoX, tempVerts[j].y+randoY, tempVerts[j].z+randoZ);
            tempMesh.getVertices()[j] = tempster;
            
        }
        
        // add the vertices to the mesh
        voidMesh.append(tempMesh);
        
    }
}

void mVoid::draw(){
    ofSetColor(255, 255, 255);
    //    for (int i = 0; i < stars.size(); i++) {
    //        stars[i].draw();
    //    }
    voidMaterial.begin();
    voidMesh.draw();
    voidMaterial.end();
}


void mVoid::setColor(ofColor hue){
    
}
void mVoid::update(){
    
}

vector<ofVec3f> mVoid::getMeshVerts(){
    return voidMesh.getVertices();
}

//mVoid::~mVoid(){}