#include "Main.h"

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;
int Window::width = 0;
int Window::height = 0;
int Window::fps = 0;
double Window::stepTime = 0;
double Window::time = 0;
double Window::timeCounter = 0;
int Window::fpsCounter = 0;

void Window::initialize()
{
    // creating window and renderer
    Uint32 windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI ;
    Window::window = SDL_CreateWindow( "TanksGame" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , 800 , 400 , windowFlags );
    Window::renderer = SDL_CreateRenderer( Window::window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    // getting resolution
    SDL_GL_GetDrawableSize( Window::window , &Window::width , &Window::height );
    printf("started with resolution: %d x %d\n",Window::width,Window::height);
    
    // getting information about device
    Game::deviceName = SDL_GetPlatform();
    if ( strcmp( Game::deviceName , "iOS" ) == 0 || strcmp( Game::deviceName , "Android" ) == 0 )
    {
        if (SDL_IsTablet())
            Game::deviceType = DT_BIG_TOUCH;
        else
            Game::deviceType = DT_SMALL_TOUCH;
    }
    else
        Game::deviceType = DT_BIG_KEYBOARD;
    
    Window::time = SDL_GetTicks();
}

void Window::quit()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
}

void Window::reload()
{
    // getting new resolution
    SDL_GL_GetDrawableSize( Window::window , &Window::width , &Window::height );
    printf("changed resolution to: %d x %d\n",Window::width,Window::height);
}

void Window::calculateFPS()
{
    double get = SDL_GetTicks();
    stepTime = (get - time) / 1000.0;
    time = get;
    
    timeCounter += stepTime;
    fpsCounter++;
    
    if (timeCounter >= 1 )
    {
        timeCounter -= 1;
        fps = fpsCounter;
        fpsCounter = 0;
    }

}
