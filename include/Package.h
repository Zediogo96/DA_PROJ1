//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_PACKAGE_H
#define PROJETO1_PACKAGE_H

class Package {

private:

    unsigned volume;
    unsigned weight;
    int reward;
    unsigned duration;
    bool used;

public:

    /**
     * Class constructor with 3 parameters
     * @param volume
     * @param weight
     * @param reward
     * @param duration
     */
    Package(unsigned volume, unsigned weight, int reward, unsigned duration);

    /**
     * Class destructor to delete the object from memory
     */
    ~Package();

    /**
     * Returns Package associated Volume
     * @return Volume parameter
     */
    unsigned getVolume() const;

    /**
     * Returns Package associated Weight
     * @return Weight parameter
     */
    unsigned getWeight() const;

    /**
     * Returns Package associated reward (cost-efficiency?)
     * @return Reward parameter
     */
     int getReward() const;

    /**
     * Returns // COMPLETE
     * @return Duration parameter
     */
    unsigned getDuration() const;


    void setUsed(bool b);

    bool getUsed() const;

    double average() const;

    bool isEqual(const Package& aPackage) const;
};


#endif //PROJETO1_PACKAGE_H
