#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(200);
    ofDisableAntiAliasing();
    ofEnableAlphaBlending();
    ofDisableArbTex();

    rotationX = 0;
    rotationY = 0;
    ofSetFrameRate(60);
    imgon = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (imgon) {
        ofSetColor(255);
        for (int i = 0; i < imgPlanes.size(); i++){
            ofLog() << i << " X:" << imgPlanes[i].getX()
            << " Y:" << imgPlanes[i].getY()
            << " Z:" << imgPlanes[i].getZ();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();

    ofSetColor(255);
    ofPushMatrix();
    ofRotateY(rotationY);
    ofRotateX(rotationX);
    for (int i = 0; i < lines.size(); i++){
        lines[i].draw();
    }
    if (imgon) {
        ofSetColor(255);
        for (int i = 0; i < imgPlanes.size(); i++){
            imgTextures[i].getTextureReference().bind();
            imgPlanes[i].draw();
            imgTextures[i].getTextureReference().unbind();
        }

    }
    ofPopMatrix();
    camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        rotationY = mouseX % 360;
        rotationX = mouseY % 360;
    }
    if(key == 'z'){
        depth = mouseY;
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
//    lines[lines.size() - 1].addVertex(ofPoint(x, y, depth));

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    ofPolyline polyline;
//    lines.push_back(polyline);

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
    if( dragInfo.files.size() > 0 ){
		for(int i = 0; i < dragInfo.files.size(); i++){
//            composer.addPatch( dragInfo.files[i], dragInfo.position );
            
            ofImage newImg;
            ofPlanePrimitive newPlane;
            imgTextures.push_back(newImg);
            imgTextures[imgTextures.size()-1].loadImage(dragInfo.files[i]);
            imgPlanes.push_back(newPlane);
            imgPlanes[imgPlanes.size()-1].set(imgTextures[imgTextures.size()-1].width, imgTextures[imgTextures.size()-1].height,2 , 2);
            imgPlanes[imgPlanes.size()-1].setPosition(dragInfo.position.x, dragInfo.position.y, depth);
            imgon = true;
		}
	}
}
