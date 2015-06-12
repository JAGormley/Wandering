//
//  Ground.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Ground.h"

Ground::Ground(Seed seed) : Surface(seed){
    
//    int planeWidth = 4000;
//    int planeHeight = 4000;
//    int planeColums = 20;
//    int planeRows = 20;
//    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
//    plane.rotate(90, 0, 0, 1);
//    groundMesh = plane.getMesh();
    
    material.setShininess(255);
    material.setDiffuseColor(ofColor(255,255,255));
    material.setSpecularColor(ofColor(0,30,0));
    
}

void Ground::draw(){
    material.begin();
    ofSetColor(150, 75, 0);
    ofPushMatrix();
    ofRotate(-90, 1, 0, 0);
    rawShape.draw();
    material.end();
//    cout << "GROUNDUP: " << rawShape.getUpDir() << endl;
    ofPopMatrix();
}

void Ground::setColor(ofColor hue){
    
}

void Ground::update(){
    
}

vector<ofVec3f> Ground::getMeshVerts(){
    return plane.getMesh().getVertices();
}