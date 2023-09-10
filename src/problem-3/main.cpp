#include "include/euler.hpp"
#include "include/util.hpp"

#include <iostream>
#include <vector>

int main() {
	std::cout << "Problem 3" << std::endl;

    long int TestNumber = 600851475143;
    printVector(getPrimeFactorsOf(13195));
    printVector(getPrimeFactorsOf(23));
    printVector(getPrimeFactorsOf(TestNumber));

	return 0;
}
