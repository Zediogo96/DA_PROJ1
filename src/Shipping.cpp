//
// Created by zediogo96 on 13/04/2022.
//

#include "../include/Shipping.h"
#include <vector>

using namespace std;

/**
 * DESCRIÇÃO
 * DESCRIÇÃO
 *
 * @param maxW
 * @param maxV
 * @param cost
 */
Shipping::Shipping(unsigned int maxW, unsigned int maxV, unsigned int cost) {

    this->maxWeight = maxW;
    this->maxVol = maxV;
    currentWeight = currentVol = currentReward = 0;
    fullStatus = false;
    packages = {};
}

unsigned Shipping::getMaxWeight() const {
    return this->maxWeight;
}

unsigned Shipping::getCurrentWeight() const {
    return this->currentWeight;
}

unsigned Shipping::getMaxVol() const {
    return this->maxVol;
}

unsigned Shipping::getCurrentVol() const {
    return this->currentVol;
}

void Shipping::increaseCurrentWeight(unsigned int W) {
    currentWeight += W;
}

void Shipping::increaseCurrentVol(unsigned int V) {
    currentVol += V;
}

vector<Package> Shipping::getPackages() {
    return this->packages;
}

bool Shipping::isFull() const {
    if (currentVol >= maxVol || currentWeight >= maxWeight) return true;
    return false;
}

void Shipping::clearShipping() {
    packages.clear();
}

bool Shipping::fits(const Package& p) const {
    if (((p.getVolume() + currentVol) <= maxVol) && ((p.getWeight() + currentWeight) <= maxWeight))  return true;
    return false;
}

void Shipping::removePackage(Package &p) {
    for (auto it = packages.begin(); it != packages.end(); it++) {
        if (p.getWeight() == it->getWeight() && p.getVolume() == it->getVolume() && p.getDuration() == it->getDuration() && p.getReward() == it->getReward()) {
            packages.erase(it);
        }
    }

    p.setUsed(false);
    this->increaseCurrentWeight(-p.getWeight());
    this->increaseCurrentVol(-p.getVolume());
    this->incrementCurrentReward(-p.getReward());
}

void Shipping::pushPackage(Package & p) {
    p.setUsed(true);
    packages.push_back(p);
    this->increaseCurrentWeight(p.getWeight());
    this->increaseCurrentVol(p.getVolume());
    this->incrementCurrentReward(p.getReward());
}

int Shipping::getCurrentReward() const {
    return this->currentReward;
}

void Shipping::incrementCurrentReward(int r) {
    this->currentReward += r;
}



