//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_APPLICATION_H
#define PROJETO1_APPLICATION_H

#include "FileReader.h"
#include <algorithm>

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

    void sorterDeliveryMans(bool ascending);

    void sorterPackages(bool ascending);

    void testSortPackages(bool ascending);

    /** SCENERY 1 **/
    pair<int, int> scenery1();

    /** SCENERY 3 **/
    int scenery3();

    vector<Package> bestfitBT(Shipping & shipping, vector<Package> & packages);

    void testSortDeliveryman(bool ascending);


};

#endif //PROJETO1_APPLICATION_H
