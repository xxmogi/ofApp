#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <Accelerate/Accelerate.h>

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
    void audioReceived(float * input, int bufferSize, int nChannels);
    float buf[1024 * 2];
    float mug[256];
    
    ofPoint prev;
    
    ofSoundDevice device;
    ofSoundStream stream;
    ofxPanel gui;
    ofxGuiGroup vol;
    ofxIntSlider radius;
    ofxIntSlider ratio;
    ofxIntSlider freq;
   
    ofxGuiGroup fft;
    ofxIntSlider fftratio;
    ofxIntSlider initHue;
    
    
    ofFbo fbo;
    int lfo;
    
    bool showGui;
};
