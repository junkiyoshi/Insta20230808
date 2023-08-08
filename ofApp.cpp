#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255, 64);

	ofNoFill();
	ofSetCircleResolution(72);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;

	for (int i = 0; i < 2; i++) {

		glm::vec3 noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		for (int k = 0; k < 140; k++) {

			color.setHsb(ofMap(k, 0, 140, 0, 255), 150, 255);
			ofSetColor(color, 92);

			ofPushMatrix();

			ofRotate(k * 1 + i * 180);

			ofTranslate(250 * cos(20 * DEG_TO_RAD), 250 * sin(20 * DEG_TO_RAD));

			ofRotateZ(ofMap(ofNoise(noise_seed.z, k * 0.01 + ofGetFrameNum() * 0.003), 0, 1, -180, 180));
			ofRotateY(ofMap(ofNoise(noise_seed.y, k * 0.01 + ofGetFrameNum() * 0.003), 0, 1, -180, 180));
			ofRotateX(ofMap(ofNoise(noise_seed.x, k * 0.01 + ofGetFrameNum() * 0.003), 0, 1, -180, 180));

			ofDrawCircle(glm::vec2(), 50);

			ofPopMatrix();

		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}