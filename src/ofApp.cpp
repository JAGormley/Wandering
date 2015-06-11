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
    
    Light::light.setup();
    scenario.setNew();
}

//--------------------------------------------------------------
void ofApp::update(){
    scenario.player.getLocation();
    scenario.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableLighting();
    
    if (outCam == true){
        cam.begin();
        scenario.player.draw();
    }
    else {
        scenario.player.startCam();
    }
    
    scenario.player.move();
    
    Light::light.enable();
    Light::light.draw();
    
    scenario.draw();
    
//    shader.begin();
//    shader.end();

    Light::light.disable();
    ofDisableLighting();
    
    if (outCam == true){
        cam.end();
    }
    else {
        scenario.player.stopCam();
    }
    
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
    lightOr = true;
    if (lightMove){
        
        Light::light.setPosition(Light::light.getPosition().x, mouseX, mouseY);
    }
    else if (lightOr){
        Light::light.setOrientation(ofVec3f(mouseX, mouseY, 0));
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
