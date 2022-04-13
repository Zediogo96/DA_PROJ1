//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_STARTER_H
#define PROJETO1_STARTER_H


#include <stack>

#include "Application.h"
#include "Menu.h"

using namespace std;

class Starter {

private:

    Application * application;
    stack<Menu*> menuStack;

public:

    Starter();

    void start();

};


#endif //PROJETO1_STARTER_H
