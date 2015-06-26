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
//
//void SpriteSeed::populate(){
//
//}

bool SpriteSeed::isOrbital(){
    return (seed.traversal == Seed::ORBIT);
}

float SpriteSeed::getOrbitHeight(){
    if (this->isOrbital())
        return seed.getOrbitHeight()-seed.shapeSize-10;
    else
        return 100;
}

ofVec3f SpriteSeed::spritePos(){
    int vertIndex = ofRandom(sVerts.size());
    return sVerts[vertIndex];
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