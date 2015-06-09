//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){
    //    type = WaterSPHERE;
    
    rawShape = seed.getShape();
    
    
    
    
    //    int planeWidth = 4000;
    //    int planeHeight = 4000;
    //    int planeColums = 20;
    //    int planeRows = 20;
    //    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    //    plane.rotate(90, 0, 0, 1);
    //    WaterMesh = plane.getMesh();
    
}

void Water::draw(){
    ofSetColor(255, 200, 0);
    ofPushMatrix();
    ofRotate(90, 1, 0, 0);
    
    rawShape.draw();
    ofPopMatrix();
}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    
}

vector<ofVec3f> Water::getMeshVerts(){
    return plane.getMesh().getVertices();
}