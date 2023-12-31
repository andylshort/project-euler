#include "include/util.hpp"

#include <iostream>
#include <numeric>
#include <set>
#include <vector>

static std::vector<int>
getMultiplesOf(int Num, int Limit = 100) {
    std::vector<int> Multiples = { };
    int CurrentMultiple = 0;
    do {
        CurrentMultiple += Num;
        Multiples.push_back(CurrentMultiple);
    }
    while ((CurrentMultiple + Num) < Limit);
    return Multiples;
}

int main(int argc, char* argv[]) {
	std::cout << "Problem 1" << std::endl;

    int Limit = 1000;
    if (argc > 1) {
        Limit = std::atoi(argv[1]);
    }
    std::cout << "Limit: " << Limit << std::endl;

    std::vector<int> MultiplesOf3 = getMultiplesOf(3, Limit);
    std::vector<int> MultiplesOf5 = getMultiplesOf(5, Limit);
    
    std::set<int> UniqueNumbersBelowLimit(MultiplesOf3.begin(), MultiplesOf3.end());
    UniqueNumbersBelowLimit.insert(MultiplesOf5.begin(), MultiplesOf5.end());

    printVector(MultiplesOf3);
    printVector(MultiplesOf5);

    std::vector<int> UniqueNumVec(
        UniqueNumbersBelowLimit.begin(),
        UniqueNumbersBelowLimit.end());
    printVector(UniqueNumVec);

    int Sum =
        std::accumulate(
            UniqueNumbersBelowLimit.begin(),
            UniqueNumbersBelowLimit.end(), 0);

    std::cout << Sum << std::endl;
	return 0;
}
