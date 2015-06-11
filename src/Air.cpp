//
//  Air.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "Air.h"


Air::Air(Seed seed) : Medium(seed){
    
}

void Air::draw(){
    ofBackground(0, 127, 255);
    
}


void Air::setColor(ofColor hue){
    
}
void Air::update(){
    
}
vector<ofVec3f> Air::getMeshVerts(){
    return AirMesh.getVertices();
}