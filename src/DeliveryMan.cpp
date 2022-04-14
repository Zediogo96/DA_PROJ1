//
// Created by zediogo96 on 31/03/2022.
//

#include "../include/DeliveryMan.h"

DeliveryMan::DeliveryMan(unsigned int maxV, unsigned int maxW, unsigned int cost) {
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

unsigned DeliveryMan::getCost() const {
    return this->cost;
}

Shipping *DeliveryMan::getShipping() {
    return this->shipping;
}

double DeliveryMan::average() const {
    return (double)(maxWeight + maxVolume) / 2.0f;
}




