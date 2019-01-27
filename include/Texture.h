#pragma once
#include "Main.h"

class Texture
{
public:

    Texture( std::string path );
    ~Texture();

    void draw( int x , int y );
    void drawScaled( int x , int y , double s );
    void drawResized( int x , int y , int w , int h );
    
    static void loadTextures();
    static void freeTextures();
    static Texture* button[2];

private:
    
    SDL_Texture* sdlTexture;
    int width;
    int height;
    
};
