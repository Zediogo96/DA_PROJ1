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

    void sorterDeliveryMans(bool ascending);

    void sorterPackages(bool ascending);
};


#endif //PROJETO1_APPLICATION_H
