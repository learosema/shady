#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	ofxJSONElement response;
	shader.load("shader");
	std::string url = "https://api.github.com/repos/terabaud/bunch-of-shaders/contents/shaders";
	std::string data = downloadResource(url);
 
    if (! response.parse(data)) {
    	ofLogNotice("ofApp::setup") << "Failed to load JSON. Fallback to offline shader.";
    	shader.load("shader");
	    return;
    }
    std::size_t numFiles = response.size();
    
	for (Json::ArrayIndex i = 0; i < numFiles; i++) {
		RepositoryFile repoFile;
		repoFile.name = response[i]["name"].asString();
		repoFile.path = response[i]["path"].asString();
		repoFile.downloadUrl = response[i]["download_url"].asString();
		if (repoFile.name.rfind(".frag") != std::string::npos) {
			shaders.push_back(repoFile);
			std::cout << repoFile.name << std::endl;	
		}
	}

	int randomFile = (int)ofRandom(0, shaders.size()); 
	std::string fragShader = downloadResource(shaders[randomFile].downloadUrl);
	std::cout << "Fragment shader source: -------------------" << std::endl;
	std::cout << fragShader << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	shader.setupShaderFromFile(GL_VERTEX_SHADER, "shader.vert");
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragShader);
	shader.bindDefaults();
	shader.linkProgram();
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

//--------------------------------------------------------------
std::string ofApp::downloadResource(const std::string& url){
	ofHttpRequest request(url, url);
	request.headers["User-Agent"] = "Mozilla/5.0 (X11; Linux armv7l) AppleWebKit/537.36 (KHTML, like Gecko) Raspbian Chromium/78.0.3904.108 Chrome/78.0.3904.108 Safari/537.36";
	ofURLFileLoader loader;
	std::string data = loader.handleRequest(request).data.getText();
	return data;
}


