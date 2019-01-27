#include "Main.h"

Menu::Menu( MenuType menutype ) : _Scene()
{
    if (Game::deviceType == DT_BIG_KEYBOARD || Game::deviceType == DT_BIG_TOUCH)
    {
        unitWidth = 14;
        unitHeight = 15;
    }
    else
    {
        unitWidth = 15;
        unitHeight = 10;
    }
    if (Game::deviceType == DT_BIG_KEYBOARD || Game::deviceType == DT_SMALL_KEYBOARD )
        selectedButton = 0;
    else
        selectedButton = -1;
    
    title = nullptr;
    button[0] = nullptr;
    button[1] = nullptr;
    button[2] = nullptr;
    button[3] = nullptr;
    
    switch (menutype)
    {
        case MT_MAINMENU:
            titleText = "TanksGame";
            buttonText[0] = "sigma";
            buttonText[1] = "lan";
            buttonText[2] = "settings";
            buttonText[3] = "exit";
            break;
            
        default:
            titleText = "ERROR";
            buttonText[0] = "this";
            buttonText[1] = "menutype";
            buttonText[2] = "is not";
            buttonText[3] = "defined";
            break;
    }
    reload();
}

Menu::~Menu()
{
    delete title;
    delete button[0];
    delete button[1];
    delete button[2];
    delete button[3];
}

void Menu::draw()
{
    SDL_SetRenderDrawColor( Window::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Window::renderer );
    
    if (Game::debugMode)
    {
        SDL_SetRenderDrawColor( Window::renderer, 0, 0, 0, 0);
        for(int a=0; a<unitWidth; a++)
            for(int b=0; b<unitHeight; b++)
            {
                SDL_Rect kw = { unitX0+unitDesign*a , unitY0+unitDesign*b , unitDesign , unitDesign };
                SDL_RenderDrawRect( Window::renderer , &kw );
            }
    }
    
    button[0]->draw( buttonX[0] , buttonY[0] );
    button[1]->draw( buttonX[1] , buttonY[1] );
    button[2]->draw( buttonX[2] , buttonY[2] );
    button[3]->draw( buttonX[3] , buttonY[3] );

    title->draw(Window::width/2,unitY0+2.5 * unitDesign);
    
    SDL_RenderPresent( Window::renderer );
}

void Menu::keyboardEvent()
{
    
}

void Menu::touchEvent()
{
    int touchX = int(event.tfinger.x * double(Window::width));
    int touchY = int(event.tfinger.y * double(Window::height));
    
    if (event.type == SDL_FINGERDOWN)
    {
        for(int i=0;i<4;i++)
        {
            button[i]->setActive(false);
            if (touchX >= buttonX[i]-2*unitButton && touchX <= buttonX[i]+2*unitButton
                && touchY >= buttonY[i]-0.5*unitButton && touchY <= buttonY[i]+0.5*unitButton)
            {
                printf("kliknales nr: %d\n",i);
                button[i]->setActive(true);
            }
            
        }
    }
    if (event.type == SDL_FINGERUP)
    {
        for(int i=0;i<4;i++)
        {
            button[i]->setActive(false);
        }
    }
    
}

void Menu::reload()
{
    unitDesign = Window::height / unitHeight;
    if (unitDesign*unitWidth > Window::width) unitDesign = Window::width / unitWidth;
    unitX0 = (Window::width - unitDesign*unitWidth)/2;
    unitY0 = (Window::height - unitDesign*unitHeight)/2;
    
    if (Game::deviceType == DT_BIG_KEYBOARD || Game::deviceType == DT_BIG_TOUCH)
    {
        unitButton = unitDesign*unitHeight / 9;
        buttonX[0] = unitX0+unitDesign*7; buttonY[0] = unitY0+unitDesign*6;
        buttonX[1] = unitX0+unitDesign*7; buttonY[1] = unitY0+unitDesign*8;
        buttonX[2] = unitX0+unitDesign*7; buttonY[2] = unitY0+unitDesign*10;
        buttonX[3] = unitX0+unitDesign*7; buttonY[3] = unitY0+unitDesign*12;
    }
    else
    {
        unitButton = unitDesign*unitHeight / 6;
        buttonX[0] = unitX0+unitDesign*11; buttonY[0] = unitY0+unitDesign*6;
        buttonX[1] = unitX0+unitDesign*11; buttonY[1] = unitY0+unitDesign*8;
        buttonX[2] = unitX0+unitDesign*4; buttonY[2] = unitY0+unitDesign*6;
        buttonX[3] = unitX0+unitDesign*4; buttonY[3] = unitY0+unitDesign*8;
    }
    
    if (title == nullptr)
        title = new Title( titleText , this->unitButton*1.4 );
    else
    {
        delete title;
        title = new Title( titleText , this->unitButton*1.4 );
    }
    for(int i=0; i<4; i++)
        {
        if (button[i] == nullptr)
            button[i] = new Button(buttonText[i],4*this->unitButton,this->unitButton);
        else
        {
            delete button[i];
            button[i] = new Button(buttonText[i],4*this->unitButton,this->unitButton);
        }
    }
}


