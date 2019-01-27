#pragma once
#include "Main.h"

class FirstLaunch : public _Scene
{
public:
    
    FirstLaunch();
    ~FirstLaunch() override;
    
    // every step
    void everyStep() override;
    void draw() override;
    
    // on action
    void keyboardEvent() override;
    void touchEvent() override;
    void textEvent() override;
    
private:
    
    Title* text[2];
    Button* confirm;
    std::string input;
    int animationStep;
    float timeCounter;
    
};
