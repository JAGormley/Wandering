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
    
    for (int i = 0; i < 10; i++) {
        vector<ofSpherePrimitive> tempClouds;
        tempClouds = generateSCloud();
        float angle = ofRandom(360);
        int depth = ofRandom(500)-200;
        int height = ofRandom(1000)+150;
        
        for (int j = 0; j < tempClouds.size(); j++) {
            ofVboMesh vCloud;
            tempClouds[j].dolly(seed.shapeSize/2+depth);
            tempClouds[j].rotateAround(angle, ofVec3f(0,1,0), ofVec3f(0,0,0));
            tempClouds[j].boom(height);
            tempClouds[j].setMode(OF_PRIMITIVE_TRIANGLES);
            ofVec3f cloudPos = tempClouds[j].getPosition();
            
            vector<ofVec3f>tempVerts = tempClouds[j].getMesh().getVertices();
            for (int k = 0; k < tempVerts.size(); k++) {
                ofVec3f tempster = ofVec3f(tempVerts[k].x+cloudPos.x,
                                           tempVerts[k].y+cloudPos.y,
                                           tempVerts[k].z+cloudPos.z);
                tempClouds[j].getMesh().getVertices()[k] = tempster;
            }
            airMesh.append(tempClouds[j].getMesh());
        }
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

vector<ofSpherePrimitive> Air::generateSCloud(){
    vector<ofSpherePrimitive> vCloud;
    float cloudSize = ofRandom(500.0)+1000.0;
    int numSpheres = ofRandom(10)+20;
    int prevWidth = 0;
    
    ofSpherePrimitive cloud;
    cloud.set(cloudSize, 5, OF_PRIMITIVE_TRIANGLES);
    
    for (int i = 0; i < numSpheres; i++) {
        float height = ofRandom(cloudSize*3);
        float width = ofRandom(cloudSize*4)+cloudSize;
        float depth = ofRandom(cloudSize);
        
        ofVec3f tempster = ofVec3f(width+prevWidth, height, depth);
        cloud.setPosition(tempster);
        prevWidth = width;
        vCloud.push_back(cloud);
    }
    return vCloud;
    
}


vector<ofVec3f> Air::getMeshVerts(){
    return airMesh.getVertices();
}