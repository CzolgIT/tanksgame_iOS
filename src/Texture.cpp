#include "Main.h"

Texture* Texture::button[2] = {nullptr};

Texture::Texture( std::string path )
{
    SDL_Surface* surface = IMG_Load( path.c_str() );
    if (surface == nullptr) printf("Can't load file: %s",path.c_str());
    
    this->sdlTexture = SDL_CreateTextureFromSurface( Window::renderer , surface );
    this->width = surface->w;
    this->height = surface->h;
    
    SDL_FreeSurface( surface );
}

Texture::~Texture()
{
    SDL_DestroyTexture( sdlTexture );
}

void Texture::draw( int x , int y)
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-width/2,y-height/2,width,height};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Texture::drawResized( int x , int y , int w , int h )
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-w/2,y-h/2,w,h};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Texture::drawScaled( int x , int y , double s )
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-(double(width)*s)/2.0,y-(double(height)*s)/2.0,double(width)*s,double(height)*s};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Texture::loadTextures()
{
    Texture::button[0] = new Texture("button.png");
    Texture::button[1] = new Texture("buttonActive.png");
}

void Texture::freeTextures()
{
    delete Texture::button[0];
    delete Texture::button[1];
}
