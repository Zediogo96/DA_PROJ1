#include <iostream>

#include "include/FileReader.h"

using namespace std;

int main() {

    vector<Package> * test;
    test = getPackagesFromFiles("../input/package.txt");

    for (auto tmp : *test) {
        cout << tmp.getVolume() << " " << tmp.getWeight() << " " << tmp.getReward() << " " << tmp.getDuration() << endl;
    }
    return 0;
}
