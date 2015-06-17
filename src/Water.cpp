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
        
        
        float xCoord = ofMap(tempVert.x, -2500, 2500, 0, 500);
        float yCoord = ofMap(tempVert.y, -2500, 2500, 0, 500);
        
        float height = img.getColor(xCoord, yCoord).getBrightness()/200;
//        cout << height << endl;
        vboMesh.getVertices()[i] = ofVec3f(tempVert.x, tempVert.y, 200*height);
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