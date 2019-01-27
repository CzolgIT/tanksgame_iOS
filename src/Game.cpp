#include "Main.h"

const char* Game::deviceName = nullptr;
DeviceType Game::deviceType;
bool Game::debugMode = false;

Game::Game()
{
    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );
    TTF_Init();
    
    Window::initialize();
    Texture::loadTextures();
    
    this->running = true;
    this->currentScene = new FirstLaunch();
}

Game::~Game()
{
    delete currentScene;
    Texture::freeTextures();
    Window::quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::update()
{
    while (currentScene->running)
    {
        currentScene->update();
        Window::calculateFPS();
    }
    
    int flag = currentScene->flagReturn;
    delete currentScene;
    switch( flag )
    {
        case 0: // Main Menu
            currentScene = new Menu(MT_MAINMENU);
            break;
        case 1: // Play on Sigma
            //currentScene = new Room( SIGMAIP );
            break;
        case 2: // Play on LAN
            //currentScene = new Room( LOCALIP );
            break;
        case 3: // Settings
            //currentScene = new Settings();
            break;
        case 4: // Settings - Graphics
            //currentScene = new SettingsVideo();
            break;
        case 5:
            //currentScene = new MainMenu();
            break;
        case 7: // Settings - Game
            //currentScene = new SettingsGame();
            break;
        case 8: // Multiplayer run
            //currentScene = new MpManager();
            break;
        default:
            running = false;
            break;
    }
}
