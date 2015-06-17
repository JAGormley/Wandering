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
    
    //    ofVec3f playerNode;
    //    playerNode =  Player::playerLoc;
    //    ofSpherePrimitive jimmy;
    //    jimmy.set(7, 3);
    //    vector<ofVec3f> groundVerts = vboMesh.getVertices();
    //    for (int i = 0; i < groundVerts.size(); i++) {
    //        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
    //
    //        if ( (abs(currentVert.x-playerNode.x) < 150 ) &&
    //            //            (abs(currentVert.y-playerNode.y) < 100 ) &&
    //            (abs(currentVert.z-playerNode.z) < 150 )) {
    //            ofSetColor(255,0,0);
    //            jimmy.setPosition(currentVert);
    //            jimmy.draw();
    //        }
    //    }
    
    
    ofVec3f playerNode = Player::playerLoc;
    //    cout << "PLAYER: " << playerNode << endl;
    int heightCounter = 0;
    float height;
    //    deque<ofVec3f> points;
    vector<ofVec3f> groundVerts = vboMesh.getVertices();
    // init vector with very far points
    if (points.size() == 0)
        for (int i = 0; i < 3; i++) {
            points.push_back(ofVec3f(100000,100000,100000));
        }
    
    ofSpherePrimitive jimmy;
    jimmy.set(7, 3);
    for (int i = 0; i < groundVerts.size(); i++) {
        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
        
        std::deque<ofVec3f>::iterator it = points.begin();
        
        if (playerNode.distance(currentVert) < playerNode.distance(points[0])){
            points.insert (it,currentVert);
            cout << "1" << endl;
        }
        else if (playerNode.distance(currentVert) < playerNode.distance(points[1])){
            it = points.begin()+1;
            points.insert (it,currentVert);
            cout << "2" << endl;
        }
        else if (playerNode.distance(currentVert) < playerNode.distance(points[2])){
            it = points.begin()+2;
            points.insert (it,currentVert);
            cout << "3" << endl;
        }
    }
    ofSetColor(255,0,0);
//    ofDrawSphere(points[0].x, points[0].y, points[0].z,7);
//    ofDrawSphere(points[1].x, points[1].y, points[1].z,7);
//    ofDrawSphere(points[2].x, points[2].y, points[2].z,7);
    
    cout << "1:"<< points[0] << endl;
    cout << "2:"<<  points[1] << endl;
    cout << "3:"<<  points[2] << endl;
    
    
    
    
    
    
    
    
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




