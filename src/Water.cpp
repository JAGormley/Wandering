//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){
    waterMesh = rawShape.getMesh();
}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    for (int i = 0; i < waterMesh.getVertices().size(); i++) {
        ofVec3f tempVert = waterMesh.getVertices()[i];
        waterMesh.getVertices()[i] = ofVec3f(tempVert.x, tempVert.y, tempVert.z+ofRandom(10)-5);
    }
}

void Water::draw(){
    ofSetColor(0, 200, 255);
    ofPushMatrix();
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    waterMesh.draw();
    ofPopMatrix();
}