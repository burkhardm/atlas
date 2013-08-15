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

#include "ofMain.h"
#include "atlasApp.h"
#include "ofAppGlutWindow.h"

int main( ){
    
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1280, 1024, OF_FULLSCREEN);
	ofSetDataPathRoot("../Resources/");
    ofRunApp( new atlasApp());

}
