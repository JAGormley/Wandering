//
//  Void.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#include "Void.h"

Void::Void(Seed seed) : Domain(seed){
    world.set(2000, 50);
    voidMaterial.setColors(50, 0, 0, 0);
    voidMaterial.setShininess(200);
    }

void Void::draw(){
    voidMaterial.begin();
    world.drawWireframe();
    voidMaterial.end();
}


void Void::setColor(ofColor hue){
    
}
void Void::update(){
    
}
vector<ofVec3f> Void::getMeshVerts(){
    return world.getMesh().getVertices();
}
