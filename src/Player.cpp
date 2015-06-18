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
    cam.setPosition(cam.getPosition().x, 1100, cam.getPosition().z);
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
        cam.lookAt(ofVec3f(0,0,283));
        
    };
}


void Player::setHeight(ofVboMesh groundMesh){
    
    //    groundMesh.ge
    
    //    cam.setPosition(cam.getPosition().x, 1100, cam.getPosition().z);
    
    ofVec3f playerNode = Player::playerLoc;
    vector<ofVec3f> groundVerts = groundMesh.getVertices();
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
        
        cam.setPosition(cam.getPosition().x, a.y+30, cam.getPosition().z);
    }
    
    
    
}


//ofVec3f Player::getPlayerLoc(){
//    return Player::playerLoc;
//}
