#pragma once
#include "Main.h"

class Window
{
public:
    
    static void initialize();
    static void reload();
    static void quit();
    
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    
    static int width;
    static int height;
    
    static int fps;
    static double stepTime;
    
    static void calculateFPS();
    
private:
    
    static double time;
    static double timeCounter;
    static int fpsCounter;
    Window();
    ~Window();
    
};

