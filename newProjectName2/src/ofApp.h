#pragma once

#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{
    ofxPanel gui;
    
    ofShader shader;
    ofxGuiGroup mixer;
    ofTexture image;
    bool showGui;
    ofxToggle kenabled;
    ofxIntSlider ksectors;
    ofxFloatSlider kangle, kx,ky;
    
    ofSpherePrimitive sphere;
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
    
    ofFbo fbo;
    ofFbo fbo2;
    ofFbo fbo3;
    
    ofxFloatSlider rad,deform, deformFreq, extrude;
    vector<ofPoint> vertices0;
    
	public:
		void setup();
		void update();
		void draw();
    void draw2D();
    void draw3D();
    void stripePattern();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    

		
};
