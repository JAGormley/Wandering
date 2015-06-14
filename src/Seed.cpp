//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.

// TODO: SETTERS USE HISTORY AND SOIL TO GET THEIR VALUES

#include "Seed.h"


Seed::Seed(){}

void Seed::populate(){
    history.setPresent();
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
    if (traversal == ORBIT){
        sShape = SPHERE;
    }
    else sShape = PLANE;
    
    shapeSize = 500;
}
void Seed::setSurfaceType(){
    sType = Seed::SurfaceType(history.getPresent().surface);
}

void Seed::setMedium(){
    medium = Seed::Medium(history.getPresent().medium);
}


// PLAYER

void Seed::setTraversal(){
    traversal = Seed::Traversal(history.getPresent().traversal);
    
//    DEBUG
    traversal = ORBIT;
}

Seed::Traversal Seed::getTraversal(){
//    return ORBIT;
    return traversal;
}

// TODO: FIX THIS
float Seed::getPlayerLocation(){
    if (sShape == PLANE){
        return 20;
    }
    else return shapeSize;
}


// LIGHT

void Seed::setLightType(){
    
}
Seed::LightType Seed::getLightType(){
    return lightType;
}
