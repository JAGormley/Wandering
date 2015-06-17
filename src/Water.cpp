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
    
}

void Water::setColor(ofColor hue){
    
}

void Water::update(){
    noiseGen(vboMesh.getNumVertices());
    for (int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec3f tempVert = vboMesh.getVertices()[i];
        
        
        float xCoord = ofMap(vboMesh.getVertices()[i].x, -seed.shapeSize/2, seed.shapeSize/2, 0, 500);
        float yCoord = ofMap(vboMesh.getVertices()[i].y, -seed.shapeSize/2, seed.shapeSize/2, 0, 500);
        
        float height = heightMap.getColor(xCoord, yCoord).getBrightness()*2;
//        cout << height << endl;
        vboMesh.getVertices()[i] = ofVec3f(tempVert.x, tempVert.y, height);
    }
}

void Water::draw(){
    ofSetColor(0, 200, 255);
    ofPushMatrix();
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    vboMesh.draw();
    ofPopMatrix();
}