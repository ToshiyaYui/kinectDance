#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(40, 100, 40);
    
    // open an outgoing connection to HOST:PORT
    sender.setup(HOST, PORT);
    
    imgAsBuffer = ofBufferFromFile("of-logo.png", true);
    
     ofSetFrameRate(20);
}

//--------------------------------------------------------------
void ofApp::update(){
    poly.clear();
    float i = 0;
    int ii = 0;
    while (i < TWO_PI) { // make a heart
        float r = (2-2*sin(i) + sin(i)*sqrt(abs(cos(i))) / (sin(i)+1.4)) * -80+(1+sin(ofGetElapsedTimef()*3)*30);
        float x = cos(i) * r;
        float y = sin(i) * r;
        poly.addVertex(ofVec2f(x,y));
        i+=0.005*HALF_PI*0.5;
        ii++;
    }
    poly.close(); // close the shape
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    poly.draw();
    ofPopMatrix();
    ofxOscMessage m;
    
    vector<ofPoint> & vecP = poly.getVertices();
    m.setAddress("/poly");
    for(int i = 0; i < (int)poly.size();i++){
        m.addIntArg(vecP.at(i).x);
        m.addIntArg(vecP.at(i).y);
    }
    sender.sendMessage(m);
    
    
    
    if(img.getWidth() > 0){
        ofDrawBitmapString("Image:", 10, 160);
        img.draw(10, 180);
    }
    
    
    
    ofBuffer buff;
    //buff.set(&poly , poly.size());
    
    // display instructions
    string buf;
    buf = "sending osc messages to" + string(HOST) + ofToString(PORT);
    ofDrawBitmapString(buf, 10, 20);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'i' || key == 'I'){
        img.load(imgAsBuffer);
        
        ofxOscMessage m;
        m.setAddress("/image");
        m.addBlobArg(imgAsBuffer);
        sender.sendMessage(m);
        cout << "ofApp:: sending image with size: " << imgAsBuffer.size() << endl;
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
