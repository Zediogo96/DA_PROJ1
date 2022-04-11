
#include "include/Application.h"
#include "include/Starter.h"


using namespace std;

int main() {

    Application * app = Application::getInstance();

    app->loadData();

    Starter starter = Starter();
    starter.start();
}
