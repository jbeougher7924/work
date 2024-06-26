#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <functional>
#include <ecef_converter.h>

// Define a template function that takes two function objects as arguments
template <typename Func1, typename Func2>
auto callFunctions(Func1 func1, Func2 func2) -> typename std::result_of<Func2()>::type
{
    // Call the first function and store its return value
    auto result1 = func1();

    // Call the second function and store its return value
    auto result2 = func2();

    // Print the return values
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return result2;
}

template <typename Func1>
auto conversion(Func1 func1) -> decltype(func1())
{
    // Call the first function and store its return value
    auto convertedPoint = func1();

    // Print the return values
    // std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "ECEF coordinates: (" << convertedPoint.x << ", " << convertedPoint.y << ", " << convertedPoint.z << ")" << std::endl;

    return convertedPoint;
}

// Declare example functions with different return types
int add(int a, int b);
double multiply(double a, double b);

#endif // CONVERT_H