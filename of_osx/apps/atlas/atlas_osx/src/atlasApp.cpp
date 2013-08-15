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

#include "atlasApp.h"

void atlasApp::setup(){
	ofBackground(0, 0, 0);

    movieWidth = 320;
    movieHeight = 240;
    pauseAll = false;
    movieName = "";
    movieDescription = "";
    
    // Calculate Movie Screen Offsets
    offsetY = (ofGetScreenHeight() - 3 * movieHeight) / 4;
    offsetX = (ofGetScreenWidth() - 3 * movieWidth - 2*offsetY) / 2; // evenly distributed
    offsetX2 = offsetX+offsetY+movieWidth;
    offsetY2 = 2*offsetY+movieHeight;
    offsetX3 = offsetX+2*offsetY+2*movieWidth;
    offsetY3 = 3*offsetY+2*movieHeight;
    
    // Initializes movie list with description for every video
    movieList.push_back(atlasMovie("cage",      "a strange animal, being trapped\n"
                                                "literally and visually.\n"
                                                "the camera passes the cage\n"
                                                "like anautomated surveillance\n"
                                                "cam. or is the animal watching\n"
                                                "the viewer?\n"
                                                "a study about the relation\n"
                                                "between nature and men,\n"
                                                "between watching and being\n"
                                                "watched.\n"
                                                "or just a visualized nightmare\n"
                                                "about being trapped?\n"
                                                "rilke's \"panther\" seems\n"
                                                "not so far away.",
                                                "Nicolas Romanacci",
                                                "atlas/cage.mov"));
    movieList.push_back(atlasMovie("care",      "a study about the interconnections\n"
                                                "between idyll and fear.",
                                                "Nicolas Romanacci",
                                                "atlas/care.mov"));
    movieList.push_back(atlasMovie("crossing",  "one short moment, like watching\n"
                                                "a girl crossing a street can\n"
                                                "stand for a whole state of mind\n"
                                                "in your life.\n"
                                                "recorded Berlin 2007.",
                                                "Nicolas Romanacci",
                                                "atlas/crossing.mov"));
    movieList.push_back(atlasMovie("curve",     "another study of bodies interacting.\n"
                                                "movement, form, re-action, breathing.\n"
                                                "fragile reciprocity",
                                                "Nicolas Romanacci",
                                                "atlas/curve.mov"));
    movieList.push_back(atlasMovie("drag (system for passing III)",
                                                "a study about time, appearance\n"
                                                "and vanishing.",
                                                "Nicolas Romanacci",
                                                "atlas/drag.mov"));
    movieList.push_back(atlasMovie("draw",      "considering the drawing of a child\n"
                                                "as something highly precious and\n"
                                                "to be protected in any sense,\n"
                                                "it is disturbing watching these\n"
                                                "drawings being moved by air draft\n"
                                                "of an opendoor, surrounded by\n"
                                                "strange, raw and disturbing sounds.\n"
                                                "the freedom of a child's drawing\n"
                                                "does not go well together with\n"
                                                "the sound of church bells,\n"
                                                "expressing power and oppression.",
                                                "Nicolas Romanacci",
                                                "atlas/draw.mov"));
    movieList.push_back(atlasMovie("eclipse chase",
                                                "about being trapped\n"
                                                "in a nightmare",
                                                "Nicolas Romanacci",
                                                "atlas/eclipsechase.mov"));
    movieList.push_back(atlasMovie("elfin",
                                                "No description available.",
                                                "Nicolas Romanacci",
                                                "atlas/elfin.mov"));
    movieList.push_back(atlasMovie("feld (system for passing)",
                                                "hommage to Cy Twombly,\n"
                                                "especially regarding some\n"
                                                "of his 1971 works",
                                                "Nicolas Romanacci",
                                                "atlas/feld.mov"));
    movieList.push_back(atlasMovie("fence (system for passing II)",
                                                "study",
                                                "Nicolas Romanacci",
                                                "atlas/fence.mov"));
    movieList.push_back(atlasMovie("flight",
                                                "recorded from a screen at\n"
                                                "the 9 evenings hommage\n"
                                                "exhibition, berlin 2007.\n"
                                                "a hommage to the 9 evenings,\n"
                                                "new york",
                                                "Nicolas Romanacci",
                                                "atlas/flight.mov"));
    movieList.push_back(atlasMovie("ghosts",
                                                "No description available.",
                                                "Nicolas Romanacci",
                                                "atlas/ghostdinner.mov"));
    movieList.push_back(atlasMovie("grasp",
                                                "The \"Komuso\", a priest and\n"
                                                "Shakuchachi player, played this\n"
                                                "piece for a pregnant woman as\n"
                                                "a kind of prayer for a easy\n"
                                                "delivery. the grainy-ness of\n"
                                                "image reminds of sonar foto\n"
                                                "of embryos ...\n\n"
                                                "yet it remains unclear, which\n"
                                                "scene has been recorded ...\n"
                                                "music: \"San-an\".",
                                                "Nicolas Romanacci",
                                                "atlas/grasp.mov"));
    movieList.push_back(atlasMovie("gumsmile prelude",
                                                "study about experiencing the\n"
                                                "sadness of one being diconnected\n"
                                                "from being aware of her own beauty,\n"
                                                "though trying to play with it.\n"
                                                "watching such a kind of \n"
                                                "unconscious/conscious acting bears\n"
                                                "a specific melancholic experience\n"
                                                "of beauty. as this state bears\n"
                                                "some parallels (in another context)\n"
                                                "to thinking about the relation\n"
                                                "(or not) between mind, nature\n"
                                                "and acting, the music has been chosen.\n"
                                                "music: excerpts john cage,\n"
                                                "prelude for meditation",
                                                "Nicolas Romanacci",
                                                "atlas/gumsmile.mov"));
    movieList.push_back(atlasMovie("kengaku",
                                                "Once on a train ride to Rome.\n"
                                                "watching a dance of two samurai\n"
                                                "ghosts. \"kengaku\" in japanese\n"
                                                "means \"learning through observation\"",
                                                "Nicolas Romanacci",
                                                "atlas/kengaku.mov"));
    movieList.push_back(atlasMovie("kreuzweg",
                                                "based on the experience of\n"
                                                "remembering that as a child I used\n"
                                                "to connect the movement of the\n"
                                                "wipers with passing object\n"
                                                "(guess I am still doing this).\n\n"
                                                "recorded on the way to the Goettweig\n"
                                                "monastery, austria.\n"
                                                "strange combination passing these\n"
                                                "crossway stations on our way to the\n"
                                                "Media Art course ...\n",
                                                "Nicolas Romanacci",
                                                "atlas/kreuzweg.mov"));
    movieList.push_back(atlasMovie("lamp",
                                                "storm lamp. a light surrounded by\n"
                                                "darkness and storm, moving unsteady\n"
                                                "and insecure. a visual metaphor for\n"
                                                "the darknesses and fears of childhood,\n"
                                                "always accompained by the hope for\n"
                                                "security.",
                                   "Nicolas Romanacci",
                                   "atlas/lamp.mov"));
    movieList.push_back(atlasMovie("men",
                                                "Men. The eternal circle of praying \n"
                                                "and discussing. A disturbing and raw\n"
                                                "collage of colors, interfused sound\n"
                                                "layers of voices and noise.\n"
                                                "An alienated documentary video loop\n"
                                                "(berlin 2008), ambiguously, scetchy\n"
                                                "and elaborated alike. A mantra-like\n"
                                                "pieceof minimal art. A metaphor of \n"
                                                "the inseparability of nature and\n"
                                                "culture and the circularity of human\n"
                                                "behaviour. Worldwide.\n"
                                                "In past, presence and future.",
                                   "Nicolas Romanacci",
                                   "atlas/men.mov"));
    movieList.push_back(atlasMovie("nataraja",
                                                "\"because You love the burning-ground,\n"
                                                "i have made a burning-ground of my\n"
                                                "heart -- that You, Dark One, hunter\n"
                                                "of the burning-ground, may dance your\n"
                                                "eternal dance of creation and\n"
                                                "destruction.\" (bengali hymn)\n",
                                   "Nicolas Romanacci",
                                   "atlas/nataraja.mov"));
    movieList.push_back(atlasMovie("pitch",
                                   "No description available.",
                                   "Nicolas Romanacci",
                                   "atlas/pitch.mov"));
    movieList.push_back(atlasMovie("rift",
                                                "somewhere. during a lecture on\n"
                                                "experimental video.\n"
                                                "one of my first pieces.\n"
                                                "seminal moments",
                                   "Nicolas Romanacci",
                                   "atlas/rift.mov"));
    movieList.push_back(atlasMovie("scan",
                                                "selfportrait. recorded at the\n"
                                                "ars electronica center, linz.\n"
                                                "an unsettling visualization of\n"
                                                "experiencing the possibilities\n"
                                                "of being \"scanned\".\n"
                                                "let it be in terms of governmental\n"
                                                "observation, or evoking the fear\n"
                                                "of medical examination, or just\n"
                                                "in a diffuse subconscious\n"
                                                "psychological sense.\n\n"
                                                "a constant and strange sound\n"
                                                "accompaigns the scenery like a\n"
                                                "recorded and alienated\n"
                                                "heartbeat.\n"
                                                "colaborator: jon cates, chicago",
                                   "Nicolas Romanacci",
                                   "atlas/scan.mov"));
    movieList.push_back(atlasMovie("scope",
                                   "at the 9 evenings exhibition, Berlin",
                                   "Nicolas Romanacci",
                                   "atlas/scope.mov"));
    movieList.push_back(atlasMovie("stage",
                                                "\"The world is now indeed a stage,\n"
                                                "an amphitheatre, a world of worlds,\n"
                                                "a theatre in the round, (...)\" \n\n"
                                                "adrianne wortzel\n"
                                                "(in: Kacunko, Slavko, Closed Circuit.\n"
                                                "Videoinstallationen. Logos 2004).\n\n"
                                                "a study about our sometimes\n"
                                                "ridiculous and alarming search\n"
                                                "for community, and our dependency\n"
                                                "on media.",
                                   "Nicolas Romanacci",
                                   "atlas/stage.mov"));
    movieList.push_back(atlasMovie("systemerror",
                                                "an erroneous navigation system is\n"
                                                "leading the driver in an abstruse\n"
                                                "and murky forest. the driver tries\n"
                                                "to keep track of the insecure path,\n"
                                                "struggling with the untamableness\n"
                                                "of nature, surrounded by uncanny\n"
                                                "sounds and appearances.\n\n"
                                                "another study about nature and men\n"
                                                "- or maybe just about ourselves,\n"
                                                "trying to find our way through\n"
                                                "darkness.",
                                   "Nicolas Romanacci",
                                   "atlas/systemerror.mov"));
    movieList.push_back(atlasMovie("walk",
                                                "recorded at the celeste prize\n"
                                                "exhibition, berlin 2008.\n"
                                                "had a great sense of being in\n"
                                                "an Escher scenario ...\n"
                                                "like the sound loop with whistling",
                                   "Nicolas Romanacci",
                                   "atlas/walk.mov"));
    movieList.push_back(atlasMovie("weight",
                                   "the weight of the world\n"
                                   "- in the flight of a bird",
                                   "Nicolas Romanacci",
                                   "atlas/weight.mov"));
    random_shuffle(movieList.begin(), movieList.end());
    movieListIterator = movieList.begin();
   
    
    amountOfPlayers = sizeof(player) / sizeof(ofVideoPlayer);
    for(int i=0; i < amountOfPlayers; i++) {
        
        // # 1 Play player without an alpha channel
        player[i].setPixelFormat(OF_PIXELS_RGB);
        
        // # 2 Load movie without looping
        player[i].loadMovie(getNextMovieFile().getFilePath());
        player[i].setLoopState(OF_LOOP_NONE);
        
        // # 3 Begin playback
        if(player[i].isLoaded()) player[i].play();
    }
}
//--------------------------------------------------------------
atlasMovie atlasApp::getNextMovieFile() {
    
    // In case we reached the end of the movie list we shuffle the list
    if(movieListIterator == movieList.end()) {
        random_shuffle(movieList.begin(), movieList.end());
        movieListIterator = movieList.begin();
    }
    
    // Return next movie from list
    return *movieListIterator++;
}

