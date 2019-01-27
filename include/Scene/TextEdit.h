#pragma once
#include "Main.h"

class TextEdit : public _Scene
{
public:
    
    TextEdit();
    
    // every step
    void draw() override;
    
private:
    
    Title* info;
    
};

