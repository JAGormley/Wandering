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
    
    

    
//    intersectionPlane.setFrom(groundMesh);
    
//    ofVec3f playerNode = cam.getPosition();
////    cout << "PLAYER: " << playerNode << endl;
//    int heightCounter = 0;
//    float height;
//    for (int i = 0; i < groundVerts.size(); i++) {
//        ofVec3f currentVert = groundVerts[i].rotate(-90, ofVec3f(1,0,0));
//        if ( (abs(currentVert.x-playerNode.x) < 30 ) &&
////            (abs(currentVert.y-playerNode.y) < 100 ) &&
//            (abs(currentVert.z-playerNode.z) < 30 )) {
//            
//            heightCounter++;
//            height += currentVert.y;
//            
//            cout << "VERT: " << currentVert << endl;
//        }
//    }
//    height /= heightCounter+1;
//    cout << height << endl;
//    cam.setPosition(cam.getPosition().x, -height, cam.getPosition().z);
    
    
    
    
}


//ofVec3f Player::getPlayerLoc(){
//    return Player::playerLoc;
//}
