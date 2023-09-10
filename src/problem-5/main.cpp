#include <iostream>
#include <numeric>

int main() {
	std::cout << "Problem 5" << std::endl;

    int Answer = 2520;
    int StartFactor = 11;
    int LimitFactor = 20;

    for (int Factor = StartFactor; Factor <= LimitFactor; Factor++) {
        Answer = std::lcm(Answer, Factor);
    }

    std::cout << Answer << std::endl;

	return 0;
}
