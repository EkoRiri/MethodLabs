//
// Created by EMIL on 06.03.2022.
//
#include <iostream>
#include <cmath>

float func(float x) {
    return std::exp(5-8/x);//5*x-8*std::log(x)-8
}

int main() {
    float accuracy = 0.001;

    float first = 0.1;
    float second = 2;

    while ((std::abs(second - first)) > accuracy) {
        first = second;
        second = func(first);
    }

    std::cout << "Root value " << second << std::endl;
    std::cout << "Function value " << func(second) - second << std::endl;
    return 0;
}
