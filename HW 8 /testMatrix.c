#include "matrix.h"
// Constructor
Matrix createMatrix(int rows, int cols) {
    Matrix temp;
    temp.m_rows = rows;
    temp.m_cols = cols;
    temp.m_data = (int**) malloc(rows * sizeof(int*)); // creating an abstract 2d matrix full of memory
    for (int i = 0; i < rows; i++) {
        temp.m_data[i] = (int *) malloc(cols * sizeof(int)); // allocating memory into col instead of row
    }
    return temp;
}
// Destructor
void destroyMatrix(Matrix *temp) {
    for (int i = 0; i < temp->m_rows; i++) { // freeing memory within the 2d matrix
        free(temp->m_data[i]);
    }
    free(temp->m_data); // free memory from the abstract 2d matrix
    temp->m_data = NULL;
}
// Transposer
Matrix transpose(Matrix temp) {
    Matrix result = createMatrix(temp.m_cols, temp.m_rows); // swapped rows and cols
    for (int i = 0; i < temp.m_rows; i++) {
        for (int j = 0; j < temp.m_cols; j++) {
            result.m_data[j][i] = temp.m_data[i][j]; // swapping the data
        }
    }
    return result;
}

Matrix addMatrix(Matrix other1, Matrix other2) {
    if (other1.m_rows != other2.m_rows || other1.m_cols != other2.m_cols) { // if trying to add 2 matrices of different mxn
        printf("These 2 matrices can't be added together because they're not the same mxn\n" );
        exit(1);
    }
    Matrix result = createMatrix(other1.m_rows, other1.m_cols);
    for (int i = 0; i < other1.m_rows; i++) {
        for (int j = 0; j < other1.m_cols; j++) {
            result.m_data[i][j] = other1.m_data[i][j] + other2.m_data[i][j]; // add the 2 matrix together into result
        }
    }
    return result;
}

Matrix multiplyMatrix(Matrix other1, Matrix other2) {
    Matrix result = createMatrix(other1.m_rows, other2.m_cols); // new matrix that's the product with mxp size
    if (other1.m_cols != other2.m_rows) { // if trying to multiply 2 matrices that aren't mxn and nxp
        printf("\"These 2 matrices can't be multiplied together because it's not by mxn and nxp\n");
        exit(0);
    }
    for (int i = 0; i < other2.m_cols; i++) { // loop through the cols of matrix C (in the formula)
        for (int j = 0; j < other1.m_rows; j++) { // loop through the rows of matrix B
            int product = 0;
            for (int k = 0; k < other1.m_cols; k++) { // loop through the cols of matrix B + rows of matrix C
                product += other1.m_data[j][k] * other2.m_data[k][i];
            }
            result.m_data[j][i] = product;
        }
    }
    return result;
}

Matrix scaleMatrix(Matrix theMatrix, int scalar) {
    Matrix result = createMatrix(theMatrix.m_rows, theMatrix.m_cols); // new matrix that's the product
    for (int i = 0; i < theMatrix.m_rows; i++) {
        for (int j = 0; j < theMatrix.m_cols; j++) {
            result.m_data[i][j] = theMatrix.m_data[i][j] * scalar;  // scale with scalar
        }
    }
    return result;
}

void printMatrix(Matrix theMatrix) {
    for (int i = 0; i < theMatrix.m_rows; i++) {
        for (int j = 0; j < theMatrix.m_cols; j++) {
            printf("%d ", theMatrix.m_data[i][j]);
        }
        printf("\n");
    }
}
// Testing Purposes
// Getter
int getData(Matrix m, int row, int col) {
    return m.m_data[row][col];
}
// Setter
void setData(Matrix* m, int row, int col, int value) {
    m->m_data[row][col] = value;
}
int main() {
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
    printf("How many Rows and Cols for matrix A? "); // let user define dimensions
    scanf("%d %d", &rowsA, &colsA);
    while (rowsA == 0 || colsA == 0) { // so no invalid matrix can be made
        printf("That is invalid. How many Rows and Cols for matrix A? ");
        scanf("%d %d", &rowsA, &colsA);
    }
    Matrix A = createMatrix(rowsA, colsA);
    int i = 0;
    while (i < rowsA) { // let user define values
        int j = 0;
        while (j < colsA) {
            int value;
            printf("What do you want at Row %d and Col %d? ", i + 1, j + 1);
            scanf("%d", &value);
            setData(&A, i, j, value);
            j++;
        }
        i++;
    }
    printf("----This is A----\n");
    printMatrix(A);

    printf("How many Rows and Cols for matrix B? "); // let user define dimensions
    scanf("%d %d", &rowsB, &colsB);
    while (rowsB == 0 || colsB == 0) { // so no invalid matrix can be made
        printf("That is invalid. How many Rows and Cols for matrix B? ");
        scanf("%d %d", &rowsB, &colsB);
    }
    Matrix B = createMatrix(rowsB, colsB); // let user define values
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            int value;
            printf("What do you want at Row %d and Col %d? ", i + 1, j + 1);
            scanf("%d", &value);
            setData(&B, i, j, value);
        }
    }
    printf("----This is B----\n");
    printMatrix(B);

    printf("How many Rows and Cols for matrix C? "); // let user define dimension
    scanf("%d %d", &rowsC, &colsC);
    while (rowsC == 0 || colsC == 0) { // so no invalid matrix can be made
        printf("That is invalid. How many Rows and Cols for matrix C? ");
        scanf("%d %d", &rowsC, &colsC);
    }
    Matrix C = createMatrix(rowsC, colsC);
    for (int i = 0; i < rowsC; i++) { // let user define values
        for (int j = 0; j < colsC; j++) {
            int value;
            printf("What do you want at Row %d and Col %d? ", i + 1, j + 1);
            scanf("%d", &value);
            setData(&C, i, j, value);
        }
    }
    printf("----This is C----\n");
    printMatrix(C);

    printf("----Now doing the formula of A + (3 * B) * C^T----\n");

    printf("\t1) 3 * B\n");
    Matrix B3 = scaleMatrix(B, 3);
    printMatrix(B3);

    printf("\t2) C^T\n");
    Matrix CT = transpose(C);
    printMatrix(CT);

    printf("\t3) B * C\n");
    Matrix BC = multiplyMatrix(B3, CT);
    printMatrix(BC);

    printf("\t4) Final Result is: A + (B*C)\n");
    Matrix finalMatrix = addMatrix(A, BC);
    printMatrix(finalMatrix);

    destroyMatrix(&A); // cleaning all matrices
    destroyMatrix(&B);
    destroyMatrix(&C);
    destroyMatrix(&B3);
    destroyMatrix(&CT);
    destroyMatrix(&BC);
    destroyMatrix(&finalMatrix);
    return 0;
}
