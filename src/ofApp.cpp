#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    
    // turn on smooth lighting //
    ofSetSmoothLighting(true);
    
    light.setDiffuseColor( ofColor(255.f, 255.f, 255.f));
    
    float planeScale = .5;
    int planeWidth = 1000;
    int planeHeight = 1000
    ;
    int planeGridSize = 20;
    int planeColums = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
    cam.setPosition(0, 100, 653);
    
    
    lightColor.setBrightness( 180.f );
    lightColor.setSaturation( 150.f );
    colorHue = 170;
    lightColor.setHue(colorHue);
    
    material.setShininess( 128 );
    materialColor.setHue(colorHue);
    materialColor.setBrightness(500.f);
    materialColor.setSaturation(400);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    verts = plane.getMesh().getVertices();
    
    light.setDiffuseColor(lightColor);
    
    
//    for (int i = 0; i < verts.size(); i++) {
//        ofBoxPrimitive tempBox;
//        tempBox.setPosition(verts[i]);
//        tempBox.set(5);
//        boxes.push_back(tempBox);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    
    cam.begin();
    light.enable();
    material.begin();
    
    plane.drawWireframe();
    ofFill();
    ofPushMatrix();
    ofRotate(90, 1, 0, 0);
    light.setPosition(-200, 70, -300);
    light.setOrientation(ofVec3f(600, 200, 300));
    
    for (int i = 0; i < verts.size(); i++) {
        ofDrawBox(verts[i].x, verts[i].y, verts[i].z, 5);
    }
    ofPopMatrix();
    material.end();
    light.disable();
    light.draw();
    
    verts.clear();
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //TODO: change to Leap controls
    
    switch(key) {
        case 'w':
            cam.dolly(-10);
            break;
        case 'a':
            cam.setOrientation(ofVec3f(cam.getOrientationEuler().x, cam.getOrientationEuler().y + 5, cam.getOrientationEuler().z));
            break;
        case 'd':
            cam.setOrientation(ofVec3f(cam.getOrientationEuler().x, cam.getOrientationEuler().y - 5, cam.getOrientationEuler().z));
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
