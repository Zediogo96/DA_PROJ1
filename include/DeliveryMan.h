//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_DELIVERYMAN_H
#define PROJETO1_DELIVERYMAN_H

class DeliveryMan {

private:

    unsigned maxVolume{};
    unsigned maxWeight{};
    unsigned cost{};

public:

    /**
     * Class constructor with 3 parameters:
     * @param maxV maximum volume supported
     * @param maxW maximum weight supported
     * @param cost to transport
     */
    DeliveryMan(unsigned maxV, unsigned maxW, unsigned cost);

    /**
     * Class destructor to delete the object from memory
     */
    ~DeliveryMan();


    /**
     * Returns DeliveryMan maximum volume supported
     * @return Maximum volume parameter
     */
    unsigned getMaxVolume();

    /**
     * Returns DeliveryMan maximum weight supported
     * @return Maximum weight parameter
     */
    unsigned getMaxWeight();

    /**
     * Returns DeliveryMan associated cost to deliver
     * @return Cost parameter
     */
    unsigned getCost();
};


#endif //PROJETO1_DELIVERYMAN_H
