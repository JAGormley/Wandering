//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){
    vboMesh = rawShape.getMesh();
    
    
    ofColor matCol(0,0,255);
    matCol.setBrightness(255);
    material.setDiffuseColor(matCol);
    material.setShininess(80);
    material.setSpecularColor(ofColor(0,255,150));
    
}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    
    if (seed.getTraversal() != Seed::ORBIT) {
        
        waterNoiseGen(vboMesh.getNumVertices());
        for (int i = 0; i < vboMesh.getVertices().size(); i++) {
            ofVec3f tempVert = vboMesh.getVertices()[i];
            
            
            int xCoord = ofMap(vboMesh.getVertices()[i].x, -seed.shapeSize/2, seed.shapeSize/2, 0, 99);
            int yCoord = ofMap(vboMesh.getVertices()[i].y, -seed.shapeSize/2, seed.shapeSize/2, 0, 99);
            
            float height = heightMapi[xCoord][yCoord]*2;
            vboMesh.getVertices()[i] = ofVec3f(tempVert.x, tempVert.y, height);
        }
    }
}

void Water::draw(){
    ofSetColor(0, 200, 255);
    ofPushMatrix();
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    material.begin();
    vboMesh.draw();
    material.end();
    ofPopMatrix();
}