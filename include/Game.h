#pragma once
#include "Main.h"

enum DeviceType
{
    DT_BIG_KEYBOARD = 0,
        // duże menu
        // rysowany znacznik na przyciskach
        // jest opcja użycia myszki lub touchscreena
    DT_BIG_TOUCH = 1,
        // duże menu
        // bez znaczników na przycisku
        // do użytku tylko touchscreen i klawiatura ekranowa do wpisywania tekstu
    DT_SMALL_KEYBOARD = 2,
        // małe menu
        // rysowany znacznik na przyciskach
        // jest opcja użycia myszki lub touchscreena
    DT_SMALL_TOUCH = 3
        // małe menu
        // bez znaczników na przycisku
        // do użytku tylko touchscreen i klawiatura ekranowa do wpisywania tekstu
};

class Game
{
public:
    
    Game();
    ~Game();
    
    void update();
    bool running;
    
    static DeviceType deviceType;
    static const char* deviceName;
    static bool debugMode;
    
private:
    
    _Scene * currentScene;
    
};
