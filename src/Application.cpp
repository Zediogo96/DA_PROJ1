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
        sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
            if (a.getWeight() != b.getWeight()) return a.getWeight() > b.getWeight();
            return a.getVolume() > b.getVolume();
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
        if (a.getWeight() != b.getWeight()) return a.getWeight() < b.getWeight();
        return a.getVolume() < b.getVolume();
    });
}

void Application::testSortPackages(bool ascending) {
    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
            return a.average() > b.average();
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
        return a.average() < b.average();
    });
}

int Application::scenery1() {

    /*vector<Package> auxVecPack;
    vector<DeliveryMan> auxVecDel;

    auxVecPack.reserve(packages->size());
    auxVecDel.reserve(deliverymans->size());*/

    for (auto pck : *packages) pck.setUsed(false);

    int countStaff = 0, countPack = 0;

    /** First loop should be always to iterate through all men? **/
    for (auto & deliveryman : *deliverymans) {

        deliveryman.getShipping()->clearShipping();
    }

    return 0;
}


vector<Package> Application::bestfitBT(Shipping & shipping, vector<Package> & packages_) {

    cout << "Weight: " << shipping.getCurrentWeight() << "Volume" << shipping.getCurrentVol() << endl;

    /** STOP CONDITION **/
    if (shipping.isFull()) return shipping.getPackages();

    vector<Package> res = shipping.getPackages();

    for (int i = 0; i < packages_.size(); i++) {

        if (!packages_[i].getUsed() && shipping.fits(packages_[i])) {
            cout << packages_[i].getUsed() << " " << packages_[i].getWeight() << " " <<  packages_[i].getVolume() << endl;

            shipping.pushPackage(packages_[i]);
            packages_[i].setUsed(true);


            vector<Package> aux = bestfitBT(shipping, packages_);


            if (aux.size() > res.size()) {
                res = aux;
                if (res.size() == packages_.size()) return res;
            }

            else {
                shipping.removePackage(packages_[i]);
                packages_[i].setUsed(false);
            }


        }
    }
    return res;
}

int Application::scenery3() {

    vector<Package> auxVec;
    vector<Package> expressPackages;
    unsigned totalWeight = 0;

    auxVec.reserve(packages->size());

    for (const Package& pack : *packages) {
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


