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
    
    // NOTE: KEEP IN THIS ORDER:
    
    // set Traversal
    int t = calculateTraversal();
    newPresent.push_back(t);
    
    // set Medium
    int m = calculateMedium(t);
    newPresent.push_back(m);

    // set Surface
    int s = calculateSurface(m);
    newPresent.push_back(s);
    

    cout << "T: " << t << endl;
    cout << "M: " << m << endl;
    cout << "S: " << s << endl;
    
    
    
    
    
    
    // set Surface
    newPresent.push_back(0);
    
    
    return newPresent;
}

int History::calculateTraversal(){
    int aSize = 4;
    int smallest = past.traversal[0];
    int sIndex = 0;
    for (int i = 0; i < aSize; i++) {
        if (past.traversal[i] < smallest){
            smallest = past.traversal[i];
            sIndex = i;
        }
    }
    return sIndex;
}
int History::calculateMedium(int nt){
    int aSize = 3;
    for (int i = 0; i < aSize; i++) {
        
    }
}
int History::calculateSurface(int nm){
    int aSize = 4;
    for (int i = 0; i < aSize; i++) {
        
    }
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



