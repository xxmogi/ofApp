#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("gui", "setting.xml");
    gui.add(enabled.setup("shader", false));
    gui.add(val.setup("val", 8.0, 1.0, 20.0));
    ofLoadImage(image, "img.jpg");
    shader.load("laplacian");
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::update(){
 

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    fbo.begin();
    if(enabled) {
        shader.begin();
    }
    ofSetColor(ofColor::white);
    image.draw(0,0,ofGetWidth(), ofGetHeight());
    if(enabled) {
        shader.end();
        shader.setUniform1f("val", val);
    }
    fbo.end();
    
    fbo.draw(0,0,ofGetWidth(),ofGetHeight());
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
