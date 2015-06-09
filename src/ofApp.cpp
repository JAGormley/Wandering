#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("shadersGL2/shader");
    
    //    ofSetVerticalSync(true);
    
    outCam = false;
    
    ofSetFrameRate(60);
    ofBackground(10, 80, 210);
    ofEnableDepthTest();
    ofEnableLighting();
    
//    light.setAttenuation(1.f, 0, 0.00005f);
    for (int i = 0; i < 500; i++) {
        sprites.push_back(shared_ptr<Sprite>(new Plant()));
    }
//    sprites.push_back(shared_ptr<Sprite>(new Animal(seed)));
    
    
    cam.setPosition(0, 0, -2500);
    
    Light::light.setup();
    scenario.setNew();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    scenario.player.getLocation();
    
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofEnableLighting();
    if (outCam == true){
        cam.begin();
        scenario.player.draw();
    }
    else {
        scenario.player.startCam();
    }
//
    
    scenario.player.move();
    
    Light::light.enable();
    
    ofSetColor(0,0,0);
    Light::light.draw();
    
    vboMesh.drawWireframe();
    scenario.draw();
    
//    shader.begin();
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->draw();
    }
    shader.end();

    
    Light::light.disable();
    ofDisableLighting();
    
    
    
    if (outCam == true){
        cam.end();
    }
    else {
        scenario.player.stopCam();
    }
    
//
    
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
        
//        scenario.player.cam.lookAt(ofVec3f(mouseX,
//                                    0,
//                                    0));o
//        cout << scenario.player.cam.getOrientationEuler() << endl;
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
