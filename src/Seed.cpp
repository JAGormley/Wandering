//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.



#include "Seed.h"


Seed::Seed(){
    sShape = SPHERE;
    sType = GROUND;
    medium = M_VOID;
}


of3dPrimitive Seed::getShape(){
    // TODO: Dynamically generate using Seed structure; this will come from SurfaceSeed
    
    return *new ofSpherePrimitive(1000, 32);
//    return *new ofPlanePrimitive(ofPlanePrimitive(5000, 5000, 50, 50));
}

float Seed::getRadius(){
    return 1100;
}
//
Seed::SurfaceShape Seed::getSurfaceShape(){
    return sShape;
}

Seed::SurfaceType Seed::getSurfaceType(){
    return sType;
}

Seed::Medium Seed::getMedium(){
    return medium;
}