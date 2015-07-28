#include "ofApp.h"
#include "ofxGui.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofLoadImage(image, "img.jpg");
    gui.setup("Parameters", "settings.xml");
    shader.load("kaleido");
    
    mixer.setup("mixer");
    mixer.add(kenabled.setup("kenabled", true));
    mixer.add(ksectors.setup("ksectos", 10,1,100));
    mixer.add(kangle.setup("kangle",0, -180,180));
    mixer.add(kx.setup("kx", 0.5, 0, 1));
    mixer.add(ky.setup("ky", 0.5, 0, 1));
    
    mixer.add(rad.setup("rad",250, 0, 500));
    mixer.add(deform.setup("deform", 0.3,0,1.5));
    mixer.add(deformFreq.setup("deform freq", 3, 0, 10));
    mixer.add(extrude.setup("extrude",1,0,1));

    
    gui.add(&mixer);
    
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    
    sphere.set(250, 20);
    vertices0 = sphere.getMesh().getVertices();
    fbo2.allocate(ofGetWidth(), ofGetHeight());
    float w = fbo2.getWidth();
    float h = fbo2.getHeight();
    sphere.mapTexCoords(0, h, w, 0);
    sphere.rotate(180, 0, 1, 0);
    
    fbo3.allocate(ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::update(){
    vector<ofPoint> &vertices = sphere.getMesh().getVertices();
    float deforms = sin(ofGetElapsedTimef()) * 10;
    for (int i=0; i<vertices.size(); i++) {
        ofPoint v = vertices0[i];
        v.normalize();
        float sx = sin(v.x * deformFreq);
        float sy = sin(v.y * deformFreq);
        float sz = sin(v.z * deformFreq);
        v.x += sy * sz * deforms;
        v.y += sx * sz * deforms;
        v.z += sx * sy * deforms;
        v *= rad;
        vertices[i] = v;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo2.begin();
    if(kenabled) {
        shader.begin();
        shader.setUniform1i("ksectors", ksectors);
        shader.setUniform1f("kangleRad", ofDegToRad(kangle));
        shader.setUniform2f("kcenter", kx * ofGetWidth(), ky* ofGetHeight());
        shader.setUniform2f("screenCenter", 0.5 * ofGetWidth(), 0.5 * ofGetHeight());
    }
    
    
    
    fbo.begin();
    draw2D();
    fbo.end();
    
    fbo.draw(0,0, ofGetWidth(), ofGetHeight());
    if(kenabled) {
        shader.end();
    }
    fbo2.end();

    draw3D();

    
    
    if(showGui) {
        gui.draw();
    }
}

void ofApp::draw2D(){
    ofSetColor(255);
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::draw3D(){
    fbo2.getTexture().bind();
    float time = ofGetElapsedTimef();
    float longitude = time * 10;
    float latitude = 10 * sin(time * 0.8);
    float radius = 600 + 50 * sin(time * 0.4);
    cam.orbit(longitude, latitude, radius, ofPoint(0,0,0));
    light.setPosition(ofGetWidth()/2.0, ofGetHeight()/2.0, 600);
    light.enable();
    material.begin();
    ofEnableDepthTest();
    
    cam.begin();
    ofSetColor(ofColor::white);
    sphere.draw();
    cam.end();
    
    ofDisableDepthTest();
    material.end();
    light.disable();
    ofDisableLighting();
    fbo2.getTexture().unbind();
}

void ofApp::stripePattern() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'z') {
        showGui = !showGui;
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
