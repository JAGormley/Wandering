//
//  Seed.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"


//#ifndef __Wandering2__Surface__
//#define __Wandering2__Surface__
//
//#include "Surface.h"
//
//#endif /* defined(__Wandering2__Surface__) */

class Seed {
public:
    
    Seed();
    void populate();
    
    // ENVIRONMENT
    
    enum Medium {M_WATER, M_VOID, AIR};
    enum SurfaceShape {SPHERE, PLANE};
    enum SurfaceType {S_WATER, S_VOID, GROUND, NONE};
    
    Medium getMedium();
    SurfaceShape getSurfaceShape();
    SurfaceType getSurfaceType();
    
    void setMedium();
    void setSurfaceShape();
    void setSurfaceType();
    
    Medium medium;
    SurfaceShape sShape;
    SurfaceType sType;
    float shapeSize;
    
    
    // PLAYER
    enum Traversal {FLOAT, WALK, FLY, ORBIT};
    Traversal getTraversal();
    void setTraversal();
    float getPlayerLocation();
    
    Traversal traversal;
    
    
    // LIGHT

};