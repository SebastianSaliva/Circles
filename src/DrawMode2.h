#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode2: public FractalMode {

    public:
    
    ofColor color1;
    ofColor color2;
    ofColor color3;
    DrawMode2():FractalMode(){color1 = ofColor(255, 0, 0); color2 = ofColor(255, 0, 0); color3 = ofColor(255, 0, 0);}

    string getName() {return "Trees";}

    void draw(){}

    void draw(int length, int n, int x, int y, int d) {

        ofNoFill();


        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}

        if(n > 0){
            int middleY = y-length;
            int leftBranchX = x -length*cos(PI/180*d);
            int leftBranchY = middleY -length*sin(PI/180*d);
            int rightBranchX = x +length*cos(PI/180*d);
            int rightBranchY = middleY -length*sin(PI/180*d);

            ofDrawLine(x, y, x,y-length);
            ofDrawLine(x, y-length, rightBranchX, rightBranchY);
            ofDrawLine(x,y-length, leftBranchX, leftBranchY);

            this->draw(length/2, n-1,rightBranchX,rightBranchY, 30);
            this->draw(length/2,n-1,leftBranchX,leftBranchY, 30);
        }
    }
};
