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
    
    ofVboMesh vCloud;
    for (int i = 0; i < 10; i++) {
        float angle = ofRandom(360);
        int rando = ofRandom(6000)-3000;
        int rando2 = ofRandom(100)-50;
        int rando3 = ofRandom(100)-50;
        
        vCloud = generateCloud();
        vector<ofVec3f>tempVerts = vCloud.getVertices();
        
        //        // move the cloud's vertices to new location
        for (int j = 0; j < tempVerts.size(); j++) {
            //            ofVboMesh tempCloud = generateCloud();
            ofVec3f tempster = ofVec3f(tempVerts[j].x+20000*cos(angle)+rando2, tempVerts[j].y+1000, tempVerts[j].z+20000*sin(angle)+rando3);
//            tempster.rotateRad(angle, ofVec3f(0,1,0));
            vCloud.getVertices()[j] = tempster;
        }
        
        // add the vertices to the mesh
        airMesh.append(vCloud);
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
    ofVboMesh vCloud;
    float cloudSize = 2000.0;
    int numSpheres = ofRandom(10)+20;
    int prevWidth = 0;
    
    ofSpherePrimitive cloud;
    cloud.set(cloudSize, 5, OF_PRIMITIVE_TRIANGLES);
    ofVboMesh tempMesh;
    
    for (int i = 0; i < numSpheres; i++) {
        float height = ofRandom(cloudSize*3.0);
        float width = ofRandom(cloudSize*4);
        float depth = ofRandom(cloudSize*2);
        
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