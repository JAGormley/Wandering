#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
//#include "Player.h"
//#include "Animal.h"
#include "Scenario.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    static int getLightPos();
    
    ofShader shader;
//    ofPlanePrimitive plane;
    vector<ofBoxPrimitive> boxes;
    
    bool lightMove;
    bool lightOr;
    bool outCam;
    
    ofBoxPrimitive box;
    ofMaterial material;
    
    ofColor lightColor;
    float colorHue;
    ofColor materialColor;
    
    ofEasyCam cam;
    
//    Player player;
    
    ofFbo fbo;
    ofVboMesh vboMesh;
    ofVbo vbo;
    
    Scenario scenario;
    
    
    
};
