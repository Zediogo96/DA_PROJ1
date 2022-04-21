//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_APPLICATION_H
#define PROJETO1_APPLICATION_H

#include "FileReader.h"
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iomanip>

class Application {

protected:

    Application();

    static Application * app;

    vector<DeliveryMan> * deliverymans{};

    vector<Package> * packages{};

public:

    void loadData();

    /**
     * Singletons should not be assignable.
     */
    void operator=(const Application &) = delete;

    static Application *getInstance();

    vector<DeliveryMan> *getDeliveryMan();

    vector<Package> *getPackages();

    size_t getDeliveryManSize();

    size_t getPackagesSize();

    void sorterDeliveryMans(bool ascending, bool volume);

    void sorterPackages(bool ascending, bool volume);

    void testSortPackages(bool ascending);

    void rewardSortPackages(bool ascending);

    void costSortDeliveryMan(bool ascending);

    /** SCENERY 1 **/
    pair<int, int> scenery1();

    /** SCENERY 2 **/
    pair<int, pair <int, int>> scenery2();

    /** SCENERY 3 **/
    int scenery3();

    vector<Package> bestfitBT(Shipping & shipping, vector<Package> & packages);

    void testSortDeliveryman(bool ascending);

    static vector<int> knapsack_Scenery1(DeliveryMan &deliveryman, vector<Package> &  packages_);

    void printDeliveryMan();

    static vector<int> knapsack_Scenery2(DeliveryMan &deliveryman, vector<Package> &packages_);
};

#endif //PROJETO1_APPLICATION_H
