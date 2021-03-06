//
//  Environment.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Environment.h"
#include "ofMath.h"

Environment::Environment(){}

Environment::Environment(Surface &surface, Medium &medium){
    this->surface = &surface;
    this->medium = &medium;
    
    // maybe dont need this, may just reconstruct the object each time.
    //    this->surface->generate();
}

void Environment::draw(){
    medium->draw();
    surface->draw();
}

void Environment::update(){
    surface->update();
    medium->update();
}


ofVboMesh Environment::getSurfaceMesh(){
    return surface->getMesh();
}

Environment::~Environment(){
    delete surface;
    delete medium;
}