//
//  Tree.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-24.
//
//

#ifndef __Wandering2__Tree__
#define __Wandering2__Tree__

#include <stdio.h>
#include "Plant.h"

#endif /* defined(__Wandering2__Tree__) */


class Tree : public Plant {
public:
    
    Tree(SpriteSeed spriteSeed);
    void setup();
    ofVboMesh generateLeaves();
};