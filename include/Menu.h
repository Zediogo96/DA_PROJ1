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
    explicit Menu(Application * application);

    virtual ~Menu();

    /** Virtual function for display **/
    virtual void display() = 0;

    virtual Menu* getNextMenu();

    virtual void setNextMenu(Menu* new_menu) = 0;
};


class MainMenu: public Menu {
public:

    explicit MainMenu(Application * application);
    void display() override;
    void setNextMenu(Menu* new_menu) override;
};

class Scenery3_Menu: public Menu {
public:

    explicit Scenery3_Menu(Application *application);
    void display() override;

    static int Scenery3(const vector<Package>& packages);
    void setNextMenu(Menu* new_menu) override;
};



#endif //PROJETO1_MENU_H
