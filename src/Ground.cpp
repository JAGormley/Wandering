//
//  Ground.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Ground.h"

Ground::Ground(Seed seed) : Surface(seed){
    
    groundCount = 0;
    
    material.setShininess(255);
    material.setDiffuseColor(ofColor(255,255,255));
    material.setSpecularColor(ofColor(0,30,0));
    
    vboMesh = rawShape.getMesh();
    
    vector<ofVec3f> meshVerts = vboMesh.getVertices();
    noiseGen(vboMesh.getNumVertices());
    for (int i = 0; i < vboMesh.getNumVertices(); i++) {

        float xCoord = ofMap(vboMesh.getVertices()[i].x, -2500, 2500, 0, 500);
        float yCoord = ofMap(vboMesh.getVertices()[i].y, -2500, 2500, 0, 500);
        
        float height = img.getColor(xCoord, yCoord).getBrightness()*3;
        
        // TODO: DENSITY
        // TODO: change to sphere terrain
        int rando = ofRandom(100);
        ofVec3f tempVert = vboMesh.getVertices()[i];
        
        
        // TERRAIN MANIPULATION
        if (seed.getSurfaceShape() == Seed::PLANE){
            
            // Hills
            tempVert = ofVec3f(meshVerts[i].x, meshVerts[i].y, meshVerts[i].z+height);
        }
        
        
        // Sphere terrain
        else tempVert = ofVec3f(meshVerts[i].x, meshVerts[i].y+rando, meshVerts[i].z);
        
        vboMesh.getVertices()[i] = tempVert;
        
        //         CAVE!
        //        if (tempVert.y > 0){
        //            vboMesh.getVertices()[i] = tempVert;
        //        }
        //        else vboMesh.getVertices()[i] = ofVec3f(0,0,0);
    }
    
}

void Ground::draw(){

    
// TERRAIN DEBUG ////////////

//    ofVec3f playerNode;
//    playerNode =  Player::playerLoc;
//    ofSpherePrimitive jimmy;
//    jimmy.set(7, 3);
//    vector<ofVec3f> groundVerts = vboMesh.getVertices();
//    for (int i = 0; i < groundVerts.size(); i++) {
//        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
//        
//        if ( (abs(currentVert.x-playerNode.x) < 150 ) &&
//            //            (abs(currentVert.y-playerNode.y) < 100 ) &&
//            (abs(currentVert.z-playerNode.z) < 150 )) {
//            ofSetColor(255,0,0);
//            jimmy.setPosition(currentVert);
//            jimmy.draw();
//        }
//        else {
//            ofSetColor(0,0,255);
//            jimmy.setPosition(currentVert);
//            jimmy.draw();
//        }
//    }
    
    
////////////////////////////
    
    material.begin();
    ofSetColor(150, 75, 0);
    ofPushMatrix();
    
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    // DEBUG
//    vboMesh.getVertices()[3000] = ofVec3f(vboMesh.getVertices()[3000].x, vboMesh.getVertices()[3000].y, ofGetMouseX());
    
    vboMesh.draw();
//    rawShape.drawAxes(100);
//    ofDrawAxis(600);
    material.end();
    ofPopMatrix();
}

void Ground::setColor(ofColor hue){
    
}

void Ground::update(){
    
}

vector<ofVec3f> Ground::getMeshVerts(){
    return vboMesh.getVertices();
}




