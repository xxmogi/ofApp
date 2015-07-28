#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    leap.open();
    ofBackground(ofColor::white);
    gui.setup();
    gui.add(place.setup("place", 0, -200, 200));
    ofSetFrameRate(30);
    ofSetCircleResolution(128);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    hands = leap.getSimpleHands();
    if(leap.isFrameNew() && hands.size()) {
        fingerPos.clear();
        handPos.clear();
        leap.setMappingX(-230, 230,0, ofGetWidth() );
        leap.setMappingY(90, 490, ofGetHeight(), 0);
        leap.setMappingZ(-150, 150, -200, 200);
        for(int i=0;i<hands.size();i++) {
            handPos.push_back(hands[i].handPos);
            for(int j=0;j<hands[i].fingers.size();j++) {
                fingerPos.push_back(hands[i].fingers[j].pos);
               
            }
        }
        
    }
    
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i< fingerPos.size(); i++) {
        //ofDrawRectangle(fingerPos[i].x, fingerPos[i].y, 20, 20);
    }

    float time = ofGetElapsedTimef();
    float longitude = 10 * time;
    float latitude = 100;
    float radius = 100;
    
    for(int j=0;j<hands.size();j++) {
        vector<ofPoint> points;
        ofxLeapMotionSimpleHand hand = hands[j];
        for(int k=0;k < hand.fingers.size();k++) {
//            ofDrawLine(hand.fingers[k].base, hand.fingers[k].pos);
            if (hand.fingers[k].pos.z < place) {
                ofFill();
                ofSetColor(ofColor::cyan, 100);
//                ofDrawCircle(hand.fingers[k].pos, 10);
                points.push_back(hand.fingers[k].pos);
            }
            
        }
        if(points.size() < 5) {
            continue;
        }
        
        ofMatrix3x3 ma,mb;
        ofMatrix3x3 va,vb;
        for(int l=0;l<points.size();l++) {
            ofPoint p = points.at(l);
            mb.set(p.x * p.x, p.x * p.y, p.x,
                   p.x * p.y, p.y * p.y, p.y,
                   p.x, p.y, 1);
            ma += mb;
            vb.set(pow(p.x, 3) + p.x * pow(p.y ,2), 0, 0,
                   pow(p.x, 2) * p.y + pow(p.y, 3), 0, 0,
                   pow(p.x, 2) + pow(p.y,2), 0, 0);
            va -= vb;
        }
        
        ma.invert();
        va = ma * va;
        int x = va[0] / -2;
        int y = va[3] / -2;
        int r = sqrt(x * x + y*y - va[6]);
        if(r > 100) {
            r -= r%100;
            ofNoFill();
            ofSetLineWidth(5);
            ofSetColor(ofColor::magenta, 250);
            ofDrawCircle(x,y ,r);
            ofFill();
            ofSetColor(ofColor::magenta, 50);
            ofDrawCircle(x,y ,r);
            
        }
    }
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
