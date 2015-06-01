#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //    ofSetVerticalSync(true);
    
    ofSetFrameRate(60);
    ofBackground(210, 210, 210);
    ofEnableDepthTest();
    ofEnableLighting();
    
    light.setPosition(-700, 0, 0);
    
    light.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    light.setDiffuseColor( ofColor(255.f, 255.f, 255.f));
    light.setSpotlight();
    ofSetSmoothLighting(true);
    lightColor.setBrightness( 180.f );
    lightColor.setSaturation( 150.f );
    lightColor.setBrightness(255);
    lightColor.setSaturation(255);
    
    material.setShininess( 128 );
    materialColor.setHue(colorHue);
    materialColor.setBrightness(500.f);
    materialColor.setSaturation(400);
    materialColor.set(0, 255, 0, .5);
    //    light.setAttenuation(1.f, 0, 0.00005f);
        
    
    sprites.push_back(shared_ptr<Sprite>(new Plant(seed)));
    sprites.push_back(shared_ptr<Sprite>(new Animal(seed)));
    
    environment = new Environment(moon, *new Ground(seed), *new Void(seed));
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    verts = plane.getMesh().getVertices();
    player.getLocation();
    
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    
    player.startCam();
    player.move();
    
    //    shader.begin();

    light.enable();
    light.draw();
    environment->draw();
//    player.draw();
//    shader.end();

    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->draw();
    }
    
    
    ofSetColor(0, 0, 255, 100);
    ofDrawSphere(0, -250, 500);
    ofSetColor(0, 0, 0);
    
    
    light.disable();
    player.stopCam();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //TODO: change to Leap controls
    
    switch(key) {
        case 'v':
            lightMove = true;
            break;
        case 'b':
            lightOr = true;
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
        
        light.setPosition(light.getPosition().x, mouseX, mouseY);
    }
    else if (lightOr){
        light.setOrientation(ofVec3f(mouseX, mouseY, 0));
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
//void ofApp::exit(){
//    leap.close();
//}