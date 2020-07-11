#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update(){
    //
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    shader.begin();

    shader.setUniform1f("time", ofGetElapsedTimef());

	float width = ofGetWidth();
	float height = ofGetHeight();

	const float resolution[2] = {width, height};

	shader.setUniform2fv("resolution", resolution);

    ofDrawRectangle(0, 0, width, height);
    
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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