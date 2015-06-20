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
#include "History.h"


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
    
    enum Medium {AIR, M_VOID, M_WATER};
    enum SurfaceShape {SPHERE, PLANE};
    enum SurfaceType {S_WATER, GROUND, S_VOID, NONE};
    
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
    enum Traversal {ORBIT, WALK, FLOAT, FLY};
    Traversal getTraversal();
    void setTraversal();
    float getOrbitHeight();
    
    Traversal traversal;
    
    
    // LIGHT
    enum LightType {SUN, MOON, CLOUDY};
    void setLightType();
    LightType getLightType();
    LightType lightType;
    
    
    // HISTORY
    
    History history;
    
    
    

};