#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxSyphon.h"
#include "bodysPolyline.hpp"
#include "bodysHand.hpp"
#include "weapon.hpp"
// listen on port 12345
#define PORT 12346
#define NUM_MSG_STRINGS 20

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofTrueTypeFont font;
    ofxOscReceiver receiver;
    
    int current_msg_string;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
    
    
    
    
    
     //syphon
     ofxSyphonServer mainOutputSyphonServer;
     ofxSyphonServer individualTextureSyphonServer;
     ofxSyphonClient mClient;
    
    ofTexture tex;
    
    bodysPolyline bp;
    bodysHand bh;
    weapon wp;

		
};
