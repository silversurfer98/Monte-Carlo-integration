#include "include.h"


inline float test_func(float x)
{
    return x * x * x + 2 * x * x + 1;
}

int main()
{
    std::cout << "enter no. of random numbers to be generated : ";
    size_t size;
    std::cin >> size;
    std::cout << "enter range a : ";
    float sd, a, b;
    std::cin >> a;
    std::cout << "enter range b : ";
    std::cin >> b;
    std::cout << "enter standard deviation : ";
    std::cin >> sd;

    std::ofstream file2;
    file2.open("gauss.txt");

    float* ans = gauss_random(size, a, b, sd, 17);
    for (size_t i = 0; i < size; i++)
        file2 << *(ans + i)<<"\n";

    return 0;
}