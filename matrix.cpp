#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string currLine;
fstream inputFile;

int** readMatrix(int matrixSize) {
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
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return matrix;
}

int main() {
    string fileName;
    int size;
    int **matrix1;
    int **matrix2;

    //get file name and open
    printf("Enter matrix file name: ");
    cin >> fileName;
    inputFile.open(fileName);

    //get matrix size from first line of file
    getline(inputFile, currLine);
    size = stoi(currLine);

    printf("Matrix Size: %d\n", size);
    matrix1 = readMatrix(size);
    printf("\n");
    matrix2 = readMatrix(size);

    inputFile.close();
}