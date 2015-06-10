//
//  Water.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Water.h"

Water::Water(Seed seed) : Surface(seed){}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    
}

vector<ofVec3f> Water::getMeshVerts(){
    return plane.getMesh().getVertices();
}