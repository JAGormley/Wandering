//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

Plant::Plant(SpriteSeed spriteSeed) : Sprite(spriteSeed){
    sSeed = spriteSeed;
    
    // TODO: get plantSize from spriteSeed
    plant.set(5, 500, 5);
    pos = sSeed.spritePos();
    plant.setPosition(pos.x, pos.y, pos.z);
    //    plant.setUseVbo(true);
    
    ofQuaternion q;
    if (sSeed.isOrbital()){
        q.makeRotate(ofVec3f(0, sSeed.getShapeSize(), 0), pos);
        plant.rotate(q);
    }
    else {
//        plant.rotate(90, 1, 0, 0);
        plant.rotateAround(-90, ofVec3f(1,0,0), ofVec3f(0,0,0));
        
        // TODO: get plantSize from spriteSeed
        plant.move(ofVec3f(0, 0, 50));
    }
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    colorHue = 100;
    materialColor.setHue(colorHue);
    //    material.setEmissiveColor(materialColor);
    
    material.setShininess(255);
    material.setDiffuseColor(materialColor);
    material.setSpecularColor(materialColor);
}


void Plant::move(){
}
void Plant::activate(){
    
}
void Plant::setActivated(bool activated){
    
}

void Plant::draw(){
    ofPushMatrix();
    material.begin();
    plant.draw();
    material.end();
    ofPopMatrix();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}

vector<ofVec3f> Plant::getVerts(){
    return plant.getMesh().getVertices();
}