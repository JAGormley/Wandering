//
//  Player.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-28.
//
//

#include "Player.h"

ofVec3f Player::playerLoc;

Player::Player(){
    controls.setCam(cam);
    
};

void Player::move(){
    controls.move();
    Player::playerLoc = cam.getPosition();
    //    cout << cam.getPosition() << endl;
    
    // debug: lock camera in place:
    //    cam.setPosition(ofVec3f(Light::getLightPos().x+10, Light::getLightPos().y+30,Light::getLightPos().z+10));
}

ofVec3f Player::getLocation(){
    ofVec3f pos = cam.getPosition();
    return pos;
}
void Player::startCam(){
    cam.begin();
}
void Player::stopCam(){
    cam.end();
}

void Player::draw(){
    cam.draw();
}

void Player::setMovementType(Seed lSeed){
    cam.resetTransform();
    controls.type = lSeed.getTraversal();
    if (lSeed.getTraversal() == Seed::ORBIT){
        controls.setOrbitRadius(lSeed.getPlayerLocation());
        cam.tilt(-20);
    }
}

Seed::Traversal Player::getMovementType(){
    return controls.type;
}

void Player::setLocation(Seed lSeed){
    
    // IDEMPOTENT ONLY!!
    
    if (lSeed.getTraversal() == Seed::ORBIT){
        cam.setPosition(ofVec3f(0, lSeed.getPlayerLocation(), 0));
    }
    else {
        cam.setPosition(ofVec3f(0, lSeed.getPlayerLocation(), 0));
        //        cam.lookAt(ofVec3f(0,0,283));
        
    };
}


// TODO: MOVE THIS LOGIC INTO SURFACE

void Player::setHeight(ofVboMesh groundMesh){
    
    ofVec3f playerNode = Player::playerLoc;
    vector<ofVec3f> groundVerts = groundMesh.getVertices();
    distances.clear();
    
    for (int i = 0; i < groundVerts.size(); i++) {
        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
        float distance = currentVert.distance(playerNode);
        if (distance < 500)
            distances.push_back(pair<float, int>(distance, i));
    }
    
    
    sort(distances.begin(), distances.end());
    
    if (distances.size() > 3){
        ofVec3f a = groundVerts[distances[0].second];
        ofVec3f b = groundVerts[distances[1].second];
        ofVec3f c = groundVerts[distances[2].second];
        
        float newHeight = getHeightApprox(playerNode, a, b, c);
        
        // DEBUG: player position crash becaused  cross.y is 0 sometimes...
//        cout << "NH: " << newHeight << endl;
        if (!isinf(newHeight))
            cam.setPosition(cam.getPosition().x, newHeight+30, cam.getPosition().z);
    }
}


/* adapted following two functions from here: http://stackoverflow.com/questions/26273131/smooth-terrain-collision-3d*/

float Player::getNewHeight(float posX, float posZ, ofVec3f a, ofVec3f b, ofVec3f c){
    // get triangle normal
    ofVec3f nVec1 = b - a;
    ofVec3f nVec2 = c - a;
    
    ofVec3f nCross = nVec1.cross(nVec2);
    nCross.normalize();
    
    float d = -(a.x * nCross.x + a.y * nCross.y + a.z * nCross.z);
    
//    cout << nCross.y << endl;
    
    return -(d + nCross.z * posZ + nCross.x * posX)/nCross.y;
}
float Player::getHeightApprox(ofVec3f playerPos, ofVec3f a, ofVec3f b, ofVec3f c)
{
    return ( (getNewHeight(playerPos.x,playerPos.z, a,b,c)
              + getNewHeight(playerPos.x + 1, playerPos.z, a,b,c)
              + getNewHeight(playerPos.x - 1, playerPos.z, a,b,c)
              + getNewHeight(playerPos.x, playerPos.z + 1, a,b,c)
              + getNewHeight(playerPos.x, playerPos.z - 1, a,b,c)) / 5);
}

//ofVec3f Player::getPlayerLoc(){
//    return Player::playerLoc;
//}
