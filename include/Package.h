//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_PACKAGE_H
#define PROJETO1_PACKAGE_H

/**
 * @brief Class used to encapsulate inputs read from input/packages.txt
 * 
 */
class Package {

private:

    unsigned volume;
    unsigned weight;
    int reward;
    unsigned duration;
    bool used;

public:

    /**
     * @brief Class constructor with 3 parameters
     * @param volume
     * @param weight
     * @param reward
     * @param duration
     */
    Package(unsigned volume, unsigned weight, int reward, unsigned duration);

    /**
     * @brief Class destructor to delete the object from memory
     */
    ~Package();

    /**
     * @brief Returns Package associated Volume
     * @return Volume parameter
     */
    unsigned getVolume() const;

    /**
     * @brief Returns Package associated Weight
     * @return Weight parameter
     */
    unsigned getWeight() const;

    /**
     * @brief Returns Package associated reward
     * @return Reward parameter
     */
     int getReward() const;

    /**
     * @brief Returns Duration associated parameter
     * @return Duration parameter
     */
    unsigned getDuration() const;

    /**
     * @brief Specifies if the package has been already used or not during an Algorithm
     * 
     * @return true means it has been used
     * @return false it has not
     */
    bool getUsed() const;

    /**
     * @brief Used to change the package used status
     * 
     * @param b: boolean
     */
    void setUsed(bool b);

    /**
     * @brief Returns the package density (weight / volume)
     * 
     * @return double density
     */
    double getDensity() const;

    /**
     * @brief Compares the this->package to another package
     * 
     * @param aPackage 
     * @return true if they are equal
     * @return false if not
     */
    bool isEqual(const Package& aPackage) const;
};


#endif //PROJETO1_PACKAGE_H
