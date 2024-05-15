#include "HermiteMatrix.h" // Include the header file for HermiteMatrix
#include <cstdlib>         // Include the necessary headers for rand() and srand()
#include <iostream>

extern const int MATRIX_SIZE; // Declare MATRIX_SIZE from HermiteMatrix.h

int main()
{
    srand(time(0)); // Seed the random number generator using the current time

    double matrix[MATRIX_SIZE][MATRIX_SIZE]; // Declare a matrix of size MATRIX_SIZE x MATRIX_SIZE

    // Fill the matrix with random values
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX; // Generate a random value between 0 and 1 and store it in the matrix
        }
    }

    std::cout << "Random Matrix:" << std::endl; // Output a message indicating the random matrix is being printed

    HermiteMatrix hm;       // Create an instance of the HermiteMatrix class
    hm.printMatrix(matrix); // Call the printMatrix method of HermiteMatrix to print the matrix

    hm.applyHermiteToMatrix(matrix); // Apply Hermite polynomials to the matrix and print the results

    return 0; // Return 0 to indicate successful execution of the program
}
