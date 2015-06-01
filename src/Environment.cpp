//
//  Environment.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "Environment.h"

Environment::Environment(){
    int planeWidth = 500;
    int planeHeight = 500;
    int planeColums = 20;
    int planeRows = 20;
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
    verts = plane.getMesh().getVertices();
}

void Environment::draw(){
    plane.drawWireframe();
}