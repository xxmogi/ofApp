#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();
    vol.setup("volume");
    
    vol.add(radius.setup("radius", 70, 50, 200));
    vol.add(ratio.setup("ratio", 100, 50, 1000));
    vol.add(freq.setup("freq", 17, 1, 180));
    gui.add(&vol);
    
    fft.setup("fft");
    fft.add(fftratio.setup("fft", 10, 1, 500));
    fft.add(initHue.setup("color", 150,0,255));
    
    gui.add(&fft);
    
    ofSoundStreamSetup(0, 2, this, 44100, 1024, 2);
    lfo = 0;
    fbo.allocate(ofGetWidth(), ofGetHeight());
    ofBackground(ofColor::black);
    ofSetCircleResolution(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    showGui = false;
   
    

    
}

//--------------------------------------------------------------
void ofApp::update(){
    float f = (ofGetElapsedTimef()/ freq) * 360.0;
    lfo = sin(ofDegToRad(f)) * 180 + 360;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    
    ofBackground(0, 10);
    unsigned int sizeLog2 = (int)(log(256)/log(2));
    unsigned int size = 1 << sizeLog2;
    
    FFTSetup fftSetup = vDSP_create_fftsetup(sizeLog2, FFT_RADIX2);
    
    float* window = (float*)calloc(size, sizeof(float));
    float* windowInput = (float*)calloc(size, sizeof(float));
    vDSP_hann_window(window, size, 0);
    
    vDSP_vmul(buf, 1, window, 1, windowInput, 1, size);
    DSPSplitComplex splitComplex;
    splitComplex.realp = (float*)calloc(size, sizeof(float));
    splitComplex.imagp = (float*)calloc(size, sizeof(float));
    for (int i=0; i<size; i++) {
        splitComplex.realp[i] = windowInput[i];
        splitComplex.imagp[i] = 0.0f;
    }
    
    vDSP_fft_zrip(fftSetup, &splitComplex,1 ,sizeLog2, FFT_FORWARD);
    float max = 0;
    for (int i=1; i<=size/4.0; i++) {
        int xp = ofMap(i, 0, size/4.0, 100, ofGetWidth()-100);
        float v = sqrt(splitComplex.realp[i] *splitComplex.realp[i] + splitComplex.imagp[i] * splitComplex.imagp[i]);
        float val = 10.0f * (float)log10(1 + v) * 2.0f;
        ofPushMatrix();
        ofTranslate(xp, ofGetHeight()/2);
        ofColor base;
        base = ofColor::fromHsb(0, 255, 255);
        base.setHueAngle(fmodf(initHue + (val*10),360));
        ofSetColor(base, 180);
        ofDrawCircle(0, 0, val * fftratio);
        ofPopMatrix();
    }

    
    free(splitComplex.realp);
    free(splitComplex.imagp);
    free(windowInput);
    free(window);
    vDSP_destroy_fftsetup(fftSetup);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight() /2.0);
    prev.set(((buf[2047] + buf[0])/2.0) * ratio + radius,0);
    for(int i=1;i<1024;i++) {
        float deg = fmodf(i * freq, 360);
        float rad = ofDegToRad(deg);
        float r = buf[i] * ratio + radius;
        float x = cos(rad) * r;
        float y = sin(rad) * r;
        float hue = fmodf(ofMap(buf[i], -1.0, 1.0, 100, 255) + deg ,100);
        ofColor color;
        ofSetColor(ofColor::fromHsb(hue, 250, 250), 200);
        ofDrawLine(prev.x, prev.y, x, y);
        prev.set(x, y);
    }
    ofPopMatrix();
    fbo.end();
    
    fbo.draw(0,0, ofGetWidth(), ofGetHeight());
    
    if(showGui){
        gui.draw();
    }
}

void ofApp::audioReceived(float *input, int bufferSize, int nChannels) {
    for (int i=0; i< bufferSize * nChannels; i++) {
        buf[i] = input[i];
    }


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'z') {
        showGui = !showGui;
    } else if(key == 'f') {
        ofSetFullscreen(true);
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

