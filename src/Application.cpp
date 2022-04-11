//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Application.h"

Application::Application() = default;

Application* Application::app = nullptr;

void Application::loadData() {
    this->packages = getPackagesFromFiles("../input/package.txt");
    this->deliverymans = getDeliveryManFromFiles("../input/carrinhas.txt");
}

vector<Package> * Application::getPackages() {
    return this->packages;
}

vector<DeliveryMan> * Application::getDeliveryMan() {
    return this->deliverymans;
}

Application *Application::getInstance() {
    if (app == nullptr) app = new Application();

    return app;
}
