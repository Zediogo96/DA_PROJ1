//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Menu.h"

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
            std::cout << "test2 \n";
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
        case '1':
            application->sorterDeliveryMans(true);
            application->sorterPackages(true);
            cout << Scenery1(* application->getPackages(), *application->getDeliveryMan()) << endl;
            break;
        case '2':
            std::cout << "test2 \n";
            break;
        case '3':

            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

int Scenery1_Menu::Scenery1(const vector<Package> &vecPack, const vector<DeliveryMan> &vecDel) {

    size_t m = vecPack.size();

    vector<Package> auxVecPack;
    vector<DeliveryMan> auxVecDel;

    auxVecPack.reserve(vecPack.size());
    auxVecDel.reserve(vecDel.size());

    for (Package tmp : vecPack) {
        tmp.setUsed(false);
        auxVecPack.emplace_back(tmp);
    }

    for (const auto& tmp : vecDel) {
        auxVecDel.emplace_back(tmp);
    }

    int numberStaff = 0;


    for (int i = 0; i < auxVecDel.size(); i++) {

        unsigned remainingW = auxVecDel[i].getMaxWeight();
        unsigned remainingV = auxVecDel[i].getMaxVolume();

        for (auto & j : auxVecPack) {
            if (!j.getUsed()) {
                if (j.getWeight() > remainingW || j.getVolume() > remainingV) {
                    numberStaff++;
                    break;
                }
                else {
                    remainingW -= j.getWeight();
                    remainingV -= j.getVolume();

                    cout << "[" << i << "]" << "RemW: " << remainingW << "; RemV: " << remainingV << endl;
                    j.setUsed(true);
                }
            }
        }
    }

    int cnt = 0;
    for (const auto& tmp : auxVecPack) {
        if (!tmp.getUsed()) cnt++;
    }

    cout << "cnt remaining packages: " << cnt << endl;

    return numberStaff;
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
    cout << "|   [3]                             |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1':
            cout << Scenery3(* application->getPackages()) << endl;
            break;
        case '2':
            std::cout << "test2 \n";
            break;
        case '3':

            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

int Scenery3_Menu::Scenery3(const vector<Package>& packages) {

    vector<Package> auxVec;
    vector<Package> expressPackages;
    unsigned totalWeight = 0;

    auxVec.reserve(packages.size());

    for (const Package& pack : packages) {
        auxVec.emplace_back(pack);
    }

    sort(auxVec.begin(), auxVec.end(), [](Package & a,Package & b) {
        return a.getDuration() < b.getDuration();
    });

    unsigned timeLeft = 8 * 3600;

    for (const Package& aPackage : auxVec) {
        if (aPackage.getDuration() <= timeLeft) {
            expressPackages.push_back(aPackage);
            timeLeft -= aPackage.getDuration();
            totalWeight += aPackage.getWeight();
        }
        else break;
    }

    return (int)(((8 * 3600) - timeLeft) / expressPackages.size());
}


