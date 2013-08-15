/*
 ------------------------------------------------------------------
 
 >> atlas << random channel matrix
 This app has been developed for >> atlas << by Nicolas Romanacci.
 >> ars dilettanti << exhibition, Germany, 15 - 16 March 2013.
 Exhibition: http://arsdilettanti.de/content/nicolas-romanacci
 Youtube: http://www.youtube.com/watch?v=Ou5xSzix4VQ&list=PL6F73FC87598524CB
 About Nicolas Romanacci: http://www.celesteprize.com/nicolasrom
           __   .__
 _____   _/  |_ |  |  _____     ______
 \__  \  \   __\|  |  \__  \   /  ___/
  / __ \_ |  |  |  |__ / __ \_ \___ \
 (____  / |__|  |____/(____  //____  >
      \/                   \/      \/
 
 Author: Martin Burkhard
 License: The MIT License (MIT)
 Version: 0.2 (2013-03-15)
 Github: https://github.com/burkhardm/atlas
 
 ------------------------------------------------------------------ */
#pragma once

#include "ofMain.h"
#include <list>
#include <iterator>
#include "atlasMovie.h"

#define GLUT_LEFT_BUTTON                0
#define GLUT_MIDDLE_BUTTON              1
#define GLUT_RIGHT_BUTTON               2

class atlasApp: public ofBaseApp {

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
    
private:
    atlasMovie getNextMovieFile();
    int mapPosToPlayer(int x, int y);
    
    // Movie Sizes
    int movieWidth;
    int movieHeight;
    
    // Movie Screen Offsets
    int offsetX;
    int offsetY;
    int offsetX2;
    int offsetY2;
    int offsetX3;
    int offsetY3;
    
    // Movie List
    vector<atlasMovie> movieList;
    vector<atlasMovie>::iterator movieListIterator;
    
    // Movie Player
    ofVideoPlayer player[9];
    int amountOfPlayers;
    bool pauseAll;
    
    // Movie Details
    string movieName;
    string movieDescription;
    int movieNamePosX;
    int movieNamePosY;
};

