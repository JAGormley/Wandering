//
//  Ground.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Ground.h"

Ground::Ground(Seed seed) : Domain(seed){
    int planeWidth = 4000;
    int planeHeight = 4000;
    int planeColums = 20;
    int planeRows = 20;
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
}

void Ground::draw(){
    plane.drawWireframe();
}

void Ground::setColor(ofColor hue){
    
}
void Ground::update(){
    
}
vector<ofVec3f> Ground::getMeshVerts(){
    return plane.getMesh().getVertices();
}