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
    
    void move();
    ofVec3f getLocation();
    void draw();
    void startCam();
    void stopCam();
    void setMovementType();
    void setInitHeight();
    void setSurface(ofVboMesh surfaceMesh);
    void setSeed(Seed seed);
    float getNewHeight(float posX, float posY, ofVec3f a, ofVec3f b, ofVec3f c);
    float getHeightApprox(ofVec3f playerPos, ofVec3f a, ofVec3f b, ofVec3f c);
    void setNewHeight();
    Seed::Traversal getMovementType();
    ofVboMesh surfaceMesh;
    
    ofCamera cam;
   static ofVec3f playerLoc;

private:
    void setOrbitHeight();
    void setPlaneHeight();
    
    Controls controls;
    Seed seed;
    vector<pair<float, int> > distances;
    float safeY;
};

