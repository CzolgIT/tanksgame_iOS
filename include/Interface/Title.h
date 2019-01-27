#pragma once
#include "Main.h"

class Title
{
public:
    
    Title( std::string text , int size );
    ~Title();
    
    void draw( int x , int y );
    void drawScaled( int x , int y , double s );
    void drawResized( int x , int y , int w , int h );
    
    void setAlpha(float alpha);
    
private:
    
    SDL_Texture* sdlTexture;
    int width;
    int height;
    int shadow;
    int alpha;
    
};

