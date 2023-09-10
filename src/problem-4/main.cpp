#include "include/euler.hpp"
#include "include/util.hpp"

#include <deque>
#include <iostream>
#include <vector>

static bool
isPalindromic(int Number) {
    if (Number < 10) return true;

    std::deque<int> Digits = {};
    int Num = Number;
    do {
        int Digit = Num % 10;
        Digits.push_front(Digit);
        Num /= 10;
    }
    while (Num > 10);
    Digits.push_front(Num);
    
    while (Digits.size() > 1) {
        int Front = Digits.front();
        int Back = Digits.back();
        Digits.pop_front();
        Digits.pop_back();
        if (Front != Back) return false;
    }
    
    return true;
}

int main() {
	std::cout << "Problem 4" << std::endl;
    std::vector<int> TestData = { 1, 97, 99, 114, 303, 9009 };
    for (int TestElem : TestData) {
        std::cout << TestElem << ": " << (isPalindromic(TestElem) ? "True" : "False") << std::endl;
    }

    int LargestPalindromic = 0;
    int FactorA = 0, FactorB = 0;

    for (int A = 999; A >= 100; A--) {
        for (int B = 999; B >= 100; B--) {
            int Test = A * B;
            if (!isPalindromic(Test)) continue;
            if (Test <= LargestPalindromic) break;

            LargestPalindromic = Test;
            FactorA = A;
            FactorB = B;
            break;
        }
    }

    std::cout << LargestPalindromic << " (" << FactorA << " x " << FactorB << ")" << std::endl;
	return 0;
}
