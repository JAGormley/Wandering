//
//  History.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "History.h"

History::History(){};


void History::addHistory(int type){
    
}

History::Present History::getPresent(){
    Present present;
    
    present.traversal = ofRandom(3);
    present.medium = ofRandom(2);
    present.surface = ofRandom(4);
    cout << present.surface << endl;
    
    return present;
}