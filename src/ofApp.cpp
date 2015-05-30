#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    Player player;
    
    //    ofSetVerticalSync(true);
    
    ofSetFrameRate(60);
    ofBackground(70, 70, 70);
    ofEnableDepthTest();
    ofEnableLighting();
    
    int planeWidth = 500;
    int planeHeight = 500;
    int planeColums = 20;
    int planeRows = 20;
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
    verts = plane.getMesh().getVertices();
    
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
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    verts = plane.getMesh().getVertices();
    player.getLocation();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.startCam();
    player.move();
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    //    shader.begin();

    light.enable();
    light.draw();
    
    player.draw();
    
    plane.drawWireframe();
//    shader.end();
    
    material.begin();
    ofPushMatrix();
    ofSetColor(0, 0, 255, 100);
    ofRotate(90, 1, 0, 0);
    for (int i = 0; i < verts.size(); i++) {
        ofDrawBox(verts[i].x, verts[i].y, verts[i].z, 5);
    }
    
    ofFill();
    ofPopMatrix();
    
    material.end();
    light.disable();
    
    
    player.stopCam();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //TODO: change to Leap controls
    
    switch(key) {
//        case 'w':
//            cam.dolly(-10);
//            break;
//        case 'a':
//            cam.setOrientation(ofVec3f(cam.getOrientationEuler().x, cam.getOrientationEuler().y + 5, cam.getOrientationEuler().z));
//            break;
//        case 'd':
//            cam.setOrientation(ofVec3f(cam.getOrientationEuler().x, cam.getOrientationEuler().y - 5, cam.getOrientationEuler().z));
//            break;
//        case 'v':
//            lightMove = true;
//            break;
//        case 'b':
//            lightOr = true;
//            break;
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
        light.setOrientation(ofVec3f(light.getOrientationEuler().x, mouseX, mouseY));
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