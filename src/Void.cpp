//
//  Void.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "Void.h"


Void::Void(Seed seed) : Surface(seed){
    vboMesh = rawShape.getMesh();
}

void Void::setColor(ofColor hue){
    
}

void Void::update(){
}

void Void::draw(){
    ofSetColor(100, 100, 100);
    ofPushMatrix();
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    move();
    vboMesh.draw();
    ofPopMatrix();
}

void Void::move(){
    vector<ofVec3f> meshVerts = vboMesh.getVertices();
    for (int i = 0; i < meshVerts.size(); i++) {
        
        float noise = voidNoiseGen(meshVerts[i].x, meshVerts[i].y);
        
        vboMesh.getVertices()[i].rotate(meshVerts[i].y/2000, rawShape.getYAxis());
        
    }
}