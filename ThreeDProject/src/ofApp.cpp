#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("gui", "setting.xml");
    gui.add(x.setup("X scale",1, 1,10));
    gui.add(y.setup("Y Scale", 1, 1,10));
    gui.add(z.setup("Z scale", 1, 1, 10));
    mixer.setup("mixer");
    mixer.add(kenable.setup("kenabled", true));
    mixer.add(ksectors.setup("ksectos", 10,1,100));
    mixer.add(kangle.setup("kangle",0, -180,180));
    
    mixer.add(kx.setup("kx", 0.5, 0, 1));
    mixer.add(ky.setup("ky", 0.5, 0, 1));
    
    gui.add(&mixer);

    sphere.set(250, 20);
    ofLoadImage(image, "img.jpg");
    shader.load("kaleido");
    
    ofBackground(ofColor::black);
//    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
//    float w = fbo.getWidth();
//    float h = fbo.getHeight();
//    sphere.mapTexCoords(0, h, w, 0);
//    sphere.rotate(180,0,1,0);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofPopMatrix();
    
//    fbo.begin();
    draw3D();
//    fbo.end();
//    fbo.draw(0,0,ofGetWidth(),ofGetHeight());
    gui.draw();
    
}

void ofApp::draw3D(){
//    fbo.getTexture().bind();
    light.setPosition(ofGetWidth()/2.0, ofGetHeight()/2.0, 600);
    light.enable();
    material.begin();
    ofEnableDepthTest();
    
    float time = ofGetElapsedTimef();
    float longitude = 10 * time;
    float latitude = 10 + sin(time * 0.8);
    float radius = 600 + 50 * sin(time * 0.4);
    cam.orbit(longitude, latitude, radius, ofPoint(0,0,0));
    cam.begin();
    ofSetColor(ofColor::darkBlue);
    sphere.draw();
    cam.end();
    
    ofDisableDepthTest();
    material.end();
    light.disable();
    ofDisableLighting();
//    fbo.getTexture().unbind();
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
