#ifndef HERMITEMATRIX_H // Header guard to prevent multiple inclusion of the header file
#define HERMITEMATRIX_H

const int MATRIX_SIZE = 7; // Constant defining the size of the matrix

class HermiteMatrix // Declaration of the HermiteMatrix class
{
private:
    double hermite(int n, double x); // Private method to calculate Hermite polynomials

public:
    void printMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]);          // Public method to print a matrix
    void applyHermiteToMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]); // Public method to apply Hermite polynomials to a matrix
};

#endif // End of header guard
