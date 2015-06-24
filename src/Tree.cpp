//
//  Tree.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-24.
//
//

#include "Tree.h"


Tree::Tree(SpriteSeed spriteSeed) : Plant(spriteSeed){
    stem = ofBoxPrimitive();
    stem.set(5, 500, 5);
    pos = sSeed.spritePos();
    stem.setPosition(pos.x, pos.y, pos.z);
    
    top.setParent(stem);
    addLeaves();
    top.set(10, 10, 10);
    top.boom(150);
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
    //    material.setEmissiveColor(materialColor);
    
    material.setShininess(255);
    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
    
    this->setup();
}

void Tree::setup(){
    ofQuaternion q;
    if (sSeed.isOrbital()){
        q.makeRotate(ofVec3f(0, sSeed.getShapeSize(), 0), pos);
        stem.rotate(q);
        stem.boom(200);
    }
    else {
        //        plant.rotate(90, 1, 0, 0);
        stem.rotateAround(-90, ofVec3f(1,0,0), ofVec3f(0,0,0));
    }
}


void Tree::addLeaves(){
    ofConePrimitive tempLeaf;
    ofVboMesh vLeaf;
    for (int i = 0; i < 20; i++) {
        tempLeaf.set(6, 6);
        tempLeaf.setScale(.5, 1, 1);
        tempLeaf.setParent(top);
        tempLeaf.setPosition(ofVec3f(ofRandom(50), ofRandom(20), ofRandom(20)));
        vLeaf = tempLeaf.getMesh();
        leaves.push_back(tempLeaf);
    }
    
    
    
}