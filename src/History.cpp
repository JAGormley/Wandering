//
//  History.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "History.h"

History::History(){
};


void History::addHistory(int t, int m, int s){
    past.traversal[t]++;
    past.medium[m]++;
    past.surface[s]++;
}

vector<int> History::calculatePresent() {
    vector<int> newPresent;
    
    
    
    // set Traversal
    newPresent.push_back(0);
    
    // set Medium
    newPresent.push_back(1);
    
    // set Surface
    newPresent.push_back(2);
    
    
    
    
    return newPresent;
}


History::Present History::getPresent(){
    return present;
}

void History::setPresent(){
    vector<int> newPresent = calculatePresent();
    
//    addHistory(1);
    
    // TRAVERSAL
    // 0 = ORBIT, 1 = WALK, 2 = FLOAT, 3 = FLY
    present.traversal = newPresent[0];
    
    // DEBUG:
//    present.traversal = 0;
    
    // MEDIUM
    // 0 = AIR, 1 = VOID, 2 = WATER
    if (present.traversal == 0 || present.traversal == 1){
        present.medium = ofRandom(2);
    }
    else if (present.traversal == 3){
        do{
            present.medium = ofRandom(3);
        }
        while (present.medium == 1);
    }
    else present.medium = ofRandom(3);
    
    // DEBUG:
    present.medium = newPresent[1];
    
    
    // SURFACE_TYPE
    // 0 = WATER, 1 = GROUND, 2 = VOID, 3 = NONE
    
    // ORBIT
    if (present.traversal == 0){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 3);
    }
    // WALK
    else if (present.traversal == 1){
        present.surface = 1;
    }
    // FLOAT
    else if (present.traversal == 2){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 0 || present.surface == 2);
    }
    // FLY:
    else if (present.traversal == 3 && present.medium == 0){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 1 || present.surface == 2);
    }
    else if (present.traversal == 3 && present.medium == 2){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 0 || present.surface == 2);
    }
    // DEBUG:
    present.surface = newPresent[2];
    
    
    addHistory(newPresent[0], newPresent[1], newPresent[2]);
}



