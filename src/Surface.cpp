//
//  Surface.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Surface.h"


Surface::Surface(Seed seed){this->seed = seed;};


void Surface::generate(){
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(1000, 32);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(1000, 1000, 30, 30);
            break;
    }
}

void Surface::draw(){
    ofSetColor(255, 200, 0);
    ofPushMatrix();
    ofRotate(90, 1, 0, 0);
    rawShape.draw();
    ofPopMatrix();
}