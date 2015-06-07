//
//  Environment.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Environment.h"
#include "ofMath.h"

Environment::Environment(){
    float rando;
//    for (int i = 0; i < worldVerts.size(); i++) {
//        rando = ofRandom(100);
//        world.getMesh().setVertex(i, ofVec3f(worldVerts[i].x + rando, worldVerts[i].y + rando ,worldVerts[i].z) + rando);
//    }
}

Environment::Environment(Light light, Surface &surface, Medium &medium){
    this->light = light;
    this->surface = &surface;
    this->medium = &medium;
    
}

void Environment::draw(){
    
    medium->draw();
    surface->draw();
}

int Environment::getType(){
    return type;
}