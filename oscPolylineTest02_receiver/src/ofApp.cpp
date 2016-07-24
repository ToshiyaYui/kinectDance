#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    
    ofBackground(30, 30, 130);
    
    // syphon
    mainOutputSyphonServer.setName("Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        bp.update(m);
        bh.update(m);
        wp.update(m);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255);
    bp.draw();
    bh.draw();
    wp.draw();
    
    ofSetColor(255);
    string buf;
    buf = "listening for osc messages on port" + ofToString(PORT);
    ofDrawBitmapString(buf, 10, 20);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
    mClient.draw(50,50);
    mainOutputSyphonServer.publishScreen();
    
    int separateLine = 100;
    ofDrawLine(separateLine,0,separateLine, 512);
    
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
