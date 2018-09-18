#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255, 255, 255);

	ofSetVerticalSync(true);

	fileName = "rhino.obj";
	// load the wavefront object model
	model.loadModel(fileName , 30);

	model.setRotation(2, 90, 1, 1, 0);
	model.setScale(0.8, 0.8, 0.8);
	light.setPosition(0, 0, 500);

	cameraOrbit = 0;
	camera.setDistance(700);

}

//--------------------------------------------------------------
void ofApp::update(){
	cameraOrbit += ofGetLastFrameTime() * 20.; // 20 degrees per second;
	camera.orbitDeg(cameraOrbit, 0., camera.getDistance(), { 0., 0., 0. });
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableDepthTest();

	light.enable();

	camera.begin();
	ofColor(255, 255);
	// documentation: https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
	
	//model.setPosition(ofGetWidth() / 2, (float)ofGetHeight() * 0.75, 0);
	model.drawFaces();
	camera.end();

	light.disable();
	ofDisableDepthTest();

	stringstream ss;
	ss << "Frames Per Second: " << ofToString(ofGetFrameRate(), 0) << endl;
	ss << "Name of file: " + fileName << endl;
	ofDrawBitmapString(ss.str().c_str(), 20, 20);

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
