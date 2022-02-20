#include <iostream>
#include <cmath>

float func(float x) {
    return std::pow(x,2) * std::pow(2,x) - 1;
}

int main() {
    float firstGap, secondGap;
    float accuracy;

    std::cout << "Введите первый конец промежутка: " << std::endl;
    std::cin >> firstGap;
    std::cout << "Введите второй конец промежутка: " << std::endl;
    std::cin >> secondGap;

    std::cout << "Введите точность: " << std::endl;
    std::cin >> accuracy;

    float temp;
    while((secondGap - firstGap) > 2 * accuracy) {
        temp = (firstGap + secondGap) / 2;
        if (func(firstGap) * func(temp) > 0) {
            firstGap = temp;
        } else {
            secondGap = temp;
        }
        std::cout << "Первый " << firstGap << " | Второй " << secondGap << std::endl;
    }
    const float result = (firstGap + secondGap) / 2;
    std::cout << "Значение корня с точностью " << accuracy << " равно " << result << std::endl;
    return 0;
}