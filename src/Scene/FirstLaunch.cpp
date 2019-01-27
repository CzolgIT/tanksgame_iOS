#include "Main.h"

FirstLaunch::FirstLaunch()
{
    text[0] = new Title("Welcome to",Window::width/19);
    text[1] = new Title("TanksGame",Window::width/10);
    int unitButton;
    if (Game::deviceType == DT_BIG_KEYBOARD || Game::deviceType == DT_BIG_TOUCH)
        unitButton = int( Window::height / 15 ) * 15 / 9;
    else
        unitButton = int( Window::height / 10 ) * 10 / 6;
    confirm = new Button("confirm",4*unitButton,unitButton);
    this->animationStep = 0;
    this->timeCounter = 0;
}

FirstLaunch::~FirstLaunch()
{
    delete text[0];
    delete text[1];
    delete confirm;
}

void FirstLaunch::everyStep()
{
    this->timeCounter += Window::stepTime;
    
    switch (animationStep)
    {
        case 0: // show welcome
            if (timeCounter > 1)
            {
                animationStep = 1;
                text[0]->setAlpha(1);
                text[1]->setAlpha(1);
            }
            else
            {
                text[0]->setAlpha(timeCounter);
                text[1]->setAlpha(timeCounter);
            }
            break;
            
        case 1: // pause welcome
            if (timeCounter>2)
                animationStep = 2;
            break;
            
        case 2: // hide welcome
            if (timeCounter>3)
            {
                animationStep = 3;
                text[0]->setAlpha(0);
                text[1]->setAlpha(0);
                delete text[0];
                text[0] = new Title("enter your nickname:",Window::width/20);
            }
            else
            {
                text[0]->setAlpha(3-timeCounter);
                text[1]->setAlpha(3-timeCounter);
            }
            break;
            
        case 3: // show nickname textbox
            if (timeCounter>4)
            {
                animationStep = 4;
                text[0]->setAlpha(1);
                text[1]->setAlpha(1);
            }
            else
            {
                text[0]->setAlpha(timeCounter-3);
                text[1]->setAlpha(timeCounter-3);
            }
            break;
            
        case 4: // show keyboard
            SDL_StartTextInput();
            animationStep = 5;
            break;
            
        default:
            break;
    }
}

void FirstLaunch::keyboardEvent()
{
    if (event.key.keysym.sym == SDLK_BACKSPACE)
    {
        input = input.substr(0, input.size()-1);
        if (input.length() > 0)
        {
            delete text[1];
            text[1] = new Title( input , Window::width/13 );
        }
    }
    if (event.key.keysym.sym == SDLK_RETURN)
    {
        if (input.length() > 0)
        {
            SDL_StopTextInput();
            exitScene(0);
        }
    }
}

void FirstLaunch::touchEvent()
{
    int touchX = int(event.tfinger.x * double(Window::width));
    int touchY = int(event.tfinger.y * double(Window::height));
    int unitButton;
    if (Game::deviceType == DT_BIG_KEYBOARD || Game::deviceType == DT_BIG_TOUCH)
        unitButton = int( Window::height / 15 ) * 15 / 9;
    else
        unitButton = int( Window::height / 10 ) * 10 / 6;
    if (event.type == SDL_FINGERDOWN)
    {
        confirm->setActive(false);
        if (touchX >= Window::width/2-2*unitButton && touchX <= Window::width/2+2*unitButton
            && touchY >= Window::height/3*2-0.5*unitButton && touchY <= Window::height/3*2+0.5*unitButton)
        {
            confirm->setActive(true);
        }
        else
        {
            if (SDL_IsTextInputActive())
                SDL_StopTextInput();
            else
                SDL_StartTextInput();
        }
    }
    if (event.type == SDL_FINGERUP)
    {
        if (confirm->isActive())
        {
            confirm->setActive(false);
            SDL_Delay(10); // to show inactive button for a 10ms
            exitScene(0);
        }
    }
}

void FirstLaunch::textEvent()
{
    printf("- %s -",event.text.text);
    if (input.length()<10)
    {
        input = input + event.text.text;
        delete text[1];
        text[1] = new Title( input , Window::width/13 );
    }
}

void FirstLaunch::draw()
{
    SDL_SetRenderDrawColor( Window::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Window::renderer );
    if (animationStep < 3)
    {
        text[0]->draw( Window::width/2 , Window::height/7*3 );
        text[1]->draw( Window::width/2 , Window::height/7*4 );
    }
    else
    {
        text[0]->draw( Window::width/2 , Window::height/6 );
        if (input.length() >0)
            text[1]->draw( Window::width/2 , Window::height/3 );
        if (animationStep>4)
            confirm->draw( Window::width/2 , Window::height/5*3 );
    }
    SDL_RenderPresent( Window::renderer );
}
