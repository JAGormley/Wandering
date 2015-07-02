//
//  SpriteSeed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-13.
//
//

#include "SpriteSeed.h"

SpriteSeed::SpriteSeed(){};

SpriteSeed::SpriteSeed(Seed seed, ofVboMesh surfaceMesh){
    sVerts = surfaceMesh.getVertices();
    this->seed = seed;
}



bool SpriteSeed::isOrbital(){
    return (seed.traversal == Seed::ORBIT);
}



// set Sprite position depending on seed data

float SpriteSeed::getOrbitHeight(){
    if (this->isOrbital())
        return seed.getOrbitHeight()-seed.shapeSize-10;
    else
        return 100;
}



ofVec3f SpriteSeed::plantPos(){
    
        int vertIndex = ofRandom(sVerts.size());
        return sVerts[vertIndex];
    
}

ofVec3f SpriteSeed::animalPos(){
    
    if (seed.traversal != Seed::FLY){
        int vertIndex = ofRandom(sVerts.size());
        return sVerts[vertIndex];
    }
    else {
        
        int x = Player::playerLoc.x + ofRandom(2000)-1000;
        int y = Player::playerLoc.y + ofRandom(2000)-1000;
        int z = Player::playerLoc.z + ofRandom(2000)-1000;
        int clampY = ofClamp(y, 200, 4000);
        
        ofVec3f flyLoc(x,clampY,z);
        return flyLoc;
    }
}


int SpriteSeed::getShapeSize(){
    return seed.shapeSize;
}

int SpriteSeed::getMoveDiv(){
    if (seed.traversal == Seed::ORBIT){
        return 3;
    }
    else return 1;
}