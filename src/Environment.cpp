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

Environment::Environment(Light light, Surface &surface, Medium &medium){
    this->light = light;
    this->surface = &surface;
    this->medium = &medium;
    this->surface->generate();
}

void Environment::draw(){
//    light.enable();
    medium->draw();
    surface->draw();
//    light.draw();
//    light.disable();
}

int Environment::getType(){
    return type;
}

void Environment::update(){
    light.update();
}