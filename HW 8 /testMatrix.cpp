#include "matrix.hpp"
// Constructor
Matrix::Matrix(int rows, int cols) {
    m_cols = cols;
    m_rows = rows;
    m_data = vector<vector<int>>(rows, vector<int>(cols,0));
}
// Transposer
Matrix Matrix::transpose() const {
    Matrix result(m_cols,m_rows); // swapped rows and cols
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.m_data[j][i] = m_data[i][j]; // swapping the data
        }
    }
    return result;
}
// 4 below are overloaded operators
// Matrix Addition
Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    Matrix result(m_rows,m_cols); // new matrix that's the sum
    if (m_rows != otherMatrix.m_rows or m_cols != otherMatrix.m_cols) { // if trying to add 2 matrices of different mxn
        cout << "These 2 matrices can't be added together because they're not the same mxn" << endl;
        exit(0);
    }
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.m_data[i][j] = otherMatrix.m_data[i][j] + m_data[i][j]; // add the 2 matrix together into result
        }
    }
    return result;
}
// Matrix on Matrix Multiplication
Matrix Matrix::operator*(const Matrix& otherMatrix) const {
    Matrix result(m_rows,otherMatrix.m_cols); // new matrix that's the product with mxp size
    if (m_cols != otherMatrix.m_rows) { // if trying to multiply 2 matrices that aren't mxn and nxp
        cout << "These 2 matrices can't be multiplied together because it's not by mxn and nxp" << endl;
        exit(0);
    }
    for (int i = 0; i < otherMatrix.m_cols; i++) { // loop through the cols of matrix C (in the formula)
        for (int j = 0; j < m_rows; j++) { // loop through the rows of matrix B
            int product = 0;
            for (int k = 0; k < m_cols; k++) { // loop through the cols of matrix B + rows of matrix C
                product += m_data[j][k]* otherMatrix.m_data[k][i];
            }
            result.m_data[j][i] = product;
        }
    }
    return result;
}
// Matrix Scalar Multiplication (when scalar on right)
Matrix Matrix::operator*(int scalar) {
    Matrix result(m_rows,m_cols); // new matrix that's the product
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.m_data[i][j] = m_data[i][j] * scalar; // scale with scalar
        }
    }
    return result;
}
// Printer
void Matrix::print() const {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << m_data[i][j] << " ";
        }
        cout << endl;
    }
}
// Testing Purposes
// Getter
int Matrix::getData(int rows, int cols) const {
    return m_data[rows][cols];
}
// Setter
void Matrix::setData(int rows, int cols, int value) {
    m_data[rows][cols] = value;
    return;
}
// Friend - Matrix Scalar Multiplication (when scalar on left)
Matrix operator*(int scalar, const Matrix &otherMatrix) {
    Matrix result(otherMatrix.m_rows,otherMatrix.m_cols); // new matrix that's the product
    for (int i = 0; i < otherMatrix.m_rows; i++) {
        for (int j = 0; j < otherMatrix.m_cols; j++) {
            result.m_data[i][j] = otherMatrix.m_data[i][j] * scalar; // scale with scalar
        }
    }
    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
    cout << "How many Rows and Cols for matrix A? "; // let user define dimensions
    cin >> rowsA >> colsA;
    while (rowsA == 0 or colsA == 0) { // so no invalid matrix can be made
        cout << "That is invalid. How many Rows and Cols for matrix A? ";
        cin >> rowsA >> colsA;
    }
    Matrix A(rowsA,colsA);
    int i = 0;
    while (i < rowsA) { // let user define values
        int j = 0;
        while (j < colsA) {
            int value;
            cout << "What do you want at Row " << i + 1 << " and Col " << j + 1 << "? ";
            cin >> value;
            A.setData(i, j, value);
            j++;
        }
        i++;
    }
    cout << "----This is A----" << endl;
    A.print();

    cout << "How many Rows and Cols for matrix B? "; // let user define dimensions
    cin >> rowsB >> colsB;
    while (rowsB == 0 or colsB == 0) { // so no invalid matrix can be made
        cout << "That is invalid. How many Rows and Cols for matrix B? ";
        cin >> rowsB >> colsB;
    }
    Matrix B(rowsB,colsB);
    i = 0; // reset
    while (i < rowsB) { // let user define values
        int j = 0;
        while (j < colsB) {
            int value;
            cout << "What do you want at Cow " << i + 1 << " and Col " << j + 1 << "? ";
            cin >> value;
            B.setData(i, j, value);
            j++;
        }
        i++;
    }
    cout << "----This is B----" << endl;
    B.print();

    cout << "How many Rows and Cols for matrix C? "; // let user define dimensions
    cin >> rowsC >> colsC;
    while (rowsC == 0 or colsC == 0) { // so no invalid matrix can be made
        cout << "That is invalid. How many Rows and Cols for matrix C? ";
        cin >> rowsC >> colsC;
    }
    Matrix cTranspose(rowsC, colsC);
    i = 0; // reset
    while (i < rowsC) { // let user define values
        int j = 0;
        while (j < colsC) {
            int value;
            cout << "What do you want at Row " << i + 1 << " and Col " << j + 1 << "? ";
            cin >> value;
            cTranspose.setData(i, j, value);
            j++;
        }
        i++;
    }
    cout << "----This is C----" << endl;
    cTranspose.print();

    cout << "----Now doing the formula of A + (3 * B) * C^T----" << endl;
    cout << "\t 1) 3 * B" << endl;
    Matrix B2 = B;
    Matrix B3 = 3 * B;
    B3.print();
    cout << "\t 1.5) B * 3, this is to only demonstrate right scalar multiplication" << endl;
    Matrix D = B2 * 3;
    D.print();
    cout << "\t 2) C^T" << endl;
    cTranspose = cTranspose.transpose();
    cTranspose.print();
    cout << "\t 3) B * C" << endl;
    Matrix BC = B3 * cTranspose;
    BC.print();
    cout << "\t 4) Final Result is: A + (B*C)" << endl;
    Matrix finalMatrix = A + BC;
    finalMatrix.print();
    return 0;
}
