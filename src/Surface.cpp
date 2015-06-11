//
//  Surface.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Surface.h"


Surface::Surface(Seed seed){this->seed = seed;};


void Surface::generate(){
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(seed.shapeSize, 32);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(seed.shapeSize*5, seed.shapeSize*5, 30, 30);
            break;
    }
}

void Surface::draw(){
    
}