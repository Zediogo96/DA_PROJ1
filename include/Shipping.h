//
// Created by zediogo96 on 13/04/2022.
//

#ifndef PROJETO1_SHIPPING_H
#define PROJETO1_SHIPPING_H


#include <vector>
#include "Package.h"

/**
 * @brief CLass used to encapsulate and facilitate handling of what each DeliveryMan is shipping
 */
class Shipping {

private:

    std::vector<Package> packages{};

    unsigned maxWeight;
    unsigned currentWeight;

    unsigned maxVol;
    unsigned currentVol;
    int currentReward;

    bool fullStatus;

public:
    /**
     * @brief Construct a new Shipping object
     * 
     * @param maxW max Weight supported (same as its associated DeliveryMan)
     * @param maxV max Volume supported (same as its associated DeliveryMan)
     * @param cost Cost associated to the its Delivery Man service 
     **/
    Shipping(unsigned maxW, unsigned maxV, unsigned cost);

    /**
     * @brief Retuns Maximum Weight
     * 
     * @return unsigned 
     */
    unsigned getMaxWeight() const;

    /**
     * @brief Returns the current weight (sum of all packages weight) in the shipment
     * 
     * @return unsigned 
     */
    unsigned getCurrentWeight() const;

    /**
     * @brief Retuns Maximum Volume
     * 
     * @return unsigned 
     */
    unsigned getMaxVol() const;

    /**
     * @brief Returns the current volume (sum of all packages volume) in the shipment
     * 
     * @return unsigned 
     */
    unsigned getCurrentVol() const;

    /**
     * @brief Increments current Weight by W weight units
     * 
     * @param W weight
     */
    void increaseCurrentWeight(unsigned W);

    /**
     * @brief Increments current Volume by V volume units
     * 
     * @param V volume
     */
    void increaseCurrentVol(unsigned V);

    /**
     * @brief Returns the vector of packages of the shipment
     * 
     * @return std::vector<Package> 
     */
    std::vector<Package> getPackages();

    /**
     * @brief Clears all the packages from the shipment, also updating its current Volume, Weight and Reward to 0
     * 
     */
    void clearShipping();

    /**
     * @brief Checks if the current weight is >= than the maximum Weight, and also if current volume is >= than the maximum Volume
     * 
     * @return true or false
     */
    bool isFull() const;

    /**
     * @brief Function to check fi adding a specific Package will make the current Volume or Weight exceed it's specific maximum value
     * 
     * @param package
     * @return true 
     * @return false 
     */
    bool fits(const Package & p) const;

    /**
     * @brief Removes a package from the shipment vector of packages, adjusting accordinly its current Weight, Volume and Reward.
     *        Also sets the used status of package to false.
     * 
     * @param package
     */
    void removePackage(Package & p);

    /**
     * @brief Removes a package from the shipment vector of packages, adjusting accordinly its current Weight, Volume and Reward.
     *        Also sets the used status of package to true.
     * 
     * @param p 
     */
    void pushPackage(Package &p);

    /**
     * @brief Returns the current reward of the package (sum of all package's rewards that are in it)
     * 
     * @return int 
     */
    int getCurrentReward() const;

    /**
     * @brief Increments current reward by r reward units.
     * 
     * @param r reward
     */
    void incrementCurrentReward(int r);
};


#endif //PROJETO1_SHIPPING_H
