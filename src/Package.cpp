//
// Created by zediogo96 on 31/03/2022.
//

#include "../include/Package.h"

Package::Package(unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration) {
    this->volume = volume;
    this->weight = weight;
    this->reward = reward;
    this->duration = duration;
    this->used = false;
}

unsigned Package::getVolume() const {
    return this->volume;
}

unsigned Package::getWeight() const {
    return this->weight;
}

unsigned Package::getReward() const {
    return this->reward;
}

unsigned Package::getDuration() const {
    return this->duration;
}

void Package::setUsed(bool b) {
    this->used = b;
}

bool Package::getUsed() const {
    return this->used;
}

double Package::average() const {
    return (weight + volume) / 2.0f;
}

Package::~Package() = default;


