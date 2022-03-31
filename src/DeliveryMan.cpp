//
// Created by zediogo96 on 31/03/2022.
//

#include "../include/DeliveryMan.h"

DeliveryMan::DeliveryMan(unsigned int maxV, unsigned int maxW, unsigned int cost) {
    this->maxVolume = maxV;
    this->maxWeight = maxW;
    this->cost = cost;
}

DeliveryMan::~DeliveryMan() = default;

unsigned DeliveryMan::getMaxVolume() {
    return this->maxVolume;
}

unsigned DeliveryMan::getMaxWeight() {
    return this->maxWeight;
}

unsigned DeliveryMan::getCost() {
    return this->cost;
}




