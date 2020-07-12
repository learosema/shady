#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

struct RepositoryFile {
	std::string name;
	std::string path;
	std::string downloadUrl;
};


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofShader shader;
        std::vector<RepositoryFile> shaders;

	private:
		std::string downloadResource(const std::string& url);
};
