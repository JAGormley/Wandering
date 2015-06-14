//
//  Void.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "Void.h"


Void::Void(Seed seed) : Surface(seed){}

void Void::setColor(ofColor hue){
    
}

void Void::update(){
    
}

void Void::draw(){
    ofSetColor(100, 100, 100);
    ofPushMatrix();
    ofRotate(-90, 1, 0, 0);
    rawShape.draw();
    ofPopMatrix();
}

vector<ofVec3f> Void::getMeshVerts(){
    return plane.getMesh().getVertices();
}

vector<ofVec3f> Void::getMeshNorms(){
    return plane.getMesh().getNormals();
}