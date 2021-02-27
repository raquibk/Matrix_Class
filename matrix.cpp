/*
Name: Raquib Khan Lavani
ID: 1622108
Weekly Exercise #4: Matrix Class
CMPUT 275, Winter 2021
*/

// Header files
#include <iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(size_t num_rows, size_t num_columns, float init) {
    // Initiating variables specific to instance
    this->num_rows = num_rows;
    this->num_columns = num_columns;
    this->init = init;
    // Declaring matrix to be a pointer to a pointer array
    matrix = new float*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        // Declaring each element of matrix to be an array
        matrix[i] = new float[num_columns];
        for (int j = 0; j < num_columns; j++) {
            // Setting each element of each array to be init
            matrix[i][j] = init;
        }
    }
}

Matrix::Matrix(size_t num_rows, size_t num_columns, float * arr_ptr) {
    // Initiating variables specific to instance
    this->num_rows = num_rows;
    this->num_columns = num_columns;
    // Declaring matrix to be a pointer to a pointer array
    matrix = new float*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new float[num_columns];
        for (int j = 0; j < num_columns; j++) {
            // Setting elements of each array to data stored
            matrix[i][j] = *arr_ptr;
            arr_ptr++;
        }
    }
}

Matrix::Matrix(const Matrix &mat) {
    // Initiating variables specific to instance
    this->num_rows = mat.num_rows;
    this->num_columns = mat.num_columns;
    // Declaring matrix to be a pointer to a pointer array
    matrix = new float*[num_rows];

    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new float[num_columns];
        for (int j = 0; j < num_columns; j++) {
            // Setting each element of the new matrix to the passed in matrix
            matrix[i][j] = mat.matrix[i][j];
        }
    }
}

int Matrix::get_rows() const {
    // Return number of rows
    return num_rows;
}

int Matrix::get_cols() const {
    // Return number of columns
    return num_columns;
}

float** Matrix::get_matrix() {
    // Return 2D private array
    return matrix;
}

Matrix Matrix::operator+ (const Matrix rhs) {
    // Declaring matrix to hold added values
    Matrix sum =  Matrix(num_rows, num_columns, 0.0);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            // Add elements of current instance and passed in instance
            sum.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    // Return matrix with summed values
    return sum;
}

Matrix Matrix::operator- (const Matrix rhs) {
    // Declaring matrix to hold subtracted values
    Matrix difference = Matrix(num_rows, num_columns, 0.0);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            // Subtract elements of current instance and passed in instance
            difference.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        }
    }
    // Return matrix with subtracted values
    return difference;
}

Matrix Matrix::operator* (const Matrix rhs) {
    // Declaring matrix to hold multiplied values
    Matrix multiplied = Matrix(num_rows, rhs.num_columns, 1.0);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < rhs.num_columns; j++) {
            // Declaring temporary variable
            float tempnum = 0;
            for (int k = 0; k < num_columns; k++) {
                // Multiply row wise for first matrix, columnwise
                // for second matrix and assign summed value to tempnum
                tempnum += matrix[i][k] * rhs.matrix[k][j];
            }

            // Set value of multiplied matrix to tempnum
            multiplied.matrix[i][j] = tempnum;
        }
    }
    // Return matrix with multiplied values
    return multiplied;
}

Matrix Matrix::operator- ()  {
    // Declaring matrix to hold negated values
    Matrix negated = Matrix(num_rows, num_columns, 0.0);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            // Negate values of passed in matrix
            negated.matrix[i][j] = -1 * matrix[i][j];
        }
    }

    // Return matrix with negated values
    return negated;
}

Matrix Matrix::transpose() {
    // Declaring matrix to hold transposed values
    Matrix transposed = Matrix(num_columns, num_rows, 0.0);
    for (int i = 0; i  < num_columns; i++) {
        for (int j = 0; j < num_rows; j++) {
            // Switch rows and columns, and store values in transposed matrix
            transposed.matrix[i][j] = matrix[j][i];
        }
    }
    // Return transposed matrix
    return transposed;
}

Matrix Matrix::submatrix(size_t row_start, size_t row_end, size_t column_start, size_t column_end) {
    // Define new dimensions for the submatrix
    int new_rows = row_end - row_start;
    int new_cols = column_end - column_start;

    // Declare a matrix with the new dimensions
    Matrix submat = Matrix(new_rows, new_cols, 0.0);

    // Assigning each element of submatrix
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            // Element of submatrix is equal to the element of matrix
            // which is located at i + row_start and j + column_start
            submat.matrix[i][j] = matrix[i+row_start][j+column_start];
        }
    }
    // Return submatrix
    return submat;
}


float* Matrix::operator[](int i) {
    // Return pointer to a row
    return matrix[i];
}

const float* Matrix::operator[](int i) const {
    // Const version
    // Return pointer to a row
    return matrix[i];
}

ostream& operator<<(ostream& out, Matrix mat) {
    for (int i = 0; i < mat.get_rows(); i++) {
        for (int j = 0; j < mat.get_cols(); j++) {
            // Print out the matrix elements with a space in between
            // If the end of a column is reached, go to a newline
            out << mat.get_matrix()[i][j] <<  " \n"[j == mat.get_cols()-1];
        }
    }
    // Print a blank line
    cout << endl;
    return out;
}

istream& operator>>(istream& in, Matrix &mat) {
    for (int i = 0; i < mat.get_rows(); i++) {
        for (int j = 0; j < mat.get_cols(); j++) {
            // Input and assign each element of matrix
            in >> mat.get_matrix()[i][j];
        }
    }

    return in;
}

Matrix::~Matrix() {
    for (int i = 0; i < num_rows; i++) {
        // Deallocate memory of each element of matrix array
        delete [] matrix[i];
        // Point all arrays within matrix to NULL
        matrix[i] = NULL;
    }

    // Deallocate memory for 2D matrix array
    delete [] matrix;
}
