//
//  Ground.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Ground.h"

Ground::Ground(Seed seed) : Surface(seed){
    surfaceRes = 499;
    surfaceHeightMult = 7;
    
    surfaceID = 0;
    rawShape.drawAxes(100);
    groundCount = 0;
    
    ofColor matCol(205,133,63);
    matCol.setBrightness(255);
    material.setDiffuseColor(matCol);
    //    material.setSpecularColor(ofColor(255,255,255));
    
    vboMesh = rawShape.getMesh();
    vector<ofVec3f> meshVerts = vboMesh.getVertices();
    noiseGen(vboMesh.getNumVertices());
    for (int i = 0; i < vboMesh.getNumVertices(); i++) {
        
        // TODO: DENSITY
        // TODO: change to sphere terrain
        int rando = ofRandom(100);
        ofVec3f tempVert = vboMesh.getVertices()[i];
        
        
        // TERRAIN MANIPULATION
        if (seed.getSurfaceShape() == Seed::PLANE){
            
            // Hills
            int xCoord = ofMap(vboMesh.getVertices()[i].x, -seed.shapeSize/2, seed.shapeSize/2, 0, surfaceRes);
            int yCoord = ofMap(vboMesh.getVertices()[i].y, -seed.shapeSize/2, seed.shapeSize/2, 0, surfaceRes);
            float height = heightMapi[xCoord][yCoord]*surfaceHeightMult;
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
    
    for (int i = 0; i < vboMesh.getIndices().size(); i++) {
        int inSize = vboMesh.getIndices().size();
        int patchSize = inSize/600;
        int colDex = (i-patchSize < 0) ? 0: i-patchSize;
        if (ofRandom(1.0) < .01)
            vboMesh.setColorForIndices(colDex, i, ofColor(222,184,135));
    }
}


void Ground::update(){
//    if (ofGetKeyPressed()){
//        addVRow();
//    }
}

void Ground::draw(){
    
    terrainDebug();
    
    ////////////////////////////
    
    material.begin();
    ofSetColor(222,184,135);
    ofPushMatrix();
    
    if (seed.getSurfaceShape() != Seed::SPHERE)
        ofRotate(-90, 1, 0, 0);
    
    vboMesh.draw();
    
    ofSetColor(255, 0, 0);
    for (int i = 0; i < seed.numCols+1; i++) {
        ofVec3f temp = vboMesh.getVertices()[vboMesh.getVertices().size()-i];
        ofSphere(temp, 2);
    }
    ofSetColor(0, 0, 255);
    
    ofDrawAxis(600);
    material.end();
    ofPopMatrix();
    
}


void Ground::setColor(ofColor hue){
    
}

vector<ofVec3f> Ground::getMeshVerts(){
    return vboMesh.getVertices();
}


// DEBUG FUNCTION

void Ground::terrainDebug(){
    
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
}
