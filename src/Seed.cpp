//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.

// TODO: SETTERS USE HISTORY AND SOIL TO GET THEIR VALUES

#include "Seed.h"


Seed::Seed(){
    
    medium = M_VOID;
}

void Seed::populate(){
    setTraversal();
    setSurfaceShape();
    setSurfaceType();
    setMedium();
}


// ENVIRONMENT

Seed::SurfaceShape Seed::getSurfaceShape(){
    return sShape;
}

Seed::SurfaceType Seed::getSurfaceType(){
    return sType;
}

Seed::Medium Seed::getMedium(){
    return medium;
}

void Seed::setSurfaceShape(){
    // TODO: set for other types of movement/shape
    
    sShape = SPHERE;
    shapeSize = 1000.f;
}
void Seed::setSurfaceType(){
    sType = GROUND;
}

void Seed::setMedium(){
    medium = M_WATER;
}


// PLAYER

void Seed::setTraversal(){
    traversal = ORBIT;
}

Seed::Traversal Seed::getTraversal(){
    return traversal;
}

float Seed::getPlayerLocation(){
    return shapeSize;
}