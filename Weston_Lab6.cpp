
#include <iostream>
#include <fstream>
#include <iomanip> // For std::setw to align output

const int MAX_SIZE = 100;
//const int MAX_SIZE = vector<vector<int>> matrix;
   //matrix = vector<vector<int>>(n, vector<int>(n));
   // Adjust based on the maximum expected size of the matrix

// Function to read matrix from a file
void readMatrixFromFile(const std::string& filename, int matrix[][MAX_SIZE], int& size) {
   std::ifstream file(filename);
   if (!file) {
       std::cerr << "Error opening file: " << filename << std::endl;
       return;
   }
   file >> size;
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           file >> matrix[i][j];
       }
   }
   file.close();
}

// Function to print a matrix
void printMatrix(const int matrix[][MAX_SIZE], int size) {
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           std::cout << std::setw(5) << matrix[i][j] << " ";
       }
       std::cout << std::endl;
   }
}

// Function to add two matrices
void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int resultMatrix[][MAX_SIZE], int size) {
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
       }MAX_SIZE;
   }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int resultMatrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i][j] = 0; // Initialize the result cell to 0
            for (int k = 0; k < size; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract the second matrix from the first
void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int resultMatrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element in the matrix
void updateMatrixElement(int matrix[][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

// Function to find the maximum value in the matrix
int getMaxValue(const int matrix[][MAX_SIZE], int size) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    std::cout << maxValue;
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[][MAX_SIZE], int resultMatrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[j][i] = matrix[i][j];
        }
    }
}





int main() {
   int size;
   // vector<vector<int>> matrix;
   // matrix = vector<vector<int>>(n, vector<int>(n));
   int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];

   // Reading matrices from file
   readMatrixFromFile("matrix_input.txt", matrix1, size);
   readMatrixFromFile("matrix_input.txt", matrix2, size); // Assuming the same file is read twice for simplicity

   // Printing matrices
   std::cout << std::endl << "Matrix 1:" << std::endl;
   printMatrix(matrix1, size);
   std::cout << std::endl << "\n Matrix 2:" << std::endl;
   printMatrix(matrix2, size);

   // Printing the result of addMatrices
   addMatrices(matrix1, matrix2, resultMatrix, size);
   std::cout << std::endl << "\n Matrix Addition:" << std::endl;
   printMatrix(resultMatrix, size);

    // Printing the result of multiplyMatrices
   multiplyMatrices(matrix1, matrix2, resultMatrix, size);
   std::cout << std::endl << "\n Matrix Multiply:" << std::endl;
   printMatrix(resultMatrix, size);

    // Printing the result of subtractMatrices
   subtractMatrices(matrix1, matrix2, resultMatrix, size);
   std::cout << std::endl << "\n Matrix Subtraction:" << std::endl;
   printMatrix(resultMatrix, size);

    // Update an element in a Matrix
   updateMatrixElement(matrix1, size, 1, 1, 80);
   std::cout << std::endl << "\n Matrix Element Update: Replace value at position [1,1] with 80" << std::endl;
   printMatrix(matrix1, size);

    // Printing the maximum element of a matrix
   //getMaxValue(matrix1, size);
   std::cout << std::endl << "\n Matrix Maximum Element:" << std::endl;
   printf("\t");
   getMaxValue(matrix1, size);

    // Transpose a matrix
   transposeMatrix(matrix1, resultMatrix, size);
   std::cout << std::endl << "\n Matrix Transpose:" << std::endl;
   printMatrix(resultMatrix, size);
}