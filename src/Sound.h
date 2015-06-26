//
//  Sound.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-25.
//
//

#ifndef __Wandering2__Sound__
#define __Wandering2__Sound__

#include <stdio.h>
#include "ofFmodSoundPlayer.h"

#endif /* defined(__Wandering2__Sound__) */



class Sound {
public:
    void loadMusic();
    void playMusic();
    void playSE(int sId);
    
    Sound();
    ofFmodSoundPlayer music;
    ofFmodSoundPlayer se1;
    ofFmodSoundPlayer se2;
    
};