//
//  bodysPolyline.hpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#ifndef bodysPolyline_hpp
#define bodysPolyline_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"

class bodysPolyline {
public:
    bodysPolyline();
    //oscを受けて更新
    void update(ofxOscMessage & mes);
    
    //描画
    void draw();
    bool isOsc();
    int getPolyNum();
    int getBodyNum();
    //oscを受け取ったかどうか
    bool bGetBodyPoly;
    bool bGetNoBody;
    
    //左0, 右1
    vector<int> bodyNo;
    
    //polylineのベクター
    vector<ofPolyline> bodyPolyVec;
private:
    
    
};

#endif /* bodysPolyline_hpp */
