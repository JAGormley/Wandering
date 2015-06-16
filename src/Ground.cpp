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
    
    for (int i = 0; i < vboMesh.getNumVertices(); i++) {
        // TODO: DENSITY
        int rando = ofRandom(100);
        int rando2 = ofRandom(800);
        ofVec3f tempVert = vboMesh.getVertices()[i];
        
        
        // TERRAIN MANIPULATION
        if (seed.getSurfaceShape() == Seed::PLANE)
            
            // Hills
            tempVert = ofVec3f(meshVerts[i].x+rando2-400, meshVerts[i].y+rando2-400, meshVerts[i].z+rando-70);
        
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
    if (ofGetKeyPressed()){groundCount++;}
    cout << Player::playerLoc << endl;
    ofVec3f playerNode;
    playerNode =  Player::playerLoc;
    vector<ofVec3f> groundVerts = vboMesh.getVertices();
    for (int i = 0; i < groundVerts.size(); i++) {
        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
        ofSpherePrimitive jimmy;
        jimmy.set(10, 10);
        if ( (abs(currentVert.x-playerNode.x) < 500 ) &&
            //            (abs(currentVert.y-playerNode.y) < 100 ) &&
            (abs(currentVert.z-playerNode.z) < 500 )) {
            ofSpherePrimitive jimmy;
            jimmy.set(10, 10);
            ofSetColor(255, 0,0);//
            jimmy.setPosition(currentVert);
            jimmy.draw();
        }
        else {
//            ofSetColor(0, 0,255);//
//            jimmy.setPosition(currentVert);
//            jimmy.draw();
        }
    }
    
    
    
    // MESH HEIGHT DEBUG:
    ofVec3f groundNode = vboMesh.getVertices()[groundCount];
    ofSpherePrimitive jimmy;
    jimmy.set(10, 10);
    ofSetColor(255, 0,0);//
    jimmy.setPosition(groundNode);
    jimmy.draw();
    
    material.begin();
    ofSetColor(150, 75, 0);
    ofPushMatrix();
    
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    vboMesh.draw();
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