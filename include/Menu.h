//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_MENU_H
#define PROJETO1_MENU_H


#include "Application.h"

/** Virtual class for all the different Menus **/
class Menu {

protected:

    Application * application = Application::getInstance();
    Menu * next_menu = nullptr;

public:
    explicit Menu();

    virtual ~Menu();

    /** Virtual function for display **/
    virtual void display() = 0;

    virtual Menu* getNextMenu();

    virtual void setNextMenu(Menu* new_menu);
};


class MainMenu: public Menu {
public:
    explicit MainMenu();
    void display() override;
};

class Scenery1_Menu: public Menu {
public:

    explicit Scenery1_Menu();
    void display() override;
};

class Scenery2_Menu: public Menu {
public:

    explicit Scenery2_Menu();
    void display() override;

};


class Scenery3_Menu: public Menu {
public:

    explicit Scenery3_Menu();
    void display() override;
};

#endif //PROJETO1_MENU_H
