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
    int planeWidth = 4000;
    int planeHeight = 4000;
    int planeColums = 20;
    int planeRows = 20;
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
    verts = plane.getMesh().getVertices();
    world.set(2000, 50);
    vector<ofVec3f> worldVerts = world.getMesh().getVertices();
    
    float rando;
    for (int i = 0; i < worldVerts.size(); i++) {
        rando = ofRandom(100);
        world.getMesh().setVertex(i, ofVec3f(worldVerts[i].x, worldVerts[i].y + rando ,worldVerts[i].z));
    }
    
}

void Environment::draw(){
//    plane.drawWireframe();
    world.drawWireframe();
}