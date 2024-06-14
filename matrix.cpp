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
}

int main() {
    string fileName;
    int **matrix1;
    int **matrix2;

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
    printMatrix(matrix1);
    printf("\n");
    printMatrix(matrix2);
}