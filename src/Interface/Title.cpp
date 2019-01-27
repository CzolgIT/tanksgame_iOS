#include "Main.h"

Title::Title( std::string text , int size )
{
    this->shadow = int(sqrt(double(size))/1.5);
    TTF_Font* font = TTF_OpenFont( "font.ttf" , size );
    
    const SDL_Color white = {255,255,255};
    const SDL_Color black = {0,0,0};
    
    SDL_Surface* whiteSurface = TTF_RenderText_Solid( font, text.c_str() , white );
    SDL_Surface* blackSurface = TTF_RenderText_Solid( font, text.c_str() , black );
    
    TTF_CloseFont( font );
    font = nullptr;
    
    this->sdlTexture = SDL_CreateTexture(Window::renderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_TARGET, whiteSurface->w + shadow, whiteSurface->h + shadow);
    SDL_SetRenderDrawColor( Window::renderer, 0, 0, 0, 0 );
    SDL_SetRenderTarget( Window::renderer , this->sdlTexture );
    SDL_RenderClear(Window::renderer);
    SDL_Texture* whiteTexture;
    SDL_Texture* blackTexture;
    whiteTexture = SDL_CreateTextureFromSurface( Window::renderer , whiteSurface );
    blackTexture = SDL_CreateTextureFromSurface( Window::renderer , blackSurface );
    
    SDL_Rect whiteRect = {0,0,whiteSurface->w,whiteSurface->h};
    SDL_Rect blackRect = {shadow,shadow,blackSurface->w,blackSurface->h};
    SDL_RenderCopy( Window::renderer , blackTexture , NULL , &blackRect );
    SDL_RenderCopy( Window::renderer , whiteTexture , NULL , &whiteRect );
    SDL_SetRenderTarget( Window::renderer , NULL );
    //SDL_SetRenderDrawColor( Window::renderer, 215, 226, 175, 0 );
    
    this->width = whiteSurface->w + shadow;
    this->height = whiteSurface->h + shadow;
    
    SDL_FreeSurface( whiteSurface );
    SDL_FreeSurface( blackSurface );
    SDL_DestroyTexture( whiteTexture );
    SDL_DestroyTexture( blackTexture );
    
    SDL_SetTextureBlendMode( sdlTexture , SDL_BLENDMODE_BLEND );
}

Title::~Title()
{
    SDL_DestroyTexture( sdlTexture );
}

void Title::draw( int x , int y)
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-width/2,y-height/2,width,height};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Title::drawResized( int x , int y , int w , int h )
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-w/2,y-h/2,w,h};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Title::drawScaled( int x , int y , double s )
{
    SDL_Rect sourceRect = {0,0,width,height};
    SDL_Rect destinationRect = {x-(double(width)*s)/2.0,y-(double(height)*s)/2.0,double(width)*s,double(height)*s};
    SDL_RenderCopy( Window::renderer , this->sdlTexture , &sourceRect , &destinationRect );
}

void Title::setAlpha(float alpha)
{
    if (alpha >=0 && alpha <=1)
    {
        this->alpha = alpha*255;
        SDL_SetTextureAlphaMod( sdlTexture , this->alpha );
    }
}




