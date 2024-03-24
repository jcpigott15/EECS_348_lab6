#include <iostream>
#include <fstream>
#include <iomanip>

const int MATRIX_SIZE_MAX = 10; //setting max size for the matricies

//declaring function prototypes
void readMatrixFromFile(int matrix[][MATRIX_SIZE_MAX], int& size, const std::string& filename);
void printMatrix(const int matrix[][MATRIX_SIZE_MAX], int size);
void addMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size);
void multiplyMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size);
void subtractMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size);
void updateMatrixElement(int matrix[][MATRIX_SIZE_MAX], int row, int col, int newValue, int size);
int getMaxValue(const int matrix[][MATRIX_SIZE_MAX], int size);
void transposeMatrix(const int matrix[][MATRIX_SIZE_MAX], int size);

int main() {
    int matrix1[MATRIX_SIZE_MAX][MATRIX_SIZE_MAX], matrix2[MATRIX_SIZE_MAX][MATRIX_SIZE_MAX];
    int result[MATRIX_SIZE_MAX][MATRIX_SIZE_MAX], size;

    //reading matricies from input file
    readMatrixFromFile(matrix1, size, "matrix_input.txt");
    readMatrixFromFile(matrix2, size, "matrix_input.txt");

    std::cout << "Matrix 1:\n";
    printMatrix(matrix1, size);   //prints matrix 1
    std::cout << std::endl;

    std::cout << "Matrix 2:\n";
    printMatrix(matrix2, size);    //prints matrix 2
    std::cout << std::endl;

    
    addMatrices(matrix1, matrix2, result, size);  //adding the matricies
    std::cout << "Matrix 1 + Matrix 2:\n";
    printMatrix(result, size);
    std::cout << std::endl;

    
    multiplyMatrices(matrix1, matrix2, result, size);  //multiplying the matricies
    std::cout << "Matrix 1 * Matrix 2:\n";
    printMatrix(result, size);
    std::cout << std::endl;


    subtractMatrices(matrix1, matrix2, result, size);  //subtracting the matricies
    std::cout << "Matrix 1 - Matrix 2:\n";
    printMatrix(result, size);
    std::cout << std::endl;


    updateMatrixElement(matrix1, 0, 0, 100, size);   //updates elements in each matrix slot
    std::cout << "Matrix 1 after updating element:\n";
    printMatrix(matrix1, size);
    std::cout << std::endl;

    
    std::cout << "Max value of Matrix 1: " << getMaxValue(matrix1, size) << std::endl;  //gets max value from matrix 1
    std::cout << std::endl;

    
    std::cout << "Transpose of Matrix 1:\n";  //transposes matrix 1
    transposeMatrix(matrix1, size);

    return 0;
}

//function that reads matrix in from file
void readMatrixFromFile(int matrix[][MATRIX_SIZE_MAX], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    file >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
}

//print matrix function
void printMatrix(const int matrix[][MATRIX_SIZE_MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

//matrix addition
void addMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//matrix multiplication
void multiplyMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size) {

}

//matrix subtraction
void subtractMatrices(const int matrix1[][MATRIX_SIZE_MAX], const int matrix2[][MATRIX_SIZE_MAX], int result[][MATRIX_SIZE_MAX], int size) {

}

//function that updates each element in the matrix
void updateMatrixElement(int matrix[][MATRIX_SIZE_MAX], int row, int col, int newValue, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

//function that finds the max value in the matrix
int getMaxValue(const int matrix[][MATRIX_SIZE_MAX], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[][MATRIX_SIZE_MAX], int size) {
    // Transposition logic
}
