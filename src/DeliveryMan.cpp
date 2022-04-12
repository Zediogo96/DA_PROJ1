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

unsigned DeliveryMan::getMaxVolume() const {
    return this->maxVolume;
}

unsigned DeliveryMan::getMaxWeight() const {
    return this->maxWeight;
}

unsigned DeliveryMan::getCost() const {
    return this->cost;
}




