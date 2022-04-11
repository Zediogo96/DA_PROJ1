//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Starter.h"

Starter::Starter() {
    application = Application::getInstance();
    menuStack.push(new MainMenu(application));
}

void Starter::start() {

    application->loadData();

    while (!menuStack.empty()) {
        menuStack.top()->display();

        if (menuStack.top()->getNextMenu() != nullptr) {
            Menu * tmp = menuStack.top()->getNextMenu();
            menuStack.top()->setNextMenu(nullptr);
            menuStack.push(tmp);
        }
        else {
            delete menuStack.top();
            menuStack.pop();
        }
    }
}
