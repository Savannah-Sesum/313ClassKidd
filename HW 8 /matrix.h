#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h> // C libraries for memory manipulation and io control
#include <stdio.h>
typedef struct { // the matrix "class", typedef to mimic c++ class
    int m_rows;
    int m_cols;
    int** m_data;
} Matrix;
// Constructor
Matrix createMatrix(int rows, int cols);
// Destructor
void destroyMatrix(Matrix* theMatrix); // need one since i'm allocating memory manually
// Transpose
Matrix transpose(Matrix theMatrix);
// Matrix Addition
Matrix addMatrix(Matrix other1, Matrix other2);
// Matrix on Matrix multiplication
Matrix multiplyMatrix(Matrix other1, Matrix other2);
// Matrix Scalar Multiplication
Matrix scaleMatrix(Matrix theMatrix, int scalar);
// Printer
void printMatrix(Matrix theMatrix);
// For testing purposes
// Getter
int getData(Matrix theMatrix, int row, int col);
// Setter
void setData(Matrix* theMatrix, int row, int col, int value);
#endif
