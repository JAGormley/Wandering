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
    
//    groundMesh.ge

    
    
    
    vector<ofVec3f> groundVerts = groundMesh.getVertices();
    
////    intersectionPlane.setFrom(groundMesh);
//    
    ofVec3f playerNode = cam.getPosition();
//    cout << "PLAYER: " << playerNode << endl;
    int heightCounter = 0;
    float height;
    deque<ofVec3f> points;
    
    // init vector with very far points
    for (int i = 0; i < 3; i++) {
        points.push_back(ofVec3f(100000,100000,100000));
    }
    
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
        
        
//        if ( (abs(currentVert.x-playerNode.x) < 200 ) &&
////            (abs(currentVert.y-playerNode.y) < 100 ) &&
//            (abs(currentVert.z-playerNode.z) < 200 )) {
//            
//            cam.setPosition(cam.getPosition().x, currentVert.y, cam.getPosition().z);
    
//            heightCounter++;
//            height += currentVert.y;
//            
//            cout << "VERT: " << currentVert << endl;
//        }
//    }
//    height /= heightCounter+1;
//    cout << height << endl;
    
    

}


//ofVec3f Player::getPlayerLoc(){
//    return Player::playerLoc;
//}
