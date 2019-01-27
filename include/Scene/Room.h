#pragma once
#include "Main.h"

class Room : public _Scene
{
public:
    
    Room();
    ~Room() override;
    
    // every step
    void draw() override;
    
private:
    
    Title* info;
    
};
