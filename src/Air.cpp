//
//  Air.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "Air.h"


Air::Air(Seed seed) : Medium(seed){
    ofBackground(135,206,250);
    testCloud.set(1000, 5, 100, 1);
    //    testCloud.rotate(90, 1, 0, 0);
    
    //    testCloud.setPosition(300*cos(180), 0, 300*sin(180));
    
    
    // SETUP MATERIAL
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(255);
    ofColor c(255,255,255);
    c.setBrightness( 255 );
    ofFloatColor white = ofColor::white;
    airMaterial.setShininess(255);
    airMaterial.setDiffuseColor(c);
    airMaterial.setSpecularColor(c);
    airMaterial.setEmissiveColor(c);
    
    ofVboMesh vCloud;
    for (int i = 0; i < 10; i++) {
        float angle = ofRandom(360);
        int rando = ofRandom(500);
        int rando2 = ofRandom(100)-50;
        int rando3 = ofRandom(100)-50;
        
        vCloud = generateCloud();
        vector<ofVec3f>tempVerts = vCloud.getVertices();
        
        //        // move the cloud's vertices to new location
        for (int j = 0; j < tempVerts.size(); j++) {
            ofVec3f tempster = ofVec3f(tempVerts[j].x+15000*cos(angle)+rando2,
                                       tempVerts[j].y+1000+rando,
                                       tempVerts[j].z+15000*sin(angle)+rando3);
            vCloud.getVertices()[j] = tempster;
        }
        
        // add the vertices to the mesh
        airMesh.append(vCloud);
    }
}

void Air::draw(){
    ofSetColor(255, 255, 255, 150);
    //    testCloud.draw();
    
    airMaterial.begin();
    airMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    ofPushMatrix();
    ofTranslate(Player::playerLoc.x, 0, Player::playerLoc.z);
    ofRotate(ofGetFrameNum()/50.0, 0, 1, 0);
    airMesh.draw(OF_MESH_FILL);
    ofPopMatrix();
    airMaterial.end();
}


void Air::setColor(ofColor hue){
    
}
void Air::update(){
    
}


ofVboMesh Air::generateCloud(){
    ofVboMesh vCloud;
    float cloudSize = ofRandom(500.0)+1000.0;
    int numSpheres = ofRandom(10)+20;
    int prevWidth = 0;
    
    ofSpherePrimitive cloud;
    cloud.set(cloudSize, 5, OF_PRIMITIVE_TRIANGLES);
    ofVboMesh tempMesh;
    
    for (int i = 0; i < numSpheres; i++) {
        float height = ofRandom(cloudSize*3);
        float width = ofRandom(cloudSize*4)+cloudSize;
        float depth = ofRandom(cloudSize);
        
        tempMesh = cloud.getMesh();
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        for (int j = 0; j < tempVerts.size(); j++) {
            //            ofVboMesh tempCloud = generateCloud();
            ofVec3f tempster = ofVec3f(tempVerts[j].x+width+prevWidth, tempVerts[j].y+height, tempVerts[j].z+depth);
            tempMesh.getVertices()[j] = tempster;
        }
        prevWidth = width;
        
        vCloud.append(tempMesh);
    }
    return vCloud;
}


vector<ofVec3f> Air::getMeshVerts(){
    return airMesh.getVertices();
}