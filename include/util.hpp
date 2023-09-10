#pragma once

#include <iostream>
#include <vector>

template<typename T>
static void
printVector(std::vector<T> Vec) {
    for (T Elem : Vec) {
        std::cout << Elem << " ";
    }
    std::cout << std::endl;
}
