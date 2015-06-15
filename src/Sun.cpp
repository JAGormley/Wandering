//
//  Sun.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#include "Sun.h"



Sun::Sun(Seed seed) : Light(seed){}

void Sun::draw(){
    ofSetColor(255, 255, 0);
    ofPushMatrix();
    ofCircle(1000, 1000, 200);
    ofPopMatrix();
}