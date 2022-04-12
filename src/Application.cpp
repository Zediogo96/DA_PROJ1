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

void Application::sorterDeliveryMans(bool ascending) {

    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
            if (a.getMaxWeight() != b.getMaxWeight()) return a.getMaxWeight() > b.getMaxWeight();
            return a.getMaxVolume() > b.getMaxVolume();
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
        if (a.getMaxWeight() != b.getMaxWeight()) return a.getMaxWeight() < b.getMaxWeight();
        return a.getMaxVolume() < b.getMaxVolume();
    });
}

void Application::sorterPackages(bool ascending) {

    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](Package a, Package b) {
            if (a.getWeight() != b.getWeight()) return a.getWeight() > b.getWeight();
            return a.getVolume() > b.getVolume();
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](Package a, Package b) {
        if (a.getWeight() != b.getWeight()) return a.getWeight() < b.getWeight();
        return a.getVolume() < b.getVolume();
    });
}
