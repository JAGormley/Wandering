//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.

// TODO: SETTERS USE HISTORY AND SOIL TO GET THEIR VALUES

#include "Seed.h"


Seed::Seed(){
    
    
    sType = GROUND;
    medium = M_VOID;
}

void Seed::populate(){
    setTraversal();
    setSurfaceShape();
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

void Seed::setMedium(){
    
}
void Seed::setSurfaceShape(){
    sShape = SPHERE;
    shapeSize = 1050.f;
}
void Seed::setSurfaceType(){
    
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