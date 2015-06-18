//
//  Player.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#pragma once

#include "ofxLeapMotion2.h"
#include "Controls.h"
#include "Light.h"
#include "ofxRay.h"
#include <stdio.h>



class Player {
public:
    
    Player();
    void setHeight(ofVboMesh groundMesh);
    void move();
    ofVec3f getLocation();
    void draw();
    void startCam();
    void stopCam();
    void setMovementType(Seed lSeed);
    void setLocation(Seed lSeed);
    float getNewHeight(float posX, float posY, ofVec3f a, ofVec3f b, ofVec3f c);
    float getHeightApprox(ofVec3f playerPos, ofVec3f a, ofVec3f b, ofVec3f c);
    Seed::Traversal getMovementType();
    
    
    ofCamera cam;
//    static ofVec3f playerLoc;
    
   static ofVec3f playerLoc;
//    static void init(){
//        
//    }

private:
    Controls controls;
    ofRay playerRay;
    ofPlane intersectionPlane;
    vector<pair<int, int> > distances;
    float safeY;
};

