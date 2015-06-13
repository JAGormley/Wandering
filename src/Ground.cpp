//
//  Ground.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Ground.h"

Ground::Ground(Seed seed) : Surface(seed){
    
    material.setShininess(255);
    material.setDiffuseColor(ofColor(255,255,255));
    material.setSpecularColor(ofColor(0,30,0));
    
    groundMesh = rawShape.getMesh();
    vector<ofVec3f> meshVerts = groundMesh.getVertices();
    
    for (int i = 0; i < groundMesh.getNumVertices(); i++) {
        int rando = ofRandom(100);
        ofVec3f tempVert = groundMesh.getVertices()[i];
        if (seed.getSurfaceShape() == Seed::PLANE)
            
            // Hills
            tempVert = ofVec3f(meshVerts[i].x, meshVerts[i].y, meshVerts[i].z+rando-70);
        
        // Sphere terrain
        else tempVert = ofVec3f(meshVerts[i].x, meshVerts[i].y+rando, meshVerts[i].z);
        
        groundMesh.getVertices()[i] = tempVert;
        
        // CAVE!
//        if (tempVert.y > 0){
//            groundMesh.getVertices()[i] = tempVert;
//        }
//        else groundMesh.getVertices()[i] = ofVec3f(0,0,0);
    }
    
}

void Ground::draw(){
    material.begin();
    ofSetColor(150, 75, 0);
    ofPushMatrix();
//    ofRotate(-90, 1, 0, 0);
    groundMesh.draw();
    material.end();
    ofPopMatrix();
}

void Ground::setColor(ofColor hue){
    
}

void Ground::update(){
    
}

vector<ofVec3f> Ground::getMeshVerts(){
    return groundMesh.getVertices();
}

vector<ofVec3f> Ground::getMeshNorms(){
    return groundMesh.getNormals();
}