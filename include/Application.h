//
// Created by zediogo96 on 11/04/2022.
//

#ifndef PROJETO1_APPLICATION_H
#define PROJETO1_APPLICATION_H

#include "FileReader.h"
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iomanip>

/**
 * @brief Contains the main functionalities needed for the program.
 * All fields are declared under protected since this class is implemented as a Singleton
 */
class Application {

protected:

    /**
     * @brief Default Constructor
     */
    Application();

    static Application * app;

    vector<DeliveryMan> * deliverymans{};

    vector<Package> * packages{};

public:

    /**
     * @brief Loads all the data from the input folder to the program
     */
    void loadData();

    void operator=(const Application &) = delete;

    /**
     * @brief Returns a pointer to the Instance object
     * 
     * @return Application * instance
     */
    static Application *getInstance(); 

    /**
     * @brief returns a pointer to the Delivery Mans vector
     * 
     * @return vector<DeliveryMan> * 
     */

    vector<DeliveryMan> *getDeliveryMan();

    /**
     * @brief Returns a pointer to the PAckages vector
     * 
     * @return vector<Package> * 
     */
    vector<Package> *getPackages();

    /**
     * @brief Returns the size of the Delivery Man vector 
     * 
     * @return size_t size
     */
    size_t getDeliveryManSize();

    /**
     * @brief Returns the size of the Packages vector
     * 
     * @return size_t size 
     */
    size_t getPackagesSize();  

    /**
     * @brief Sorting function for vector<DeliveryMan> deliverymans using lambdas
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     * @param volume boolean: if volume equals true, it will be sorted by Volume, else by Weight.
     */
    void sorterDeliveryMans(bool ascending, bool volume);

    /**
     * @brief Sorting function for vector<Package> packages using lambdas
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     * @param volume boolean: if volume equals true, it will be sorted by Volume, else by Weight.
     */
    void sorterPackages(bool ascending, bool volume);

    /**
     * @brief Sorting function utilized to test different sorts for packages in the development cycle, currently using density as a factor
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     */
    void testSortPackages(bool ascending);

    /**
     * @brief Sorting function utilized to test different sorts for deliverymans in the development cycle, currently using density as a factor
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     */
    void testSortDeliveryman(bool ascending);

    /**
     * @brief Sorting function for vector<Package> packages using Reward / (Weight + Volume) as a factor
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     */
    void rewardSortPackages(bool ascending);

    /**
     * @brief  Sorting function for vector<DeliveryMan> packages using Cost / (Weight + Volume) as a factor
     * 
     * @param ascending boolean: declaring if we want to sort in a ascending or descending form.
     */
    void costSortDeliveryMan(bool ascending);


    /**
     * @brief Knapsack Algorithm using Dynamic programming to maximize number of packages a certain delivery man can carry,
     *        depending on its max Weight and using Volume as a comparation factor.
     * 
     *        Time Complexity: O(N x mW), being N the number of packages and mW the maximum weight of the deliveryman
     * 
     *        Space Complexity: O(N x mW), being N the number of packages and mW the maximum weight of the deliveryman, this
     *        because of the extra 2D vector created using DP technique.
     *          
     * 
     * @param deliveryman 
     * @param packages_ 
     * @return vector<int>: vector with the indexes of the packages used
     */
    static vector<int> knapsack_Scenery1(DeliveryMan &deliveryman, vector<Package> &  packages_);

    /**
     * @brief Function used to minimize number of delivery mans used and maximize the number of packages delivered,
     * that is achieved iterating through all the delivery mans and utilizing a knapsack 0-1 algorithm to maximize it's input of packages.
     * 
     * @return pair<int, int> pair.first is the count of DeliveryMans and pair.second is count of Packages left to be delivered
     */
    pair<int, int> scenery1();

    /**
     * @brief Knapsack Algorithm using Dynamic programming to maximize number of packages a certain delivery man can carry, based on 
     *        max Weight and Volume, and using the package reward as a comparation factor.
     * 
     *        Time Complexity: O(N x mW x mV), being N the number of packages, mW the maximum weight of the deliveryman and mV the maximum volume.
     * 
     *        Space Complexity: O(N x mW x mV), being N the number of packages and mW the maximum weight of the deliveryman, this
     *        because of the extra 3D vector created using DP technique.
     *  
     * @param deliveryman 
     * @param packages_ 
     * @return vector<int> vector<int>: vector with the indexes of the packages used
     */
    static vector<int> knapsack_Scenery2(DeliveryMan &deliveryman, vector<Package> &packages_);

    /**
     * @brief Function used to maximize the profit for the company, iterating through each delivery man and utilizing a knapsack algorithm to try to
     *        to maximize it's cost reward per trip.
     * 
     * @return pair<int, pair <int, int>> pair.first is Total Reward, pair.second.first is Total Number of DeliveryMans used and pair.second.second is total Packages left without delivery.
     */
    pair<int, pair <int, int>> scenery2();

    /**
     * @brief Function used to maximize the number of packages a single delivery man can deliver within a 8 hour timeframe (from 9h00 to 17h00)
     * 
     * @return int Number of express packages delivered
     */
    int scenery3();

    /**
     * @brief Discarded function that was used in the first implementation of Scenery1, utilizing backtracking.
     * 
     * @param shipping 
     * @param packages 
     * @return vector<Package> 
     */
    vector<Package> bestfitBT(Shipping & shipping, vector<Package> & packages);    

    /**
     * @brief Auxiliary function to display some useful information regarding algorithms, for example average Weight or Volume Load for delivery mans.
     * 
     * @param scen2 boolean: if it's active, only calculates the information for deliverymans with positive profit within their service.
     */
    void printDeliveryMan(bool scen2);
};

#endif //PROJETO1_APPLICATION_H
