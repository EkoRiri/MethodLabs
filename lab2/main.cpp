#include <iostream>
#include <cmath>

float func(float x) {
    return x*x*x-3*x*x+12*x-9;
}

float funcFirst(float x) {
    return 3*x*x-6*x+12;
}

int main() {
    float accuracy, M; //Точность
    float initialApproximation;

    accuracy = 0.0000001;

    M = 21;//3;

    initialApproximation = -1;//-1;

    std::cout << "Xi " << initialApproximation << " f(Xi) " << func(initialApproximation) << " f1(Xi) " << funcFirst(initialApproximation) << " |f(Xi)|/m " << (std::abs(func(initialApproximation)) / M) << std::endl;
    while ((std::abs(func(initialApproximation)) / M) > accuracy) {
        initialApproximation = initialApproximation - func(initialApproximation) / funcFirst(initialApproximation);
        std::cout << "Xi " << initialApproximation << " f(Xi) " << func(initialApproximation) << " f1(Xi) " << funcFirst(initialApproximation) << " |f(Xi)|/m " << (std::abs(func(initialApproximation)) / M) << std::endl;
    }

    std::cout << "Root value " << initialApproximation << std::endl;
    std::cout << "Function value " << func(initialApproximation) << std::endl;
    return 0;
}
