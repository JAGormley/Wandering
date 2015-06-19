//
//  Surface.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Surface.h"


Surface::Surface(Seed seed){
    if (seed.getSurfaceType() == Seed::S_WATER)
        heightMap.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    else heightMap.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    this->seed = seed;
    
    // TODO: DENSITY
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(seed.shapeSize, 64);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(seed.shapeSize, seed.shapeSize, 100, 100);
            
            //            rawShape =ofBoxPrimitive(seed.shapeSize, seed.shapeSize, seed.shapeSize);
            break;
        default:
            rawShape = ofSpherePrimitive(1,1);
            
    }
    
    vboMesh = rawShape.getMesh();
};


// TODO: static camera function to clip the horizon a bit earlier than the light
void Surface::draw(){
    rawShape.drawAxes(100);
}

ofVboMesh Surface::getMesh(){
    return vboMesh;
}


/* code adapted from https://sites.google.com/site/ofauckland/examples/noise */


void Surface::noiseGen(int meshSize){
    for (int y=0; y<500; y++) {
        for (int x=0; x<500; x++) {
            
            float a = x * .005;
            float b = y * .005;
            float c = ofGetFrameNum() / 200.0;
            
            float noise = ofNoise(a,b,c) * 255;
            float color = noise>75 ? ofMap(noise,75,255,0,255) : 0;
            
            heightMapi[x][y] = color;
        }
    }
}

void Surface::waterNoiseGen(int meshSize){
    for (int y=0; y<100; y++) {
        for (int x=0; x<100; x++) {
            
            float a = x * .05;
            float b = y * .05;
            float c = ofGetFrameNum() / 180.0;
            
            float noise = ofNoise(a,b,c) * 255;
            float color = noise>50 ? ofMap(noise,50,255,0,255) : 0;
//
            heightMapi[x][y] = color;
        }
    }
}



Surface::~Surface(){}