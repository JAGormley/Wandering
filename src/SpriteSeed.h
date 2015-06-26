//
//  SpriteSeed.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-13.
//
//

#ifndef __Wandering2__SpriteSeed__
#define __Wandering2__SpriteSeed__

#include <stdio.h>
#include "Seed.h"

#endif /* defined(__Wandering2__SpriteSeed__) */


class SpriteSeed {
public:
    SpriteSeed();
    SpriteSeed(Seed seed, ofVboMesh surfaceMesh);
    int getShapeSize();
    bool isOrbital();
    ofVec3f spritePos();
    int getMoveDiv();
    float getOrbitHeight();
    
    vector<ofVec3f> sVerts;
    
    Seed seed;
    
};