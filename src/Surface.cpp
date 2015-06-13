//
//  Surface.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Surface.h"


Surface::Surface(Seed seed){
    this->seed = seed;
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(seed.shapeSize, 64);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(seed.shapeSize*10, seed.shapeSize*10, 30, 30);
            //            rawShape =ofBoxPrimitive(seed.shapeSize, seed.shapeSize, seed.shapeSize);
            break;
    }
};



// TODO: PROBABLY DELETE THIS FUNCTION
void Surface::generate(){
//    switch (seed.getSurfaceShape()){
//        case Seed::SPHERE:
//            rawShape = ofSpherePrimitive(seed.shapeSize, 64);
//            break;
//        case Seed::PLANE:
//            rawShape = ofPlanePrimitive(seed.shapeSize*10, seed.shapeSize*10, 30, 30);
//            //            rawShape =ofBoxPrimitive(seed.shapeSize, seed.shapeSize, seed.shapeSize);
//            break;
//    }
}

void Surface::draw(){
    
}



//vector<ofVec3f> Surface::getMeshNorms(){
//    
//}