//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Menu.h"


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


Menu::Menu(Application * application) {};

Menu::~Menu() = default;

Menu* Menu::getNextMenu() { return this->next_menu; }

void Menu::setNextMenu(Menu* new_menu) {
    this->next_menu = new_menu;
}

MainMenu::MainMenu(Application * application) : Menu(application) { }

void MainMenu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             MAIN MENU             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|   Select your desired route:      |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Scenery 1                   |" << endl;
    cout << "|   [2] Scenery 2                   |" << endl;
    cout << "|   [3] Scenery 3                   |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1':
            setNextMenu(new Scenery1_Menu(application));
            break;
        case '2':
            setNextMenu(new Scenery2_Menu(application));
            break;
        case '3':
            setNextMenu(new Scenery3_Menu(application));
            break;
        case '0':
            setNextMenu(nullptr);
            break;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

Scenery1_Menu::Scenery1_Menu(Application *application) : Menu(application) {}

void Scenery1_Menu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 1             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Exec                        |" << endl;
    cout << "|   [2] Print                       |" << endl;
    cout << "|   [3]                             |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1': {
            Application::getInstance()->scenery1();
            sleep(4);
            break;
        }
        case '2':
            Application::getInstance()->printDeliveryMan();
            sleep(4);
            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

Scenery2_Menu::Scenery2_Menu(Application *application) : Menu(application) {}

void Scenery2_Menu::display() {
    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 2             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Exec                        |" << endl;
    cout << "|   [2] Print                       |" << endl;
    cout << "|   [3]                             |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1': {
            Application::getInstance()->scenery2();
            sleep(4);
            break;
        }
        case '2':
            Application::getInstance()->printDeliveryMan();
            sleep(4);
            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }

}

Scenery3_Menu::Scenery3_Menu(Application *application) : Menu(application) { }

void Scenery3_Menu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 3             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Exec                        |" << endl;
    cout << "|   [2] Print                       |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1':
            Application::getInstance()->scenery3();
            sleep(4);
            break;
        case '2':
            Application::getInstance()->printDeliveryMan();
            sleep(4);
            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}


