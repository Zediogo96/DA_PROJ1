//
// Created by zediogo96 on 31/03/2022.
//

#include "../include/Package.h"

Package::Package(unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration) {
    this->volume = volume;
    this->weight = weight;
    this->reward = reward;
    this->duration = duration;
}

unsigned Package::getVolume() {
    return this->volume;
}

unsigned Package::getWeight() {
    return this->weight;
}

unsigned Package::getReward() {
    return this->reward;
}

unsigned Package::getDuration() {
    return this->duration;
}

Package::~Package() = default;


