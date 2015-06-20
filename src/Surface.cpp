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
    
}

ofVboMesh Surface::getMesh(){
    return vboMesh;
}


/* code adapted from https://sites.google.com/site/ofauckland/examples/noise */


void Surface::noiseGen(int meshSize){
    groundID++;
    for (int y=0; y<500; y++) {
        for (int x=0; x<500; x++) {
            
            float a = x * .005;
            float b = y * .005;
            float c = groundID * .002;
            
            float noise = ofNoise(a,b,c) * 255;
            float color = noise>0 ? ofMap(noise,0,255,0,255) : 0;
            
            heightMapi[x][y] = color;
        }
    }
}

void Surface::waterNoiseGen(int meshSize){
    waterID++;
    for (int y=0; y<200; y++) {
        for (int x=0; x<200; x++) {
            
            float a = x * .005;
            float b = y * .005;
            float c = waterID / 180.0;
            
            float noise = ofNoise(a,b,c) * 255;
            float color = noise>75 ? ofMap(noise,75,255,0,255) : 0;
//
            heightMapi[x][y] = color;
        }
    }
}



Surface::~Surface(){}