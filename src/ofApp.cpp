#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableDepthTest();
//    cam.setDistance(100);
//    cam.lookAt(ofVec3f(0, -100, 653));
    
    shader.load("shadersGL3/shader");
    
    float planeScale = .5;
    int planeWidth = 5000;
    int planeHeight = 5000;
    int planeGridSize = 20;
    int planeColums = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    plane.rotate(90, 1, 0, 0);
    cam.setPosition(0, 100, 653);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
//    ofRotate(90, 1, 0, 0);
    
    plane.drawWireframe();
    
    cam.end();
    
    ofVec3f orien = cam.getOrientationEuler();
    std::cout << "x: " << orien.x << endl;
    std::cout << "y: " << orien.y << endl;
    std::cout << "z: " << orien.z << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'w':
//            cam.setO
            break;
        case 'a':
            cam.setOrientation(ofVec3f(cam.getOrientationEuler().x, cam.getOrientationEuler().y + 5, cam.getOrientationEuler().z));
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
