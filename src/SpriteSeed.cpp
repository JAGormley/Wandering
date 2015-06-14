//
//  SpriteSeed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-13.
//
//

#include "SpriteSeed.h"

SpriteSeed::SpriteSeed(){};

SpriteSeed::SpriteSeed(Seed seed, vector<ofVec3f> surfaceVerts){
    sVerts = surfaceVerts;
    this->seed = seed;
}
//
//void SpriteSeed::populate(){
//
//}

bool SpriteSeed::isOrbital(){
    return (seed.traversal == Seed::ORBIT);
}

ofVec3f SpriteSeed::spritePos(){
    int vertIndex = ofRandom(sVerts.size());
    return sVerts[vertIndex];
}