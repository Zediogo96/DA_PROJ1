//
// Created by zediogo96 on 31/03/2022.
//

#ifndef PROJETO1_PACKAGE_H
#define PROJETO1_PACKAGE_H

class Package {

private:

    unsigned volume;
    unsigned weight;
    unsigned reward;
    unsigned duration;

public:

    /**
     * Class constructor with 3 parameters
     * @param volume
     * @param weight
     * @param reward
     * @param duration
     */
    Package(unsigned volume, unsigned weight, unsigned reward, unsigned duration);

    /**
     * Class destructor to delete the object from memory
     */
    ~Package();

    /**
     * Returns Package associated Volume
     * @return Volume parameter
     */
    unsigned getVolume();

    /**
     * Returns Package associated Weight
     * @return Weight parameter
     */
    unsigned getWeight();

    /**
     * Returns Package associated reward (cost-efficiency?)
     * @return Reward parameter
     */
    unsigned getReward();

    /**
     * Returns // COMPLETE
     * @return Duration parameter
     */
    unsigned getDuration();





};


#endif //PROJETO1_PACKAGE_H
