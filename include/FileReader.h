//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_FILEREADER_H
#define PROJETO1_FILEREADER_H

#include <iostream>
#include <vector>

#include "DeliveryMan.h"
#include "Package.h"

using namespace std;

vector<string> fileReader(const string& f_name);

vector<DeliveryMan> *getDeliveryManFromFiles(const string& f1);

vector<Package> *getPackagesFromFiles(const string& f2);

#endif //PROJETO1_FILEREADER_H
