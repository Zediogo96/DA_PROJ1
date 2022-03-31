//
// Created by zediogo96 on 31/03/2022.
//

#include "../include/FileReader.h"

#include <iostream>
#include <fstream>
#include <sstream>

vector<string> fileReader(const string& f_name) {

    ifstream inFile;
    string line;

    vector<string> v1;

    inFile.open(f_name);

    if (inFile.is_open())  {
        /** IGNORE FIRST LINE, DESCRIPTION OF THE COLUMNS **/
        getline(inFile, line);

        while (getline(inFile, line)) {
            v1.emplace_back(line);
        }
        inFile.close();
    }
    return v1;
}

vector<DeliveryMan> *getDeliveryManFromFiles(const string& f1) {

    vector<DeliveryMan> * deliveryman = new vector<DeliveryMan>;
    vector<string> inputsFromFile;

    unsigned maxV, maxW, cost;

    inputsFromFile = fileReader(f1);

    for (const auto& line : inputsFromFile) {
        stringstream ss(line);
        ss >> maxV;
        ss >> maxW;
        ss >> cost;

        deliveryman->emplace_back(DeliveryMan(maxV, maxW, cost));
    }
    return deliveryman;
}

vector<Package> *getPackagesFromFiles(const string& f2) {
    vector<Package> * packages = new vector<Package>;
    vector<string> inputsFromFile;

    unsigned volume, weight, reward, duration;

    inputsFromFile = fileReader(f2);

    for (const auto& line : inputsFromFile) {
        stringstream ss(line);
        ss >> volume;
        ss >> weight;
        ss >> reward;
        ss >> duration;

        packages->emplace_back(Package(volume, weight, reward, duration));
    }
    return packages;
}
