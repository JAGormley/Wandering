#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    shader.load("shadersGL2/shader");
    
    outCam = false;
    
    ofSetFrameRate(60);
    
    ofEnableDepthTest();
    ofEnableLighting();
    
    cam.setPosition(0, 0, -2500);
    scenario.setNew();
}

//--------------------------------------------------------------
void ofApp::update(){
    scenario.update();    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableLighting();
    
    if (outCam == true){
        // DEBUG CAM
        cam.begin();
        scenario.player.draw();
    }
    
    else {
        // PLAYER CAM
        scenario.player.startCam();
    }
    
    scenario.draw();
    
    ofPushMatrix();
    ofRotate(90, 1, 0, 0);
    ofTranslate(0, 0, -100);
    ofSetColor(100, 0, 100, 200);
    ofPopMatrix();
    
    if (outCam == true){
        cam.end();
    }
    else {
        scenario.player.stopCam();
    }
    ofDisableLighting();
    ofSetColor(ofColor::white);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key) {
        case 'v':
            lightMove = true;
            break;
        case 'b':
            lightOr = true;
            break;
        case 'o':
            outCam = !outCam;
            break;
        case 'r':
            scenario.setNew();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key) {
        case 'v':
            lightMove = false;
            break;
        case 'b':
            lightOr = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (lightMove){
        
    }
    else if (lightOr){
//        moon.setOrientation(ofVec3f(mouseX, mouseY, 0));
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
//--------------------------------------------------------------
