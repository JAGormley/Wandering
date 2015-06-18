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
        
        
        
        float xCoord = ofMap(vboMesh.getVertices()[i].x, -seed.shapeSize/2, seed.shapeSize/2, 0, 500);
        float yCoord = ofMap(vboMesh.getVertices()[i].y, -seed.shapeSize/2, seed.shapeSize/2, 0, 500);
        
        float height = heightMap.getColor(xCoord, yCoord).getBrightness()*7;
        
        // TODO: DENSITY
        // TODO: change to sphere terrain
        int rando = ofRandom(100);
        ofVec3f tempVert = vboMesh.getVertices()[i];
        
        
        // TERRAIN MANIPULATION
        if (seed.getSurfaceShape() == Seed::PLANE){
            
            // Hills
            tempVert = ofVec3f(meshVerts[i].x, meshVerts[i].y, height);
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
    
    ofVec3f playerNode = Player::playerLoc;
    vector<ofVec3f> groundVerts = vboMesh.getVertices();
    distances.clear();
    
    for (int i = 0; i < groundVerts.size(); i++) {
        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
        float distance = currentVert.distance(playerNode);
        if (distance < 500)
            distances.push_back(pair<int, int>(distance, i));
        if (distances.size() > 6){
            break;
        }
    }
    sort(distances.begin(), distances.end());
    
    if (distances.size() > 3){

        ofVec3f a = groundVerts[distances[0].second];
        ofVec3f b = groundVerts[distances[1].second];
        ofVec3f c = groundVerts[distances[2].second];
        
        ofSetColor(255,0,0);
        
        ofDrawSphere(a.x, a.y, a.z,7);
        ofDrawSphere(b.x, b.y, b.z,7);
        ofDrawSphere(c.x, c.y, c.z,7);
    }
    
    
    
    
    
    
    
    
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

