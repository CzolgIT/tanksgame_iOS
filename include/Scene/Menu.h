#pragma once
#include "Main.h"

enum MenuType
{
    MT_MAINMENU = 0,
    MT_SETTINGS = 1,
    MT_VIDEO = 2
};

class Menu : public _Scene
{
public:
    
    Menu( MenuType menutype );
    ~Menu() override;

    // every step
    void draw() override;
    
    // on action
    void keyboardEvent() override;
    void touchEvent() override;
    void reload() override;
    //void exitScene() override;
    
private:

    std::string titleText;
    Title* title;
    
    std::string buttonText[4];
    Button* button[4];
    int buttonX[4];
    int buttonY[4];
    int selectedButton;
    
    int unitButton;
    int unitDesign;
    int unitWidth;
    int unitHeight;
    int unitX0;
    int unitY0;

};
