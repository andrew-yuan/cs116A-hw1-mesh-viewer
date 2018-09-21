#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255, 255, 255);

	ofSetVerticalSync(true);


}

//--------------------------------------------------------------
void ofApp::update(){

}

// documentation: https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//--------------------------------------------------------------
void ofApp::draw(){
	// DepthTest prevents model from being see through
	ofEnableDepthTest();

	this->light.enable();

	this->camera.begin();
	this->drawFunction();
	this->camera.end();

	this->light.disable();
	ofDisableDepthTest();

	// Prints out FPS and Name of File
	stringstream ss;
	ss << "Frames Per Second: " << ofToString(ofGetFrameRate(), 0) << endl;
	ofDrawBitmapString(ss.str().c_str(), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'w':
            this->changeDrawFunction(&ofxAssimpModelLoader::drawWireframe);
            break;
        case 'f':
            this->changeDrawFunction(&ofxAssimpModelLoader::drawFaces);
            break;
        case 'v':
            this->changeDrawFunction(&ofxAssimpModelLoader::drawVertices);
            break;
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
	this->model.loadModel(dragInfo.files[0], 20);
	this->changeDrawFunction(&ofxAssimpModelLoader::drawWireframe);
}

void ofApp::changeDrawFunction(std::function<void(ofxAssimpModelLoader)> func) {
    this->drawFunction = std::bind(func, this->model);
}