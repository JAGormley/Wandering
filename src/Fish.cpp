//
//  Fish.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-26.
//
//

#include "Fish.h"

//
//Fish::Fish(SpriteSeed spriteSeed) : Animal(spriteSeed){
//    activated = false;
//    alphFill = 0;
//    materialColor.setBrightness(250.f);
//    materialColor.setSaturation(200);
//    colorHue = 200;
//    materialColor.setHue(colorHue);
//    material.setShininess(255);
//    //    material.setDiffuseColor(materialColor);
//    material.setSpecularColor(materialColor);
//    
//    actCol = ofColor(219,112,147);
//    actCol.setBrightness(150);
//    
//    pos = sSeed.spritePos();
//    body.set(100, 2);
//    body.setPosition(pos);
//    
//    ring1.set(80, 15);
//    ring1.setMode(OF_PRIMITIVE_LINES);
//    ring1.setParent(body);
//    
//    ring2.set(80, 15);
//    ring2.setMode(OF_PRIMITIVE_LINES);
//    ring2.setParent(body);
//    
//    this->setup();
//    body.boom(sSeed.getOrbitHeight());
//    ring1.boom(40);
//    ring2.boom(-40);
//}