#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    
    current_msg_string = 0;
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
    
    ofBackground(30, 30, 130);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // check for mouse moved message
        if(m.getAddress() == "/poly"){
            // both the arguments are int32's
            poly.clear();
            for(int i = 0 ; i < m.getNumArgs()/2; i++){
                poly.addVertex(m.getArgAsInt(i*2), m.getArgAsInt(i*2+1));
            }
            poly.close();
        }
        else if(m.getAddress() == "/image" ){
            ofBuffer buffer = m.getArgAsBlob(0);
            receivedImage.load(buffer);
        }
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    string buf;
    buf = "listening for osc messages on port" + ofToString(PORT);
    ofDrawBitmapString(buf, 10, 20);
    
    if(receivedImage.getWidth() > 0){
        ofDrawBitmapString("Image:", 10, 160);
        receivedImage.draw(10, 180);
    }
    ofPushMatrix();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    poly.draw();
    ofPopMatrix();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);

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
