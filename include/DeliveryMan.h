//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_DELIVERYMAN_H
#define PROJETO1_DELIVERYMAN_H

#include "Shipping.h"

/**
 * @brief Class used to encapsulate inputs read from input/carrinhas.txt
 * 
 */
class DeliveryMan {

private:

    unsigned maxVolume{};
    unsigned maxWeight{};
    int cost;
    Shipping * shipping;

public:

    /**
     * @brief Class constructor with 3 parameters:
     * @param maxV maximum volume supported
     * @param maxW maximum weight supported
     * @param cost to transport
     */
    DeliveryMan(unsigned maxV, unsigned maxW, int cost);

    /**
     * @brief Class destructor to delete the object from memory
     */
    ~DeliveryMan();

    /**
     * @brief Returns DeliveryMan maximum volume supported
     * @return Maximum Volume parameter
     */
    unsigned getMaxVolume() const;

    /**
     * @brief Returns DeliveryMan maximum weight supported
     * @return Maximum Weight parameter
     */
    unsigned getMaxWeight() const;

    /**
     * @brief Returns DeliveryMan associated cost to deliver
     * @return Cost parameter
     */
    int getCost() const;


    /**
     * @brief Returns the Class that encapsulates the shipment of the delivery man
     * 
     * @return Shipping * shipment
     */
    Shipping * getShipping();

    /**
     * @brief Return the Density parameter (Weight / Volume)
     * 
     * @return double density
     */
    double getDensity() const;

    /**
     * @brief  Return the Weight Load parameter (current Shipment Weight / Maximum Weight) in percentage (%)
     * 
     * @return double Weight Load
     */
    double getWeightLoad() const;

    /**
     * @brief Return the Volume Load parameter (current Shipment Volume / Maximum Volume) in percentage (%)
     * 
     * @return double Volume Load
     */
    double getVolumeLoad() const;
};

#endif //PROJETO1_DELIVERYMAN_H
