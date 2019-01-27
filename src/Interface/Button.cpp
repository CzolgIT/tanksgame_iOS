#include "Main.h"

Button::Button( std::string name , int width , int height )
{
    this->width = width;
    this->height = height;
    this->name = name;
    this->title[0] = new Title( name , height/2 );
    this->title[1] = new Title( "+ "+name+" +" , height/2 );
    this->active = false;
}

Button::~Button()
{
    delete title[0];
    delete title[1];
}

void Button::draw( int x , int y )
{
    if (active)
    {
        Texture::button[1]->drawResized(x, y, width, height);
        this->title[1]->draw(x, y);
    }
    else
    {
        Texture::button[0]->drawResized(x, y, width, height);
        this->title[0]->draw(x, y);
    }
}

void Button::reload( std::string name , int width , int height )
{
    this->name = name;
    delete title[0];
    delete title[1];
    
    this->title[0] = new Title( name , height/2 );
    this->title[1] = new Title( "* "+name+" *" , height/2 );
}

void Button::setActive(bool active)
{
    this->active = active;
}

bool Button::isActive()
{
    return active;
}
