
#include "include/Application.h"
#include "include/Starter.h"

using namespace std;

void test_scen2() {
    Application * app = Application::getInstance();
    app->loadData();



    DeliveryMan tmp = app->getDeliveryMan()->at(0);

    cout << "[" << tmp.getMaxWeight() << "]      " << "[" << tmp.getMaxVolume() << "]" << endl;

    app->bestfitBT(*tmp.getShipping(), *app->getPackages());
}

int main() {

    /* Application * app = Application::getInstance();
    app->loadData();

    // APP STARTER NORMAL
    Starter starter = Starter();
    starter.start();*/

    test_scen2();

    return 0;
}
