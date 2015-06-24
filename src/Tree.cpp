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
    top.set(100, 100, 100);
    
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
        
        stem.move(ofVec3f(0, 0, 50));
    }
}