//--------------------------------------------------------------
void atlasApp::update(){
    
    for(int i=0; i < amountOfPlayers; i++) {
        if (player[i].isLoaded())
            player[i].update();
    }
}

//--------------------------------------------------------------
void atlasApp::draw(){
        
    // Row #1
    if (player[0].isLoaded()) player[0].draw(offsetX, offsetY, movieWidth, movieHeight);
    if (player[1].isLoaded()) player[1].draw(offsetX2, offsetY, movieWidth, movieHeight);
    if (player[2].isLoaded()) player[2].draw(offsetX3, offsetY, movieWidth, movieHeight);

    
    // Row #2
    if (player[3].isLoaded()) player[3].draw(offsetX, offsetY2, movieWidth, movieHeight);
    if (player[4].isLoaded()) player[4].draw(offsetX2, offsetY2, movieWidth, movieHeight);
    if (player[5].isLoaded()) player[5].draw(offsetX3, offsetY2, movieWidth, movieHeight);

    
    // Row #3
    if (player[6].isLoaded()) player[6].draw(offsetX, offsetY3, movieWidth, movieHeight);
    if (player[7].isLoaded()) player[7].draw(offsetX2, offsetY3, movieWidth, movieHeight);
    if (player[8].isLoaded()) player[8].draw(offsetX3, offsetY3, movieWidth, movieHeight);
    
    // Load next player as soon as playback ended
    for(int i=0; i < amountOfPlayers; i++) {
        if (player[i].getIsMovieDone())
            player[i].loadMovie(getNextMovieFile().getFilePath());
    }
    
    // draw description
    if(movieNamePosX > 0 && movieNamePosY > 0) {
        ofSetHexColor(0xFFFFFF);
        ofDrawBitmapStringHighlight(movieName, movieNamePosX, movieNamePosY, ofColor::black, ofColor::white);
        
        ofSetHexColor(0xFFFFFF);
        ofDrawBitmapStringHighlight(movieDescription, movieNamePosX, movieNamePosY+18, ofColor::black, ofColor::white);
    }    
}

