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

Environment::Environment(Light light, Domain &up, Domain &down){
    this->light = light;
    this->up = &up;
    this->down = &down;
}

void Environment::draw(){
//    up->draw();
    down->draw();
}