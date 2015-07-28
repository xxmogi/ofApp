#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    ofxPanel gui;
    ofxIntSlider x;
    ofxIntSlider y;
    ofxIntSlider z;
    ofxToggle kenable;
    
    ofxGuiGroup mixer;
    ofxIntSlider ksectors;
    ofxFloatSlider kangle, kx,ky;
    
    
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
//    ofFbo fbo;
    
    ofShader shader;
    ofTexture image;
    ofSpherePrimitive sphere;
    
	public:
		void setup();
		void update();
		void draw();
    void draw3D();

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
