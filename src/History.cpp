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
    
    // THESE CALCULATION FNS SHOULD RETURN LEAST-VISITED OR RANDOM WITH SOME PROBABILITY
    
    // set Traversal
    int t = calculateTraversal();
    newPresent.push_back(t);
    
    // set Medium
    int m = calculateMedium(t);
    newPresent.push_back(m);
    
    // set Surface
    int s = calculateSurface(t, m);
    newPresent.push_back(s);
    
    cout << "T: " << t << endl;
    cout << "M: " << m << endl;
    cout << "S: " << s << endl;
    
    return newPresent;
}

int History::calculateTraversal(){
    int aSize = 4;
    int smallest = 10000;
    
    int sIndex = 0;
    for (int i = 0; i < aSize; i++) {
        if (past.traversal[i] < smallest){
            smallest = past.traversal[i];
            sIndex = i;
        }
    }
    
    if (ofRandom(1.0) < .5){
        return ofRandom(4);
        
    } else return sIndex;
}

// TODO: CONSOLIDATE CALCULATION FUNCTIONS

int History::calculateMedium(int nt){
    int aSize = 3;
    
    // SET ALLOWED MEDIUMS
    vector<int> permitted;
    permitted.push_back(0);
    permitted.push_back(1);
    if (nt == 2 || nt == 3)
        permitted.push_back(2);
    
    int smallest = 10000;
    int sIndex = 0;
    for (int i = 0; i < aSize; i++) {
        if (past.medium[i] < smallest &&
            find(permitted.begin(), permitted.end(), i)
            !=permitted.end()){
            smallest = past.medium[i];
            sIndex = i;
        }
    }
    if (ofRandom(1.0) < .5){
        int random = ofRandom(permitted.size());
        return permitted[random];
    } else return sIndex;
}


int History::calculateSurface(int nt, int nm){
    int aSize = 4;
    
    // SET ALLOWED SURFACES
    vector<int> permitted;
    switch (nt) {
        case 0:
            permitted.push_back(0);
            permitted.push_back(2);
        case 1:
            cout << "eeep" << endl;
            permitted.push_back(1);
            break;
        case 3:
//            if (nm == 0)
                permitted.push_back(0);
//            if (nm == 2)
                permitted.push_back(1);
        case 2:
            permitted.push_back(3);
            break;
    }
    
    int smallest = 10000;
    int sIndex = 0;
    for (int i = 0; i < aSize; i++) {
        if (past.surface[i] < smallest &&
            find(permitted.begin(), permitted.end(), i)
            !=permitted.end()){
            smallest = past.surface[i];
            sIndex = i;
        }
    }
    if (ofRandom(1.0) < .5){
        cout << "here2" << endl;
        int random = ofRandom(permitted.size());
        return permitted[random];
    }
    
    return sIndex;
}


History::Present History::getPresent(){
    return present;
}

void History::setPresent(){
    vector<int> newPresent = calculatePresent();
    
    // TRAVERSAL
    // 0 = ORBIT, 1 = WALK, 2 = FLOAT, 3 = FLY
    present.traversal = newPresent[0];
    
    // MEDIUM
    // 0 = AIR, 1 = VOID, 2 = WATER
    present.medium = newPresent[1];
    
    // SURFACE_TYPE
    // 0 = WATER, 1 = GROUND, 2 = VOID, 3 = NONE
    present.surface = newPresent[2];
    
    
    addHistory(newPresent[0], newPresent[1], newPresent[2]);
}



