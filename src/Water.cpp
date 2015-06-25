//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){
    surfaceRes = 199;
    surfaceHeightMult = 1;
    
    vboMesh = rawShape.getMesh();
    surfaceID = 0;
    
    ofColor matCol(0,0,255);
    matCol.setBrightness(255);
    material.setDiffuseColor(matCol);
    material.setShininess(80);
    material.setSpecularColor(ofColor(0,255,150));
    
    waterMove = 0;
    
}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    
    if (seed.getTraversal() != Seed::ORBIT) {
        waterNoiseGen(vboMesh.getNumVertices());
        for (int i = 0; i < vboMesh.getVertices().size(); i++) {
            ofVec3f tempVert = vboMesh.getVertices()[i];
            vboMesh.getVertices()[i] = setNoiseHeight(tempVert);
        }
    }
    if (abs(Player::playerLoc.z + vboMesh.getVertices()[vboMesh.getVertices().size()-30].y) < 15000){
        addVRow();
    }
    
    
}

void Water::draw(){
    dLight.draw();
    dLight.enable();
    
    ofSetColor(0, 200, 255);
    ofPushMatrix();
    rawShape.drawAxes(100);
    if (seed.getSurfaceShape() != Seed::SPHERE){
        ofRotate(-90, 1, 0, 0);
//        ofRotate(180, 0, 1, 0);
    }
    material.begin();
    vboMesh.draw();
    material.end();
    ofSetColor(255, 0, 0);
    ofDrawSphere(vboMesh.getVertices()[vboMesh.getVertices().size()-30], 7);
    ofPopMatrix();
    dLight.disable();
}