#include "ofApp.h"
using namespace std;

float width = 800;
float height = 600;
float y = 100;
float d = width / 10;
float r = d/2;

int numCirclesX = width / r + 2;
int numCirclesY = height / r + 2;

vector<int> doDrawCircle;

ofColor paperColour(240, 235, 220);
ofColor circleColour(5, 10, 15);

//--------------------------------------------------------------

void DrawFirstLayerCircles();
void DrawSecondLayerCircles();

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(paperColour);
    
    ofLog(OF_LOG_NOTICE, ofToString(numCirclesX));
    ofLog(OF_LOG_NOTICE, ofToString(numCirclesY));
    
    ofLog(OF_LOG_NOTICE, ofToString(((int)roundf(ofRandom(1)) % 2)));
    ofSetLineWidth(1);
    
    int numCirclesTotal = numCirclesX * numCirclesY;
    for (int i = 0; i < numCirclesTotal; i++)
    {
        doDrawCircle.push_back((int)roundf(ofRandom(1)) % 2);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofNoFill();
    ofSetColor(circleColour);
    DrawFirstLayerCircles();
    DrawSecondLayerCircles();
    
    ofFill();
    ofSetColor(paperColour);
    ofDrawRectangle(0, 0, width, r);
    ofDrawRectangle(width - r, 0, r, height);
    ofDrawRectangle(0, height - r, width, r);
    ofDrawRectangle(0, 0, r, height);
}

void DrawFirstLayerCircles()
{
    for (int x = 0; x < numCirclesX; x++)
    {
        for (int y = 0; y < numCirclesY; y++)
        {
            ofDrawEllipse(x * d, y * d, d, d);
        }
    }
}

void DrawSecondLayerCircles()
{
    for (int x = 0; x < numCirclesX; x++)
    {
        for (int y = 0; y < numCirclesY; y++)
        {
            if (doDrawCircle[x * numCirclesX + y])
            {
                ofDrawEllipse(x * r, y * r, d, d);
            }
        }
    }
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
