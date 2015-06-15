//
//  mWater.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "mWater.h"


mWater::mWater(Seed seed) : Medium(seed){
    ofBackground(10, 200, 210);
}

void mWater::draw(){
    
}

void mWater::setColor(ofColor hue){
    
}

void mWater::update(){
    
}

vector<ofVec3f> mWater::getMeshVerts(){
    return mWaterMesh.getVertices();
}