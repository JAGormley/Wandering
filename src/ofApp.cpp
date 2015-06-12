#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("shadersGL2/shader");
    
    //    ofSetVerticalSync(true);
    
    outCam = false;
    
    ofSetFrameRate(60);
    
    ofEnableDepthTest();
    ofEnableLighting();
    
//    light.setAttenuation(1.f, 0, 0.00005f);
    
    
   
//    sprites.push_back(shared_ptr<Sprite>(new Animal(seed)));
    
    cam.setPosition(0, 0, -2500);
//    moon.setPosition(ofVec3f(600, 1200, 0));
//    moon.lookAt(ofVec3f(0,0,0));
//    moon.setSpotlight();
//    Light::light.setup();
    scenario.setNew();
}

//--------------------------------------------------------------
void ofApp::update(){
    scenario.update();    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableLighting();
//    moon.enable();
    if (outCam == true){
        cam.begin();
        cout << "LOOKDIR: " << cam.getLookAtDir() << endl;
        scenario.player.draw();
    }
    else {
        scenario.player.startCam();
    }
    
//    scenario.player.move();
    
    scenario.draw();
//    moon.draw();
    
//    shader.begin();
//    shader.end();
    
//    moon.disable();
    
    
    if (outCam == true){
        cam.end();
    }
    else {
        scenario.player.stopCam();
    }
    ofDisableLighting();
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
        
        scenario.moveLight(x, y);
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
