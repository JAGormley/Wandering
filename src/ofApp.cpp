#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("shadersGL2/shader");
    
    //    ofSetVerticalSync(true);
    
    ofSetFrameRate(60);
    ofBackground(10, 80, 210);
    ofEnableDepthTest();
    ofEnableLighting();
    
//    light.setAttenuation(1.f, 0, 0.00005f);
//    for (int i = 0; i < sprites.size(); i++) {
//    }
//    sprites.push_back(shared_ptr<Sprite>(new Animal(seed)));
    
    
    
    environment = new Environment(moon, *new Ground(seed), *new Void(seed));
    
    
    
    
    
    Light::light.setup();
    vector<ofVec3f> tempVerts;
    vector<ofVec3f> transVerts;
    
//    for (int i = 0; i < 30; i++) {
//        sprites.push_back(shared_ptr<Sprite>(new Plant(seed)));
////        vboMesh.addVertices(sprites[0]->getVerts());
//        vector<ofVec3f> jim = sprites[i]->getVerts();
//        
////        tempVerts.push_back(jim);
//        
//        float mover = ofRandom(2000)-1000;
//        
//        for (int j = 0; j < jim.size(); j++) {
//            transVerts.push_back(ofVec3f(jim[j].x+mover, jim[j].y+mover, jim[j].z+mover));
//        }
//        vboMesh.addVertices(transVerts);
//        
//    }
//    ofSpherePrimitive s;
//    s.set(10, 10);
//    ofBoxPrimitive b;
//    b.set(10);
    
//    vboMesh.addVertices(s.getMesh().getVertices());
    
//    vector<ofVec3f> tempVerts = b.getMesh().getVertices();
    
//    vector<ofVec3f> transVerts;
    
//    for (int i = 0; i < tempVerts.size(); i++) {
//         transVerts.push_back(ofVec3f(tempVerts[i].x+10, tempVerts[i].y+10, tempVerts[i].z));
//    }
//    ofTranslate(-50, -50);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    player.getLocation();
    
//    for (int i = 0; i < sprites.size(); i++) {
//        sprites[i]->move();
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofEnableLighting();
    player.startCam();
    player.move();
    
    Light::light.enable();
    
    ofSetColor(0,0,0);
    Light::light.draw();
    
    vboMesh.drawWireframe();
//    environment->draw();
//    player.draw();
    
//    shader.begin();
//    for (int i = 0; i < sprites.size(); i++) {
//        sprites[i]->draw();
//    }
//    shader.end();

    
    Light::light.disable();
    ofDisableLighting();
    player.stopCam();
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