//--------------------------------------------------------------
void atlasApp::keyPressed(int key){
    
    // Pause player by number keys
    if(key >= '1' && key <= '9') {
        int p = key - '1';
        if(player[p].isLoaded()) player[p].setPaused(!player[p].isPaused());
    }    
    
	switch(key){
        case ' ':
            // Pause all players
            pauseAll = !pauseAll;
            for(int i=0; i < amountOfPlayers; i++) {
                if (player[i].isLoaded()) {
                    player[i].setPaused(pauseAll);
                }
            }
            break;
	}
}

//--------------------------------------------------------------
void atlasApp::keyReleased(int key){

}

//--------------------------------------------------------------
void atlasApp::mouseMoved(int x, int y){

    // Reset
    movieName = "";
    movieDescription = "";
    movieNamePosX = -1;
    movieNamePosY = -1;
    
    int p = mapPosToPlayer(x, y);
    if(p == -1 || !player[p].isLoaded()) return;
    
    string path = player[p].getMoviePath();
    vector<atlasMovie>::iterator it;
    for(it = movieList.begin(); it != movieList.end();it++) {
        if(it->getFilePath() == path) {
            movieName = it->getName();
            movieDescription = it->getDescription() + "\n\nby " + it->getAuthor();
            
            if(p == 0) {
                movieNamePosX = offsetX + 10;
                movieNamePosY = offsetY + 10;
            } else if(p == 1) {
                movieNamePosX = offsetX2 + 10;
                movieNamePosY = offsetY + 10;                
            } else if(p == 2) {
                movieNamePosX = offsetX3 + 10;
                movieNamePosY = offsetY + 10;
            } else if(p == 3) {
                movieNamePosX = offsetX + 10;
                movieNamePosY = offsetY2 + 10;
            } else if(p == 4) {
                movieNamePosX = offsetX2 + 10;
                movieNamePosY = offsetY2 + 10;
            } else if(p == 5) {
                movieNamePosX = offsetX3 + 10;
                movieNamePosY = offsetY2 + 10;
            } else if(p == 6) {
                movieNamePosX = offsetX + 10;
                movieNamePosY = offsetY3 + 10;
            } else if(p == 7) {
                movieNamePosX = offsetX2 + 10;
                movieNamePosY = offsetY3 + 10;
            } else if(p == 8) {
                movieNamePosX = offsetX3 + 10;
                movieNamePosY = offsetY3 + 10;
            }
            break;
        }
    }
}

