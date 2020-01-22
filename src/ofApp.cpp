#include "ofApp.h"
using namespace std;

//two arrays for each grid spot, circleCentre and circleEdge
/*
 [ x-1, y-1 ][ x, y-1 ][ x+1, y-1 ]
 [ x-1, y   ][ x, y   ][ x+1, y   ]
 [ x-1, y+1 ][ x, y+1 ][ x+1, y+1 ]
 */

// loop through all positions, if a grid spot is neither centre or edge, generate a circle there and update the centres and edges

// repeatedly do this until there are no free spaces

// draw an ellipse in each centre spot!


float width = 800;
float height = 600;
float y = 100;
float d = width / 10;
float r = d/2;

int numCirclesX = width / r + 2;
int numCirclesY = height / r + 2;

vector<int> isCircleCentre;
vector <int> isCircleEdge;


ofColor paperColour(240, 235, 220);
ofColor circleColour(5, 10, 15);

//--------------------------------------------------------------

void DrawFirstLayerCircles();
int GetIndexFromRowAndCol(int x, int y);
bool IndexIsInRange(int index, vector<int> vector);
void GenerateRandomCircles();

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(paperColour);
    
    ofLog(OF_LOG_NOTICE, ofToString(numCirclesX));
    ofLog(OF_LOG_NOTICE, ofToString(numCirclesY));
    
    ofSetLineWidth(1);
    
    isCircleCentre.resize(numCirclesX * numCirclesY, 0);
    isCircleEdge.resize(numCirclesX * numCirclesY, 0);
    
    // put in GenerateRandomCircles function
    GenerateRandomCircles();
    
    //make another loop that loops through grid and keeps calling GenerateRandomCircles as long as theres empty spaces
    
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
    
    ofFill();
    ofSetColor(paperColour);
    /*
    ofDrawRectangle(0, 0, width, r);
    ofDrawRectangle(width - r, 0, r, height);
    ofDrawRectangle(0, height - r, width, r);
    ofDrawRectangle(0, 0, r, height);
     */
}

void DrawFirstLayerCircles()
{
    for (int x = 0; x < numCirclesX; x++)
    {
        for (int y = 0; y < numCirclesY; y++)
        {
            if (isCircleCentre[x * numCirclesX + y])
            {
                ofDrawEllipse(x * r, y * r, d, d);
            }
        }
    }
}

int GetIndexFromRowAndCol(int x, int y)
{
    int columns = numCirclesX;
    return x * columns + y;
}

bool IndexIsInRange(int index, vector<int> vector)
{
    if (index < vector.size() && index >= 0)
    {
        return true;
    }
    return false;
}

void GenerateRandomCircles()
{
    for (int x = 0; x < numCirclesX; x++)
    {
        for (int y = 0; y < numCirclesY; y++)
        {
            int index = GetIndexFromRowAndCol(x, y);
            if (isCircleCentre[index] != 1 && isCircleEdge[index] != 1)
            {
                int circleDrawn = (int)roundf(ofRandom(1)) % 2;
                
                if (circleDrawn)
                {
                    int index;
                    
                    // circle centre
                    index = GetIndexFromRowAndCol( x  , y   );
                    if (IndexIsInRange(index, isCircleCentre))
                    {
                        isCircleCentre[index] = circleDrawn;
                    }
                    
                    // circle edges
                    index = GetIndexFromRowAndCol( x-1, y-1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x,   y-1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x+1, y-1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x+1, y   );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x+1, y+1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x,   y+1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x-1, y+1 );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                    
                    index = GetIndexFromRowAndCol( x-1, y   );
                    if (IndexIsInRange(index, isCircleEdge))
                    {
                        isCircleEdge[index] = circleDrawn;
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    img.grabScreen(0,0,width,height);
    img.save("render_2.png");
    ofLog(OF_LOG_NOTICE, "image saved");
    
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
