//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Application.h"

#include <cmath>

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

size_t Application::getDeliveryManSize() {
    return this->deliverymans->size();
}

size_t Application::getPackagesSize() {
    return this->packages->size();
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
            double weight1 = sqrt(pow(a.getVolume(), 2) + pow(a.getWeight(), 2));
            double weight2 = sqrt(pow(b.getVolume(), 2) + pow(b.getWeight(), 2));
            return weight1 > weight2;
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
        double weight1 = sqrt(pow(a.getVolume(), 2) + pow(a.getWeight(), 2));
        double weight2 = sqrt(pow(b.getVolume(), 2) + pow(b.getWeight(), 2));
        return weight1 < weight2;
    });
}

void Application::testSortDeliveryman(bool ascending) {
    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
            return a.average() > b.average();
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
        return a.average() < b.average();
    });
}

void Application::rewardSortPackages(bool ascending) {
    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](const Package & a, const Package & b) {
            int weight1 = a.getReward() / (a.getWeight() + a.getVolume());
            int weight2 = b.getReward() / (b.getWeight() + b.getVolume());
            return weight1 > weight2;
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package & a, const Package & b) {
        int weight1 = a.getReward() / (a.getWeight() + a.getVolume());
        int weight2 = b.getReward() / (b.getWeight() + b.getVolume());
        return weight1 < weight2;
    });
}

void Application::costSortDeliveryMan(bool ascending) {
    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan & a, const DeliveryMan & b) {
            int weight1 = a.getCost() / (a.getMaxWeight() + a.getMaxVolume());
            int weight2 = b.getCost() / (b.getMaxWeight() + b.getMaxVolume());
            return weight1 > weight2;
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan & a, const DeliveryMan & b) {
        int weight1 = a.getCost() / (a.getMaxWeight() + a.getMaxVolume());
        int weight2 = b.getCost() / (b.getMaxWeight() + b.getMaxVolume());
        return weight1 < weight2;
    });
}

pair<int, int> Application::scenery1() {

    for (auto pck : *packages) pck.setUsed(false);

    for (auto tmp : *deliverymans) tmp.getShipping()->clearShipping();

    int countStaff = 0; size_t countPack = packages->size();

    testSortDeliveryman(false);
    testSortPackages(true);

    vector<Package> auxVec = *packages;
    vector<DeliveryMan> auxVecDel = *deliverymans;

    /** First loop should be always to iterate through all men? **/
    for (auto deliveryman : auxVecDel) {

        deliveryman.getShipping()->clearShipping();

        vector<Package> aux = bestfitBT(*deliveryman.getShipping(), auxVec);

        if (!aux.empty()) {
            countStaff++;
            countPack -= aux.size();
        }
    }
    /*cout << "Num Staff: " << countStaff << ", Num Packages: Remaining " << countPack << endl;*/
    return make_pair(countStaff, countPack);
}

pair<int, pair <int, int>> Application::scenery2() {

    for (auto pck : *packages) pck.setUsed(false);

    int countStaff = 0; size_t countPack = packages->size();

    costSortDeliveryMan(true);
    rewardSortPackages(false);

    vector<Package> auxVec = *packages;
    vector<DeliveryMan> auxVecDel = *deliverymans;

    /** First loop should be always to iterate through all men? **/
    for (auto deliveryman : auxVecDel) {

        countStaff++;

        deliveryman.getShipping()->clearShipping();

        for (size_t i = 0; i < auxVec.size(); i++) {
            if (!deliveryman.getShipping()->isFull() && deliveryman.getShipping()->fits(auxVec[i]) && !auxVec[i].getUsed()) {
                countPack--;
                deliveryman.getShipping()->pushPackage(auxVec[i]);
                cout << "Weight: " << deliveryman.getShipping()->getCurrentWeight() << " Volume: " << deliveryman.getShipping()->getCurrentVol() <<
                " Cost: " << (deliveryman.getCost() - deliveryman.getShipping()->getCurrentReward()) << endl;

            }
        }

        if (deliveryman.getShipping()->getPackages().empty()) break;
        cout << "--------------------------------------------------------------" << endl;
    }

    int total_profit = 0;
    for (auto tmp : auxVecDel) {
        if (!tmp.getShipping()->getPackages().empty())
            total_profit -= (tmp.getCost() - tmp.getShipping()->getCurrentReward());
    }
    return make_pair(total_profit, make_pair(countStaff, countPack));
}

vector<Package> Application::bestfitBT(Shipping & shipping, vector<Package> & packages_) {

    /*cout << "Weight: " << shipping.getCurrentWeight() << "Volume" << shipping.getCurrentVol() << endl;*/

    /** STOP CONDITION **/
    if (shipping.isFull()) return shipping.getPackages();

    vector<Package> res = shipping.getPackages();



    for (int i = 0; i < packages_.size(); i++) {

        if (!packages_[i].getUsed() && shipping.fits(packages_[i])) {
           /* cout << packages_[i].getUsed() << " " << packages_[i].getWeight() << " " <<  packages_[i].getVolume() << endl;*/

            shipping.pushPackage(packages_[i]);
            packages_[i].setUsed(true);

            vector<Package> aux = bestfitBT(shipping, packages_);

            if (aux.size() > res.size()) {
                res = aux;
                /*if (res.size() == packages_.size()) return res;*/
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

    /** Because time in files is in seconds **/
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


