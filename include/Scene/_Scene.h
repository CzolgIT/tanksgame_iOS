#pragma once
#include "Main.h"

class _Scene
{
public:
    
    _Scene();
    virtual ~_Scene() {};
    
    // every step
    void update();
    void handleAllEvents();
    virtual void everyStep(){};
    virtual void draw(){};

    // on action
    virtual void keyboardEvent() {};
    virtual void touchEvent() {};
    virtual void textEvent() {};
    virtual void reload() {};
    void exitScene( int flag );
    
    bool running;
    int flagReturn;
    
protected:
    
    SDL_Event event;
    
};
