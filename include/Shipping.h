//
// Created by zediogo96 on 13/04/2022.
//

#ifndef PROJETO1_SHIPPING_H
#define PROJETO1_SHIPPING_H


#include <vector>
#include "Package.h"

/**
 * CLass used to facilitate handling of what each DeliveryMan is shipping
 */
class Shipping {

private:

    std::vector<Package> packages{};

    unsigned maxWeight;
    unsigned currentWeight;

    unsigned maxVol;
    unsigned currentVol;

    int currentProfit;

    bool fullStatus;

public:

    Shipping(unsigned maxW, unsigned maxV, unsigned cost);
    unsigned getMaxWeight() const;
    unsigned getCurrentWeight() const;
    unsigned getMaxVol() const;
    unsigned getCurrentVol() const;

    /** unsigned getShippingSize(); **/

    void increaseCurrentWeight(unsigned W);
    void increaseCurrentVol(unsigned V);
    std::vector<Package> getPackages();
    void clearShipping();

    bool isFull() const;

    bool fits(const Package & p) const;

    void removePackage(Package & p);

    void pushPackage(Package &p);
};


#endif //PROJETO1_SHIPPING_H