//--------------------------------------------------------------
void atlasApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void atlasApp::mousePressed(int x, int y, int button){
    
    if(button == GLUT_LEFT_BUTTON) {
        int p = mapPosToPlayer(x, y);
        if(p == -1) return;
    
        // Pause / Unpause player at given position
        if(player[p].isLoaded()) player[p].setPaused(!player[p].isPaused());
    } else if(button == GLUT_RIGHT_BUTTON) {
            
        int p = mapPosToPlayer(x, y);
        if(p == -1) return;
            
        // Load next movie
        atlasMovie movie = getNextMovieFile();
        player[p].loadMovie(movie.getFilePath());
        
        // Update description
        movieName = movie.getName();
        movieDescription = movie.getDescription() + "\n\nby " + movie.getAuthor();
    }
}


//--------------------------------------------------------------
void atlasApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void atlasApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void atlasApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void atlasApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
int atlasApp::mapPosToPlayer(int x, int y){
    if(x >= offsetX && y >= offsetY && x <= offsetX+movieWidth && y <= offsetY+movieHeight) {
        return 0;
    } else if(x >= offsetX2 && y >= offsetY && x <= offsetX2+movieWidth && y <= offsetY+movieHeight) {
        return 1;
    } else if(x >= offsetX3 && y >= offsetY && x <= offsetX3+movieWidth && y <= offsetY+movieHeight) {
        return 2;
    } else if(x >= offsetX && y >= offsetY2 && x <= offsetX+movieWidth && y <= offsetY2+movieHeight) {
        return 3;
    } else if(x >= offsetX2 && y >= offsetY2 && x <= offsetX2+movieWidth && y <= offsetY2+movieHeight) {
        return 4;
    } else if(x >= offsetX3 && y >= offsetY2 && x <= offsetX3+movieWidth && y <= offsetY2+movieHeight) {
        return 5;
    } else if(x >= offsetX && y >= offsetY3 && x <= offsetX+movieWidth && y <= offsetY3+movieHeight) {
        return 6;
    } else if(x >= offsetX2 && y >= offsetY3 && x <= offsetX2+movieWidth && y <= offsetY3+movieHeight) {
        return 7;
    } else if(x >= offsetX3 && y >= offsetY3 && x <= offsetX3+movieWidth && y <= offsetY3+movieHeight) {
        return 8;
    }
    return -1;
}
