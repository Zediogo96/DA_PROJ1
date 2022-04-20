//
// Created by zediogo96 on 11/04/2022.
//

#include "../include/Application.h"

Application::Application() = default;

Application* Application::app = nullptr;

void Application::loadData() {
    this->packages = getPackagesFromFiles("../input/package.txt");
    this->deliverymans = getDeliveryManFromFiles("../input/carrinhas.txt");
}

vector<Package> * Application::getPackages() {
    return this->packages;
}

vector<DeliveryMan> * Application::getDeliveryMan() {
    return this->deliverymans;
}

size_t Application::getDeliveryManSize() {
    return this->deliverymans->size();
}

size_t Application::getPackagesSize() {
    return this->packages->size();
}

Application *Application::getInstance() {
    if (app == nullptr) app = new Application();

    return app;
}

void Application::sorterDeliveryMans(bool ascending) {

    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
            if (a.getMaxWeight() != b.getMaxWeight()) return a.getMaxWeight() > b.getMaxWeight();
            return a.getMaxVolume() > b.getMaxVolume();
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
        if (a.getMaxWeight() != b.getMaxWeight()) return a.getMaxWeight() < b.getMaxWeight();
        return a.getMaxVolume() < b.getMaxVolume();
    });
}

void Application::sorterPackages(bool ascending) {

    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
            if (a.getWeight() != b.getWeight()) return a.getWeight() > b.getWeight();
            return a.getVolume() > b.getVolume();
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
        if (a.getWeight() != b.getWeight()) return a.getWeight() < b.getWeight();
        return a.getVolume() < b.getVolume();
    });
}

void Application::testSortPackages(bool ascending) {
    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
            return a.average() > b.average();
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package& a, const Package& b) {
        return a.average() < b.average();
    });
}

void Application::testSortDeliveryman(bool ascending) {
    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
            return a.average() > b.average();
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan& a, const DeliveryMan& b) {
        return a.average() < b.average();
    });
}

void Application::rewardSortPackages(bool ascending) {
    if (!ascending) {
        sort(this->packages->begin(), this->packages->end(), [&](const Package & a, const Package & b) {
            double weight1 = (double) a.getReward() / (a.getWeight() + a.getVolume());
            double weight2 = (double) b.getReward() / (b.getWeight() + b.getVolume());
            return weight1 > weight2;
        });
    }

    sort(this->packages->begin(), this->packages->end(), [&](const Package & a, const Package & b) {
        double weight1 = (double) a.getReward() / (a.getWeight() + a.getVolume());
        double weight2 = (double) b.getReward() / (b.getWeight() + b.getVolume());
        return weight1 < weight2;
    });
}

void Application::costSortDeliveryMan(bool ascending) {
    if (!ascending) {
        sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan & a, const DeliveryMan & b) {
            double weight1 = (double) a.getCost() / (a.getMaxWeight() + a.getMaxVolume());
            double weight2 = (double) b.getCost() / (b.getMaxWeight() + b.getMaxVolume());
            return weight1 > weight2;
        });
    }

    sort(this->deliverymans->begin(), this->deliverymans->end(), [&](const DeliveryMan & a, const DeliveryMan & b) {
        double weight1 = (double) a.getCost() / (a.getMaxWeight() + a.getMaxVolume());
        double weight2 = (double) b.getCost() / (b.getMaxWeight() + b.getMaxVolume());
        return weight1 < weight2;
    });
}

vector<int> Application::knapsack_Scenery1(DeliveryMan & deliveryman, vector<Package> & packages_) {

    int maxW = (int)deliveryman.getMaxWeight();
    int maxV = (int)deliveryman.getMaxVolume();

    /** We use + 1 at the end of each "size" declaration to be able to use index 0 as a "dummy" value **/
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(packages_.size() + 1, vector<vector<int>>(deliveryman.getMaxWeight() + 1, vector<int>(deliveryman.getMaxVolume() + 1, 0)));

    for (int i = 1; i < packages_.size(); i++) {
        int weight = (int)(packages_.begin() + i - 1)->getWeight(), vol = (int)(packages_.begin() + i - 1)->getVolume(), rew = (int)(packages_.begin() + i - 1)->getReward();

        for (int j = 0; j <= maxW; j++) {
            for (int k = 0; k <= maxV; k++) {
                dp[i][j][k] = dp[i - 1][j][k];

                if (j >= weight && k >= vol && dp[i][j][k] < (dp[i - 1][j - weight][k - vol] + 1)) {
                    dp[i][j][k] = dp[i - 1][j - weight][k - vol] + 1;
                   /* cout <<dp[i][j][k] << endl;*/
                }
            }
        }
    }

    int n = (int) packages_.size();

    vector<int> ret;

    while ( n > 0) {
        if (dp[n][maxW][maxV] != dp[n - 1][maxW][maxV]) {
            maxW -= (int)(packages_.begin() + (n - 1))->getWeight();
            maxV -= (int)(packages_.begin() + (n - 1))->getVolume();
            ret.push_back(n - 1);
        }
        n--;
    }
    /** Vai retornar os indexs atuais das packages a serem utilizadas **/
    return ret;
}

