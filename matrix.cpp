#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string currLine;
fstream inputFile;
int matrixSize;

int** readMatrix() {
    //initialize matrix
    int **matrix;
    matrix = new int *[matrixSize];
    for(int i = 0; i < matrixSize; i++) {
        matrix[i] = new int[matrixSize];
    }

    //add values from file
    for (int i = 0; i < matrixSize; i++) {
        getline(inputFile, currLine);
        stringstream stream(currLine);
        string element;
        for (int j = 0; j < matrixSize; j++) {
            getline(stream, element, ' ');
            matrix[i][j] = stoi(element);
        }
    }
    return matrix;
}

void printMatrix(int **matrix) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** addMatrices(int **matrixA, int **matrixB) {
    //initialize matrixC
    int **matrixC;
    matrixC = new int *[matrixSize];
    for(int i = 0; i < matrixSize; i++) {
        matrixC[i] = new int[matrixSize];
    }

    //perform matrix addition
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return matrixC;
}

int** multMatrices(int **matrixA, int **matrixB) {
    //initialize matrixC
    int **matrixC;
    matrixC = new int *[matrixSize];
    for(int i = 0; i < matrixSize; i++) {
        matrixC[i] = new int[matrixSize];
    }

    //perform matrix multiplication
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < matrixSize; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return matrixC;
}

int** subMatrices(int **matrixA, int **matrixB) {
    //initialize matrixC
    int **matrixC;
    matrixC = new int *[matrixSize];
    for(int i = 0; i < matrixSize; i++) {
        matrixC[i] = new int[matrixSize];
    }

    //perform matrix addition
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return matrixC;
}

void updateMatrix(int **matrix) {
    int row = matrixSize;
    int col = matrixSize;
    int val;
    string input;

    //ensure valid row
    while (!(row < matrixSize && row >= 0)) {
        printf("Enter a row number (1 to %d): ", matrixSize);
        cin >> input;
        try {
            row = stoi(input) - 1;
            if (!(row < matrixSize && row >= 0)) {
                throw (row);
            }
        }
        catch (int num) {
            printf("%d is not in allowed range\n", num);
        }
        catch (invalid_argument) {
            printf("Row number must be an integer\n");
        }
    }

    //ensure valid column
    while (!(col < matrixSize && col >= 0)) {
        printf("Enter a column number (1 to %d): ", matrixSize);
        cin >> input;
        try {
            col = stoi(input) - 1;
            if (!(col < matrixSize && col >= 0)) {
                throw (col);
            }
        }
        catch (int num) {
            printf("%d is not in allowed range\n", num);
        }
        catch (invalid_argument) {
            printf("Column number must be an integer\n");
        }
    }

    //ensure valid replacement value
    while (1) {
        printf("Enter the replacement value: ");
        cin >> input;
        try {
            val = stoi(input);
            break;
        }
        catch (invalid_argument) {
            printf("Value must be an integer\n");
        }
    }

    //update value
    matrix[row][col] = val;
}

int maxValue(int **matrix) {
    //initialize maximum to element 00
    int max = matrix[0][0];

    //update max
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    return max;
}

int main() {
    string fileName;
    int **matrix1;
    int **matrix2;
    int **matrix3;

    //get file name and open
    printf("Enter matrix file name: ");
    cin >> fileName;
    inputFile.open(fileName);

    //get matrix size from first line of file
    getline(inputFile, currLine);
    matrixSize = stoi(currLine);

    printf("\nMatrix Size: %d\n\n", matrixSize);

    //store two matrices
    matrix1 = readMatrix();
    matrix2 = readMatrix();

    inputFile.close();

    //print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);

    //add matrices
    matrix3 = addMatrices(matrix1, matrix2);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(matrix3);

    //multiply matrices
    matrix3 = multMatrices(matrix1, matrix2);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(matrix3);

    //subtract matrices
    matrix3 = subMatrices(matrix1, matrix2);
    printf("Matrix 1 - Matrix 2:\n");
    printMatrix(matrix3);

    //update matrix
    printf("Update a value in Matrix 1\n");
    updateMatrix(matrix1);
    printf("\nUpdated Matrix 1:\n");
    printMatrix(matrix1);

    //find maximum
    printf("Max value in Matrix 1: %d\n\n", maxValue(matrix1));
}