#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "Player.h"
//#include "Seed.h"
//#include "Sprite.h"
#include "Crystal.h"

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
    
    ofShader shader;
    ofPlanePrimitive plane;
    vector<ofBoxPrimitive> boxes;
    
    bool lightMove;
    bool lightOr;
    
    vector<ofVec3f> verts;
    ofBoxPrimitive box;
    ofMaterial material;
    
    ofColor lightColor;
    float colorHue;
    ofColor materialColor;    
    
    Player player;

    ofLight light;
    
    Sprite * crystal;
};
