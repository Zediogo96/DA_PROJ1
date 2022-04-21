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

/**
 * @brief Reads inputs from a file into a vector of strings, auxiliar function to the two other functions bellow
 * 
 * @param f_name: File name
 * @return vector<string> arguments
 */
vector<string> fileReader(const string& f_name);

/**
 * @brief Reads DeliveryMans from the file to vector deliverymans
 * 
 * @param f1: File Name
 * @return vector<DeliveryMan> * : pointer to the destination vector
 */
vector<DeliveryMan> *getDeliveryManFromFiles(const string& f1);

/**
 * @brief Reads Packages from the file to vector packages
 * 
 * @param f2: File Name
 * @return vector<Package> * : pointer to the destinatin vector
 */
vector<Package> *getPackagesFromFiles(const string& f2);

#endif //PROJETO1_FILEREADER_H
