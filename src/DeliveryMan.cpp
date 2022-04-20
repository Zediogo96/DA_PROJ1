//
// Created by zediogo96 on 31/03/2022.
//

#include <cmath>
#include "../include/DeliveryMan.h"

DeliveryMan::DeliveryMan(unsigned int maxV, unsigned int maxW, int cost) {
    this->maxVolume = maxV;
    this->maxWeight = maxW;
    this->cost = cost;
    this->shipping = new Shipping(maxW, maxV, cost);
}

DeliveryMan::~DeliveryMan() = default;

unsigned DeliveryMan::getMaxVolume() const {
    return this->maxVolume;
}

unsigned DeliveryMan::getMaxWeight() const {
    return this->maxWeight;
}

int DeliveryMan::getCost() const {
    return this->cost;
}

Shipping *DeliveryMan::getShipping() {
    return this->shipping;
}

double DeliveryMan::average() const {
    return (double) maxWeight / maxVolume;
}

double DeliveryMan::getWeightLoad() const {
    return round(((double)shipping->getCurrentWeight() / maxWeight) * 100);
}

double DeliveryMan::getVolumeLoad() const {
    return round(((double)shipping->getCurrentVol() / maxVolume) * 100);
}




