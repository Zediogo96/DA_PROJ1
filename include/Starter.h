//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_STARTER_H
#define PROJETO1_STARTER_H


#include <stack>

#include "Application.h"
#include "Menu.h"

using namespace std;

/**
 * @brief Class that facilitates the start of our program
 */
class Starter {

private:

    Application * application;
    stack<Menu*> menuStack;

public:

    /**
     * @brief Default constructor that pushed the Main Menu to the stack
     * 
     */
    Starter();

    /**
     * @brief Starts the application loop, loads all the data from the files to application before
     * 
     */
    void start();

};


#endif //PROJETO1_STARTER_H
