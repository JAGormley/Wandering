//
//  Surface.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#include "Surface.h"


Surface::Surface(Seed seed){
    this->seed = seed;
    
    
    // TODO: DENSITY
    switch (seed.getSurfaceShape()){
        case Seed::SPHERE:
            rawShape = ofSpherePrimitive(seed.shapeSize, 64);
            break;
        case Seed::PLANE:
            rawShape = ofPlanePrimitive(seed.shapeSize, seed.shapeSize, seed.numCols, seed.numCols);
            
            //            rawShape =ofBoxPrimitive(seed.shapeSize, seed.shapeSize, seed.shapeSize);
            break;
        default:
            rawShape = ofSpherePrimitive(1,1);
            
    }
    
    if ((seed.numCols % 2) != 0){
        even = false;
    }
    else even = true;
    
    vboMesh = rawShape.getMesh();
    
    
};


// TODO: static camera function to clip the horizon a bit earlier than the light
void Surface::draw(){
    
}

ofVboMesh Surface::getMesh(){
    return vboMesh;
}


/* code adapted from https://sites.google.com/site/ofauckland/examples/noise */



//void Surface::newVertexHeight(ofVec3f ){
//    
//}

void Surface::noiseGen(int meshSize){
    groundID = ofGetFrameNum();
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
            
            float a = x * .03;
            float b = y * .03;
            float c = waterID / 220.0;
            
            float noise = ofNoise(a,b,c) * 255;
            float color = noise>75 ? ofMap(noise,75,255,0,255) : 0;
            
            heightMapi[x][y] = color;
        }
    }
}

void Surface::addVRow(){
    float spacing = (seed.shapeSize/(seed.numCols-1));
    int vecSize = vboMesh.getVertices().size();
    for (int i = seed.numCols; i > 0; i--) {
        //add vertex
        ofVec3f temp = vboMesh.getVertices()[vecSize-i];
        temp = ofVec3f(temp.x, temp.y + spacing, temp.z);
        vboMesh.addVertex(setNoiseHeight(temp));
        vboMesh.addNormal(ofVec3f(0,0,1));
        vboMesh.enableColors();
    }
    
    for (int i = 0; i < seed.numCols; i++){
        vboMesh.removeVertex(0);
    }
    
    //stitch new verts into the mesh
    stitch();
}

void Surface::stitch(){
    if (even){
        for (int i = 1; i < seed.numCols; i++) {
            vector<ofVec3f> meshVerts = vboMesh.getVertices();
            int mSize = meshVerts.size();
            vboMesh.addTriangle(mSize-i, mSize-i-seed.numCols,  mSize-i-seed.numCols-1);
            vboMesh.addTriangle(mSize-i, mSize-i-1, mSize-i-seed.numCols-1);
        }
    }
    else {
        for (int i = seed.numCols-1; i > 0 ; i--) {
            vector<ofVec3f> meshVerts = vboMesh.getVertices();
            int mSize = meshVerts.size();
            vboMesh.addTriangle(mSize-seed.numCols-i-1, mSize-seed.numCols-i, mSize-i-1);
            vboMesh.addTriangle(mSize-seed.numCols-i, mSize-i-1,  mSize-i);
        }
    }
    even = !even;
}

ofVec3f Surface::setNoiseHeight(ofVec3f temp){
    // TODO change 499 to groundRes (same with water)
    int xCoord = ofMap(temp.x, -seed.shapeSize/2, seed.shapeSize/2, 0, 499);
    int yCoord = ofMap(temp.y, -seed.shapeSize/2, seed.shapeSize/2, 0, 499);
    
    float a = xCoord * .005;
    float b = yCoord * .005;
    float c = groundID * .002;
    
    float noise = ofNoise(a,b,c) * 255;
    float color = noise>0 ? ofMap(noise,0,255,0,255) : 0;
    
    return ofVec3f(temp.x, temp.y, color*3);
    
    
}






Surface::~Surface(){}