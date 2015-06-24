//
//  Air.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#include "Air.h"


Air::Air(Seed seed) : Medium(seed){
    ofBackground(0, 127, 255);
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
    
    
    for (int i = 0; i < 500; i++) {
        ofSpherePrimitive cloud;
        cloud.set(1000, 5, OF_PRIMITIVE_TRIANGLES);
        ofVboMesh tempMesh;
        tempMesh = cloud.getMesh();
        
        vector<ofVec3f>tempVerts = tempMesh.getVertices();
        
        float angle = ofRandom(6.0);
        int rando = ofRandom(6000)-3000;
        int rando2 = ofRandom(100)-50;
        int rando3 = ofRandom(100)-50;
        
        // move the sphere's vertices to new location
        for (int j = 0; j < tempVerts.size(); j++) {
//            ofVboMesh tempCloud = generateCloud();
            ofVec3f tempster = ofVec3f(tempVerts[j].x+8000*cos(angle)+rando2, tempVerts[j].y+1000, tempVerts[j].z+8000*sin(angle)+rando3);
            tempMesh.getVertices()[j] = tempster;
        }
        
        // add the vertices to the mesh
        airMesh.append(tempMesh);
    }
}

void Air::draw(){
    ofSetColor(255, 255, 255, 200);
//    testCloud.draw();
    
    airMaterial.begin();
    airMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    airMesh.draw(OF_MESH_FILL);
    airMaterial.end();
}


void Air::setColor(ofColor hue){
    
}
void Air::update(){
//    float map = ofMap(ofGetMouseX(), -130, 3069, 0, 6);
//    testCloud.setPosition(8000*cos(map), ofGetMouseY()*100, 8000*sin(map));
//    testCloud.lookAt(ofVec3f(0, 0, 0));
//    testCloud.rotate(90, testCloud.getXAxis());
    
}


ofVboMesh Air::generateCloud(){
    
}


vector<ofVec3f> Air::getMeshVerts(){
    return airMesh.getVertices();
}