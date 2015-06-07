//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.



#include "Seed.h"


of3dPrimitive Seed::getShape(){
    // TODO: Dynamically generate using Seed structure; this will come from SurfaceSeed
    
    return *new ofSpherePrimitive(1000, 32);
//    return *new ofPlanePrimitive(ofPlanePrimitive(5000, 5000, 50, 50));
}

float Seed::getRadius(){
    return 1100;
}