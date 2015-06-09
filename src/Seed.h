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
#include "Controls.h"


//#ifndef __Wandering2__Surface__
//#define __Wandering2__Surface__
//
//#include "Surface.h"
//
//#endif /* defined(__Wandering2__Surface__) */

class Seed {
public:
    
    Seed();
//
    enum Traversal {FLOAT, WALK, FLY, ORBIT};
    enum Medium {M_WATER, M_VOID, AIR};
    enum SurfaceShape {SPHERE, PLANE};
    enum SurfaceType {S_WATER, S_VOID, GROUND, NONE};
//
    Traversal getTraversal();
    Medium getMedium();
    SurfaceShape getSurfaceShape();
    SurfaceType getSurfaceType();
    
    void setTraversal();
    void setMedium();
    void setSurfaceShape();
    void setSurfaceType();
    
    of3dPrimitive getShape();
    float getRadius();
    
    Traversal traversal;
    Medium medium;
    SurfaceShape sShape;
    SurfaceType sType;

};