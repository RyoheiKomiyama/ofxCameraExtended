//
//  OrbitCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/21.
//
//

#include "OrbitCamera.h"

namespace ofxCameraExtended{

    OrbitCamera::OrbitCamera(){
        longitude = 0; // [degree]
        latitude = 0; // [degree]
        radius = 1000; // [cm]
        
        speed_longitude = 20; // [degree/s]
        speed_latitude = 10; // [degree/s]
        
        target_node.setPosition(0, 0, 0);
    }
    
    OrbitCamera::~OrbitCamera(){
        
    }
    
    void OrbitCamera::update(){
        float current_time = ofGetElapsedTimef();
        
        longitude += (current_time-last_updated_time)*speed_longitude;
        latitude += (current_time-last_updated_time)*speed_latitude;
        orbit(longitude, latitude, radius, target_node);
        //lookAt(target_node, ofVec3f(0, 1, 0));
        
        last_updated_time = current_time;
    }
    
    void OrbitCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 5);
        ofDrawBitmapString("OrbitCamera", getPosition()+ofVec3f(1, 1, 1)*10);
        float arrowsize = 50;
        ofSetColor(255, 0, 0);
        ofDrawArrow(getPosition(), getPosition()-getSideDir()*arrowsize);
        ofSetColor(0, 255, 0);
        ofDrawArrow(getPosition(), getPosition()+getUpDir()*arrowsize);
        ofSetColor(0, 0, 255);
        ofDrawArrow(getPosition(), getPosition()+getLookAtDir()*arrowsize);
        ofPopStyle();
        ofPopMatrix();
    }
    
    void OrbitCamera::setParameters(float longitude, float latitude, float radius, float speed_longitude, float speed_latitude){
        this->longitude = longitude;
        this->latitude = latitude;
        this->radius = radius;
        this->speed_longitude = speed_longitude;
        this->speed_latitude = latitude;
    }

}
