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
    
    ofSpherePrimitive sphere;
    sphere.set(6, 3, OF_PRIMITIVE_TRIANGLES);
    ofMesh tempMesh;
    
//    // TODO: set stars using sphere math, not generate and test
//    // STAR POPULATION
    
    for (int i = 0; i < 15000; i++) {
        
        
        float angle = ofRandom(360);
        int zHeight = ofRandom(10000)+4000;
        int starDist = ofRandom(15000)-5000;
        
        float x = (seed.shapeSize+starDist) * cos(angle) * sin(zHeight);
        float y = (seed.shapeSize+starDist) * sin(angle) * sin(zHeight);
        float z = (seed.shapeSize+starDist) * cos(zHeight);
        
        
        sphere.setPosition(x, y, z);
        ofVec3f sPos = sphere.getPosition();
        tempMesh = sphere.getMesh();
        
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        
            // move the sphere's vertices to new location
            for (int j = 0; j < tempVerts.size(); j++) {
                ofVec3f tempster = ofVec3f(tempVerts[j].x+sPos.x,
                                           tempVerts[j].y+sPos.y,
                                           tempVerts[j].z+sPos.z);
                tempMesh.getVertices()[j] = tempster;
            }
            
            // add the vertices to the mesh
            voidMesh.append(tempMesh);
    }
    
    
    
    
    
}

void mVoid::draw(){
    ofSetColor(255, 255, 255);
    voidMaterial.begin();
    voidMesh.setMode(OF_PRIMITIVE_TRIANGLES);
//    ofPushMatrix();
//    ofTranslate(Player::playerLoc.x, 0, Player::playerLoc.z);
    voidMesh.draw(OF_MESH_FILL);
//    ofPopMatrix();
    ofDrawAxis(600);
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