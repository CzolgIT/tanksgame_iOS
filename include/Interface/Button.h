#ifndef Button_h
#define Button_h

#include "Main.h"

class Button
{
public:
    
    Button( std::string name , int width , int height );
    ~Button();

    void draw( int x , int y );
    void reload( std::string name , int width , int height );

    void setActive(bool active);
    bool isActive();
    
private:
   
    int width,height;
    Title* title[2];
    bool active;
    std::string name;
    
};

#endif