pair<int, int> Application::scenery1() {

    auto start = chrono::steady_clock::now();

    for (auto pck : *packages) pck.setUsed(false);

    for (auto del : *deliverymans) del.getShipping()->clearShipping();

    /** SORTS **/
    testSortPackages(false);
    testSortDeliveryman(true);

    vector<Package> aux = *packages;

    int countStaff = 0, count_pack = (int) packages->size(), count_reward = 0;

    for (auto del : *deliverymans) {

        auto sort = knapsack_Scenery1(del, aux);

        if (sort.empty()) continue;

        count_reward -= del.getCost();

        for (auto each : sort) {
            del.getShipping()->pushPackage(aux.at(each));
            aux.erase(aux.begin() + each);
        }

        countStaff++;
        count_pack -= ((int)del.getShipping()->getPackages().size());
        count_reward += del.getShipping()->getCurrentReward();

    }


    auto end = chrono::steady_clock::now();

    cout << "There were needed " << countStaff << " delivery staff (out of " << deliverymans->size()
         << " total), and there were " << count_pack << " packages left to deliver, acquiring a total profit of: " << count_reward << "." << endl;

    cout << "Algorithm execution time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " (milli seconds)." << endl;

    return make_pair(countStaff, count_pack);

}

void Application::printDeliveryMan() {
    int averageV_load = 0 , averageW_load = 0, total = 0;

    for (size_t i = 0; i < deliverymans->size(); i++) {

        if (!deliverymans->at(i).getShipping()->getPackages().empty()) {

            total++;
            averageV_load += deliverymans->at(i).getVolumeLoad();
            averageW_load += deliverymans->at(i).getWeightLoad();


            cout << "[" << setw(2) << i << "] [Current Weight: " << setw(3)
                 << deliverymans->at(i).getShipping()->getCurrentWeight() << "/" << deliverymans->at(i).getMaxWeight()
                 << " (" << setw(3) << deliverymans->at(i).getWeightLoad() << "%)] | " << "[Current Volume: " << setw(3)
                 << deliverymans->at(i).getShipping()->getCurrentVol()
                 << "/" << deliverymans->at(i).getMaxVolume() << " (" << setw(3) << deliverymans->at(i).getVolumeLoad()
                 << "%)]" << endl;
        }
    }
    cout << endl << setw(2) << "[Average Weight Load: " << averageV_load / total << "% ] [Average Volume Load: " << averageW_load / total << "% ]"<< endl;
}

pair<int, pair <int, int>> Application::scenery2() {

    auto start = chrono::steady_clock::now();

    for (auto pck : *packages) pck.setUsed(false);

    for (auto del : *deliverymans) del.getShipping()->clearShipping();

    int countStaff = 0; size_t countPack = packages->size();

    costSortDeliveryMan(false);
    rewardSortPackages(true);

    vector<Package> auxVec = *packages;
    vector<DeliveryMan> auxVecDel = *deliverymans;

    /** First loop should be always to iterate through all men? **/
    for (auto deliveryman : auxVecDel) {

        deliveryman.getShipping()->clearShipping();

        for (auto & i : auxVec) {

            if (deliveryman.getShipping()->getPackages().empty()) continue;

            if (!deliveryman.getShipping()->isFull() && deliveryman.getShipping()->fits(i) && !i.getUsed()) {
                deliveryman.getShipping()->pushPackage(i);
            }
        }
    }

    int total_profit = 0;
    for (auto tmp : auxVecDel) {
        if (!tmp.getShipping()->getPackages().empty()) {
            if ((tmp.getCost() - tmp.getShipping()->getCurrentReward()) < 0) {
                total_profit -= (tmp.getCost() - tmp.getShipping()->getCurrentReward());
                countStaff++;
                countPack -= tmp.getShipping()->getPackages().size();
            }
        }
    }

    auto end = chrono::steady_clock::now();



    cout << "To maximize profits, there were needed " << countStaff << " staff (out of " << deliverymans->size()
         << " total) delivering packages, leaving " << countPack << " to deliver, the total profit was: " << total_profit << endl;

    cout << "Algorithm execution time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " (milli seconds)." << endl;

    return make_pair(total_profit, make_pair(countStaff, countPack));
}

vector<Package> Application::bestfitBT(Shipping & shipping, vector<Package> & packages_) {

    /** STOP CONDITION **/
    if (shipping.isFull()) return shipping.getPackages();

    vector<Package> res = shipping.getPackages();

    for (int i = 0; i < packages_.size(); i++) {

        if (!packages_[i].getUsed() && shipping.fits(packages_[i])) {

            shipping.pushPackage(packages_[i]);
            packages_[i].setUsed(true);

            vector<Package> aux = bestfitBT(shipping, packages_);

            if (aux.size() > res.size()) {
                res = aux;

            }
            else {
                shipping.removePackage(packages_[i]);
                packages_[i].setUsed(false);
            }
        }
    }
    return res;
}

int Application::scenery3() {

    auto start = chrono::steady_clock::now();

    vector<Package> auxVec;
    vector<Package> expressPackages;
    unsigned totalWeight = 0;

    auxVec.reserve(packages->size());

    for (const Package& pack : *packages) {
        auxVec.emplace_back(pack);
    }

    sort(auxVec.begin(), auxVec.end(), [](Package & a,Package & b) {
        return a.getDuration() < b.getDuration();
    });

    /** Because time in files is in seconds **/
    unsigned timeLeft = 8 * 3600;

    for (const Package& aPackage : auxVec) {
        if (aPackage.getDuration() <= timeLeft) {
            expressPackages.push_back(aPackage);
            timeLeft -= aPackage.getDuration();
            totalWeight += aPackage.getWeight();
        }
        else break;
    }

    int res =  (int)(((8 * 3600) - timeLeft) / expressPackages.size());

    auto end = chrono::steady_clock::now();

    cout << "From 9h00 to 17h00, delivering the packages with the lowest durations, you are able to deliver: " << res
    << " packages, out of " <<  packages->size() << " in total (" << round(((double)res / packages->size()) * 100) << "%)." << endl;
    cout << "Algorithm execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " (micro seconds)." << endl;

    return (int)(((8 * 3600) - timeLeft) / expressPackages.size());
}


