//
//  weapon.cpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#include "weapon.hpp"

weapon::weapon(){
    bGetNoWeapon = true;
}


void weapon::update(ofxOscMessage & mes){
    
    
    
    //ボディの信号をうけとったら
    bGetWeapon = false;
    if(mes.getAddress() == "/weapon"){
        //フラグを立てる
        bGetWeapon = true;
        
    }else if(mes.getAddress() == "/noWeapon"){
        // bodyがなくなったときの最初のみ送信
        bGetNoWeapon = true;
    }
    
    if(bGetWeapon){
        //初期化
        
        bGetNoWeapon = false;
        weaponVec.clear();
        weaponNo.clear();
        int mN = mes.getNumArgs();
        int nowMesNo = 0;
        
        while(mN>nowMesNo){
            int no = mes.getArgAsInt(nowMesNo+0);
            weaponNo.push_back(no);
            
            ofVec2f wV;
            wV = ofVec3f(mes.getArgAsInt(nowMesNo+1),mes.getArgAsInt(nowMesNo+2));
            weaponVec.push_back(wV);
            
            nowMesNo+=3;
        }
    }
}

void weapon::draw(){
    if(bGetNoWeapon){
        ofSetColor(100, 100, 100,100);
        ofRectangle(0,0,512,426);
    }else{
        ofSetColor(0, 0, 255,100);
        ofRectangle(0,0,512,426);
    }
    
    if(!bGetNoWeapon){
        for(int i = 0; i < weaponVec.size(); i++){
            if(weaponNo[i] == 0 ){ ofSetColor(255,255,100);}
            else{ ofSetColor(100,255,255);}
            ofDrawRectangle(weaponVec[i]-ofVec2f(5,5),10,10);
        }
    }
}


int weapon::getWeaponNum(){
    if(!bGetNoWeapon){
        return weaponVec.size();
    }else{
        return 0;
    }
}

bool weapon::isOsc(){
    return bGetWeapon && bGetNoWeapon;
}