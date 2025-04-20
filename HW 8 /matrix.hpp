#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include <iostream>
using namespace std;

class Matrix {
public:
    // Constructor
    Matrix(int rows, int cols);
    // Transposer
    Matrix transpose() const;
    // 4 below are overloaded operators
    // Matrix Addition
    Matrix operator+(const Matrix &otherMatrix) const;
    // Matrix on Matrix Multiplication
    Matrix operator*(const Matrix &otherMatrix) const;
    // Friend - Matrix Scalar Multiplication (when scalar on left)
    friend Matrix operator*(int scalar, const Matrix &otherMatrix);
    // Matrix Scalar Multiplication (when scalar on right)
    Matrix operator*(int scalar);
    // Printer
    void print() const;
    // For testing purposes
    // Setter
    void setData(int rows, int cols, int value);
private:
    vector<vector<int>> m_data; // The Matrix
    int m_rows;
    int m_cols;
};
#endif
