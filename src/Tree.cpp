//
//  Tree.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-24.
//
//

#include "Tree.h"


Tree::Tree(SpriteSeed spriteSeed) : Plant(spriteSeed){
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    ofColor matCol(0,128,0);
//    matCol.setBrightness(200);
    //    material.setEmissiveColor(materialColor);
    material.setShininess(10);
    material.setDiffuseColor(matCol);
//    material.setSpecularColor(matCol);
    
    
    
    float sizeDiv = (sSeed.isOrbital()) ? 1000.0 : 2000.0;
    size = sSeed.getShapeSize()/sizeDiv;
    pos = sSeed.spritePos();
    float sizeMult =  ofRandom(.7) + .5;
    size *= sizeMult;
    
    stem.set(4*size, 300*size);
    stem.setPosition(pos);
    
//    top.setParent(stem);
    top.set(50*size, 200*size);
    top.boom(150*size);
    top.rotate(180, ofVec3f(1,0,0));
    top.setMode(OF_PRIMITIVE_LINE_LOOP);
    this->setup();
    
    // Debug: fix this
    leaves = generateLeaves();
}

void Tree::setup(){
    if (sSeed.isOrbital()){
        q.makeRotate(ofVec3f(0, sSeed.getShapeSize(), 0), pos);
        stem.rotate(q);
        stem.boom(100);
    }
    else {
        stem.rotateAround(-90, ofVec3f(1,0,0), ofVec3f(0,0,0));
    }
}


// DEBUG: Translation but not rotation working
ofVboMesh Tree::generateLeaves(){
    ofVboMesh vLeaves;
    vLeaves.setMode(OF_PRIMITIVE_TRIANGLES);
    float leafSize = 6;
    int numLeaves = ofRandom(10)+20;
    
    ofConePrimitive leaf;
    leaf.set(leafSize, leafSize);
    leaf.setMode(OF_PRIMITIVE_TRIANGLES);
    ofVboMesh tempMesh;
    ofVec3f stemPos = stem.getPosition();
    
    for (int i = 0; i < numLeaves; i++) {
        float height = ofRandom(50);
        float width = ofRandom(50);
        float depth = ofRandom(50);

        tempMesh = leaf.getMesh();
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        
        
        
        for (int j = 0; j < tempVerts.size(); j++) {
            ofVec3f tempster = ofVec3f(tempVerts[j].x,
                                       tempVerts[j].y,
                                       tempVerts[j].z);
            
            
            // DEBUG: q has no useful value in it
//            float angle = 2 * acos(q.w());
//            float x = q.x() / sqrt(1-q.w()*q.w());
//            float y = q.y() / sqrt(1-q.w()*q.w());
//            float z = q.z() / sqrt(1-q.w()*q.w());
//            ofVec3f axis(x,y,z);
//            tempster.rotate(angle, axis);
            
//            float angle = tempster.angle(stem.getUpDir());
//            tempster.rotate(-30, ofVec3f(1,0,0));
            tempMesh.getVertices()[j] = tempster;
        }
        vLeaves.append(tempMesh);
    }
    return vLeaves;
}