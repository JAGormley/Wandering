//
//  mVoid.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "mVoid.h"

mVoid::mVoid(Seed seed) : Medium(seed){
    this->seed = seed;
    ofBackground(0, 0, 0);
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    ofColor c(255,255,255);
    c.setBrightness( 255 );
    
    voidMaterial.setShininess(255);
    voidMaterial.setDiffuseColor(c);
    voidMaterial.setSpecularColor(c);
    voidMaterial.setEmissiveColor(c);
    
    // Star Field
    ofSpherePrimitive sphere;
    
    int walkSetter = (seed.getTraversal() == Seed::ORBIT) ? 1 : 5;
    sphere.set(6*walkSetter, 3, OF_PRIMITIVE_TRIANGLES);
    ofMesh tempMesh;
    
    for (int i = 0; i < 15000; i++) {
        
        float angle = ofRandom(360);
        int zHeight = ofRandom(10000)+4000;
        int starDist = ofRandom(15000)-5000;
        
        float x = (seed.shapeSize+starDist/walkSetter) * cos(angle) * sin(zHeight);
        float y = (seed.shapeSize+starDist/walkSetter) * sin(angle) * sin(zHeight);
        float z = (seed.shapeSize+starDist/walkSetter) * cos(zHeight);
        
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
    
    if (seed.getTraversal() != Seed::ORBIT){
        ofPushMatrix();
        ofTranslate(Player::playerLoc.x, 0, Player::playerLoc.z);
        voidMesh.draw(OF_MESH_FILL);
        ofPopMatrix();
    }
    else {
        voidMesh.draw(OF_MESH_FILL);
    }
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