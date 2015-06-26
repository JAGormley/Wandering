//
//  Sound.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-25.
//
//

#include "Sound.h"


Sound::Sound(){
    se1.loadSound("sound/activation.wav");
    music.setLoop(true);
}

void Sound::loadMusic(){
    music.loadSound("sound/eno.mp3");
}

void Sound::playMusic(){
    
    music.play();
}

void Sound::playSE(int sId){
    switch (sId) {
        case 1:
            if (!se1.getIsPlaying()){
                se1.play();
            }
            break;
        case 2:
            se2.play();
            break;
            
        default:
            break;
    }
}