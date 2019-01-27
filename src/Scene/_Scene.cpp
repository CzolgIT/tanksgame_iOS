#include "Main.h"

_Scene::_Scene()
{
    running = true;
    flagReturn = 0;
}

void _Scene::update()
{
    handleAllEvents();
    everyStep();
    draw();
}

void _Scene::handleAllEvents()
{
    while ( SDL_PollEvent( &event ) != 0 )
    {
        printf("Event: ");
        switch (event.type)
        {
            case SDL_QUIT:
                printf("quit game\n");
                exitScene(-1);
                break;
                
            case SDL_WINDOWEVENT:
                printf("window\n");
                Window::reload();
                reload();
                break;
                
            case SDL_KEYDOWN:
                printf("keyboard - key down\n");
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    exitScene(0);
                }
                else
                    keyboardEvent();
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                printf("mouse - key down\n");
                //mouseEvent();
                break;
                
            case SDL_FINGERUP:
            case SDL_FINGERDOWN:
            case SDL_MOUSEMOTION:
                touchEvent();
                printf("touchscreen - finger down / up / motion\n");
                break;
                
            case SDL_MOUSEBUTTONUP:
                printf("mouse - key up\n");
                break;
                
            case SDL_FINGERMOTION:
                printf("touchscreen - moved\n");
                break;
                
            case SDL_TEXTINPUT:
                printf("text entered\n");
                textEvent();
                break;
                
            default:
                printf("other action\n");
                break;
        }
    }
}

void _Scene::exitScene(int flag)
{
    running = false;
    flagReturn = flag;
}
