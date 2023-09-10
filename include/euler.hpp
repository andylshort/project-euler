#pragma once

#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

template<typename T>
static bool
isPrime(T Number) {
    if (Number < 2)
        return false;
    if (Number == 2)
        return true;
    if (Number == 3)
        return true;
    if (Number % 2 == 0)
        return false;

    for (T TestNumber = 3; TestNumber * TestNumber < Number; TestNumber += 2) {
        if (Number % TestNumber == 0)
            return false;
    }
    return true;
}

template<typename T>
static std::vector<T>
primeSieve(T Limit = 100) {
    std::vector<bool> Primes(Limit + 1, true);
    Primes[0] = false; // 0 is not prime
    Primes[1] = false; // 1 is not prime

    for (std::size_t TestNumber = 2; TestNumber < Primes.size(); TestNumber++) {
        if (!isPrime(TestNumber)) continue;
        for (std::size_t Multiple = TestNumber + TestNumber; Multiple < Primes.size(); Multiple += TestNumber) {
            Primes[Multiple] = false;
        }
    }

    std::vector<T> ActualPrimes = {};
    for (auto it = Primes.begin(); it != Primes.end(); it++) {
        int Index = std::distance(Primes.begin(), it);
        if (*it) {
            ActualPrimes.push_back(Index);
        }
    }
    return ActualPrimes;
}

template<typename T>
static std::vector<T>
getPrimeFactorsOf(T Number) {
    std::cout << "Getting primes\n";
    std::vector<T> PrimeFactors = {};

    if (isPrime(Number)) {
        PrimeFactors.push_back(Number);
        return PrimeFactors;
    }

    T LeftOver = Number;
    while (LeftOver != 1) {
        for (T Prime = 2; Prime * Prime < Number; Prime++) {
            if (!isPrime(Prime)) continue;
            if (LeftOver % Prime != 0) continue;
            LeftOver /= Prime;
            PrimeFactors.push_back(Prime);
            break;
        }
    }
    return PrimeFactors;
}

template<typename T>
static std::vector<T>
getFactorsOf(T Number) {
    std::set<T> FactorSet = {};
    for (T PotentialFactor = 1; PotentialFactor * PotentialFactor < Number; PotentialFactor++) {
        if (Number % PotentialFactor != 0) continue;
        FactorSet.insert(PotentialFactor);
        FactorSet.insert(Number / PotentialFactor);
    }
    std::vector<T> Factors(FactorSet.begin(), FactorSet.end());
    return Factors;
}
