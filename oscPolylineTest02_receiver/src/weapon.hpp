//
//  weapon.hpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#ifndef weapon_hpp
#define weapon_hpp

#include <stdio.h>

#include "ofMain.h"
#include "ofxOsc.h"

class weapon {
public:
    weapon ();
    //oscを受けて更新
    void update(ofxOscMessage & mes);
    
    //描画
    void draw();
    bool isOsc();
    int getWeaponNum();
    //oscを受け取ったかどうか
    bool bGetWeapon;
    bool bGetNoWeapon;
    
    //左0, 右1
    vector<int> weaponNo;
    
    //polylineのベクター
    vector<ofVec2f> weaponVec;
private:
    
    
};

#endif /* weapon_hpp */
