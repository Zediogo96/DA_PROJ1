//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_DELIVERYMAN_H
#define PROJETO1_DELIVERYMAN_H

#include "Shipping.h"

class DeliveryMan {

private:

    unsigned maxVolume{};
    unsigned maxWeight{};
    int cost{};
    Shipping * shipping;

public:

    /**
     * Class constructor with 3 parameters:
     * @param maxV maximum volume supported
     * @param maxW maximum weight supported
     * @param cost to transport
     */
    DeliveryMan(unsigned maxV, unsigned maxW, int cost);

    /**
     * Class destructor to delete the object from memory
     */
    ~DeliveryMan();

    /**
     * Returns DeliveryMan maximum volume supported
     * @return Maximum volume parameter
     */
    unsigned getMaxVolume() const;

    /**
     * Returns DeliveryMan maximum weight supported
     * @return Maximum weight parameter
     */
    unsigned getMaxWeight() const;

    /**
     * Returns DeliveryMan associated cost to deliver
     * @return Cost parameter
     */
    int getCost() const;

    Shipping * getShipping();

    double average() const;
};


#endif //PROJETO1_DELIVERYMAN_H
