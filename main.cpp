#include "include/FileReader.h"

#include <iostream>
#include <iomanip>
#include <iterator>

using namespace std;

int scenery3(const vector<Package>& packages) {

    vector<Package> auxVec;
    vector<Package> expressPackages;

    auxVec.reserve(packages.size());

    for (const Package& pack : packages) {
        auxVec.emplace_back(pack);
    }

    sort(auxVec.begin(), auxVec.end(), [](Package & a,Package & b) {
        return a.getDuration() < b.getDuration();
    });

    unsigned timeLeft = 8 * 3600;

    for (Package aPackage : auxVec) {
        if (aPackage.getDuration() <= timeLeft) {
            expressPackages.push_back(aPackage);
            timeLeft -= aPackage.getDuration();
        }
        else break;
    }

    return (int)(((8 * 3600) - timeLeft) / expressPackages.size());
}

int main() {

    vector<Package> * test;
    test = getPackagesFromFiles("../input/package.txt");
    cout << scenery3(*test);
}
