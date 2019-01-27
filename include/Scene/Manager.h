#pragma once
#include "Main.h"

class Manager : public _Scene
{
public:
    
    Manager();
    ~Manager() override;
    
    // every step
    void draw() override;

private:
    
    Title* info;
    
};
