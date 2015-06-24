//
//  mVoid.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "mVoid.h"

mVoid::mVoid(Seed seed) : Medium(seed){
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    //    colorHue = 100;
    ofColor c(255,255,255);
    c.setBrightness( 255 );
    ofFloatColor white = ofColor::white;
    //    materialColor.setHue(c);
    
    
    voidMaterial.setShininess(255);
    voidMaterial.setDiffuseColor(c);
    voidMaterial.setSpecularColor(c);
    voidMaterial.setEmissiveColor(c);
    
    ofBackground(0, 0, 0);
    
    
    // STAR POPULATION
    for (int i = 0; i < 10000; i++) {
        ofSpherePrimitive sphere;
        //        sphere.
        sphere.set(6, 3, OF_PRIMITIVE_TRIANGLES);
        ofMesh tempMesh;
        tempMesh = sphere.getMesh();
        
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        
        float randoX = ofRandom(12000)-6000;
        float randoY = ofRandom(12000)-6000;
        float randoZ = ofRandom(12000)-6000;
        
        ofVec3f candidate(randoX,randoY,randoZ);
        if (Player::playerLoc.distance(candidate) > 5000){
            
            // move the sphere's vertices to new location
            for (int j = 0; j < tempVerts.size(); j++) {
                
                ofVec3f tempster = ofVec3f(tempVerts[j].x+randoX, tempVerts[j].y+randoY, tempVerts[j].z+randoZ);
                tempMesh.getVertices()[j] = tempster;
            }
            
            // add the vertices to the mesh
            voidMesh.append(tempMesh);
        }
    }
}

void mVoid::draw(){
    ofSetColor(255, 255, 255);
    voidMaterial.begin();
    voidMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    ofPushMatrix();
    ofTranslate(Player::playerLoc.x, 0, Player::playerLoc.z);
    voidMesh.draw(OF_MESH_FILL);
    ofPopMatrix();
    //    one.draw();
    voidMaterial.end();
}


void mVoid::setColor(ofColor hue){
    
}
void mVoid::update(){
    
}

vector<ofVec3f> mVoid::getMeshVerts(){
    return voidMesh.getVertices();
}

//mVoid::~mVoid(){}