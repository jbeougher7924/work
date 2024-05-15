#include "HermiteMatrix.h" // Include the header file where HermiteMatrix class is defined
#include <iostream>        // Include necessary libraries for input/output
#include <cmath>           // Include math library for pow() function

// Implementation of Hermite polynomial calculation
double HermiteMatrix::hermite(int n, double x)
{
    switch (n)
    {
    case 0:
        return 1.0; // H_0(x) = 1
    case 1:
        return 2.0 * x; // H_1(x) = 2x
    case 2:
        return 4.0 * pow(x, 2) - 2.0; // H_2(x) = 4x^2 - 2
    case 3:
        return 8.0 * pow(x, 3) - 12.0 * x; // H_3(x) = 8x^3 - 12x
    case 4:
        return 16.0 * pow(x, 4) - 48.0 * pow(x, 2) + 12.0; // H_4(x) = 16x^4 - 48x^2 + 12
    case 5:
        return 32.0 * pow(x, 5) - 160.0 * pow(x, 3) + 120.0 * x; // H_5(x) = 32x^5 - 160x^3 + 120x
    case 6:
        return 64.0 * pow(x, 6) - 480.0 * pow(x, 4) + 720.0 * pow(x, 2) - 120.0; // H_6(x) = 64x^6 - 480x^4 + 720x^2 - 120
    default:
        return 0.0; // For higher degrees, return 0 as Hermite polynomials beyond degree 6 are not implemented
    }
}

// Function to print a 2D matrix
void HermiteMatrix::printMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j] << "\t"; // Output matrix element followed by a tab
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }
}

// Function to apply Hermite polynomials to each element of a matrix and print the results
void HermiteMatrix::applyHermiteToMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    std::cout << "\nApplying Hermite polynomials to the matrix:" << std::endl; // Print a header message
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            double x = matrix[i][j];                                               // Get the current element of the matrix
            std::cout << "H_" << i << "(" << x << ") = " << hermite(i, x) << "\t"; // Print Hermite polynomial applied to the element
        }
        std::cout << std::endl; // Move to the next line after printing all elements in a row
    }
}
