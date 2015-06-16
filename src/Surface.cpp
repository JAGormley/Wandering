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
    
    // TODO: DENSITY
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(seed.shapeSize, 64);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(seed.shapeSize, seed.shapeSize, 30, 30);
            //            rawShape =ofBoxPrimitive(seed.shapeSize, seed.shapeSize, seed.shapeSize);
            break;
        default:
            rawShape = ofSpherePrimitive(1,1);
 
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

void Surface::draw(){}

vector<ofVec3f> Surface::getMeshVerts(){
    rawMesh = rawShape.getMesh();
    return rawMesh.getVertices();
}



Surface::~Surface(){}