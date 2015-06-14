//
//  Plant.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#include "Plant.h"

//Plant::Plant(SpriteSeed spriteSeed) : Sprite(spriteSeed){
//    plant.set(5, 50, 5);
//
//    float xRand = ofRandom(2000)-1000;
//    float zRand = ofRandom(2000)-1000;
//
//
//    plant.setPosition(xRand, 25, zRand);
//
//    materialColor.setBrightness(250.f);
//    materialColor.setSaturation(200);
//    colorHue = 100;
//    materialColor.setHue(colorHue);
////    material.setEmissiveColor(materialColor);
//
//    material.setShininess(255);
//    material.setDiffuseColor(materialColor);
//    material.setSpecularColor(materialColor);
//}

Plant::Plant(SpriteSeed spriteSeed) : Sprite(spriteSeed){
    sSeed = spriteSeed;
    plant.set(5, 100, 5);
    pos = sSeed.spritePos();
    plant.setPosition(pos.x, pos.y, pos.z);
    
    
    if (sSeed.isOrbital()){
        ofQuaternion q;
        q.makeRotate(ofVec3f(0, 500, 0), pos);
        plant.rotate(q);
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
//    ofPushMatrix();
//    if (sSeed.isOrbital())
//        ofRotate(-90, 1, 0, 0);
    material.begin();
    plant.draw();
    material.end();
//    ofPopMatrix();
}
ofVec3f Plant::getLocation(){
    plant.getPosition();
}

vector<ofVec3f> Plant::getVerts(){
    return plant.getMesh().getVertices();
}