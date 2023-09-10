#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

static std::vector<int>
getFibonacciNumbers(int Limit = 4000000) {
    int FibA = 1;
    int FibB = 2;
    std::vector<int> FibNums = { FibA, FibB };
    while (true) {
        int FibC = FibA + FibB;
        if (FibC > Limit) {
            break;
        }
        FibNums.push_back(FibC);

        FibA = FibB;
        FibB = FibC;
    }
    return FibNums;
}

int main() {
	std::cout << "Problem 2" << std::endl;
    auto Fibs = getFibonacciNumbers();
    for (int FibNum : Fibs) {
        std::cout << FibNum << " ";
    }
    std::cout << std::endl;

    std::vector<int> EvenFibs;
    std::copy_if(Fibs.begin(), Fibs.end(), std::back_inserter(EvenFibs), [](int Fib) {
        return Fib % 2 == 0;
    });
    int Sum = std::accumulate(EvenFibs.begin(), EvenFibs.end(), 0);
    std::cout << Sum << std::endl;
	return 0;
}
