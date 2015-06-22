//
//  Seed.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.


#include "Seed.h"


Seed::Seed(){}

void Seed::populate(){
    history.setPresent();
    setTraversal();
    setSurfaceShape();
    setSurfaceType();
    setMedium();
    setLightType();
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
    
    
    // TODO: get vals from ???
    if (traversal == ORBIT){
        sShape = SPHERE;
        shapeSize = 1000;
    }
    else {
        sShape = PLANE;
        shapeSize = 500;
        numCols = 10;
    }
    
    
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

}

Seed::Traversal Seed::getTraversal(){
    return traversal;
}

float Seed::getOrbitHeight(){
    return shapeSize+(shapeSize/3);
}


// LIGHT

void Seed::setLightType(){
    if (medium == M_VOID)
        lightType = MOON;
    else lightType = SUN;
}
Seed::LightType Seed::getLightType(){
    return lightType;
}
