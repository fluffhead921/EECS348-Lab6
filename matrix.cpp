#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    fstream inputFile;
    string currLine;
    int size;

    //get file name and open
    printf("Enter matrix file name: ");
    cin >> fileName;
    inputFile.open(fileName);

    //get matrix size from first line of file
    getline(inputFile, currLine);
    size = stoi(currLine);

    printf("Matrix Size: %d", size);

    inputFile.close();
}