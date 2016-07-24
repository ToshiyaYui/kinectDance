//
//  bodysHand.hpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#ifndef bodysHand_hpp
#define bodysHand_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"

class bodysHand {
public:
    bodysHand();
    //oscを受けて更新
    void update(ofxOscMessage & mes);
    
    //描画
    void draw();
    bool isOsc();
    int getBodyNum();
    //oscを受け取ったかどうか
    bool bGetBodyHand;
    bool bGetNoBody;
    
    //左0, 右1
    vector<int> bodyNo;
    
    //polylineのベクター
    vector<ofVec3f> bodyLeftHandVec;
    vector<ofVec3f> bodyRightHandVec;
    // 1 2 3 4?
    vector<int> bodyLeftHandState;
    vector<int> bodyRightHandState;
private:
    
    
};
#endif /* bodysHand_hpp */
