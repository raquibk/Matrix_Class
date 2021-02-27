/*
Name: Raquib Khan Lavani
ID: 1622108
Weekly Exercise #4: Matrix Class
CMPUT 275, Winter 2021
*/

// Header files
#include <iostream>
using namespace std;
#ifndef _MATRIX_
#define _MATRIX_

/*
A class for the implementation of a Matrix data structure
A matrix is a rectangular array of numbers, symbols, or expressions, 
arranged in rows or columns.
This class comprises of the following methods

Public Methods:

Matrix(size_t num_rows, size_t num_columns, float init)
Matrix(size_t num_rows, size_t num_columns, float * arr_ptr)
Matrix (const Matrix &mat)
int get_rows() const
int get_cols() const
float** get_matrix()
Matrix operator+(const Matrix rhs)
Matrix operator-(const Matrix rhs)
Matrix operator*(const Matrix rhs)
Matrix operator-()
float* operator [](int i)
float* operator [](int i) const
Matrix transpose()
Matrix submatrix(size_t row_start, size_t row_end, size_t column_start, size_t column_end)
~Matrix()

Private Methods:

None



*/
class Matrix {
public:

    /*
    Constructor: Initializes a matrix object with matrix
    elements initialized to 'init'

    Arguments: num_rows - Number of rows of Matrix object
               num_columns - Number of columns of Matrix object
               init - value stored as each element of matrix

    Returns: None
    */
    Matrix(size_t num_rows, size_t num_columns, float init);


    /*
    Constructor: Initializes a matrix object with the matrix 
    elements initialized using the data stored in a one-dimensional
    array, which is pointed to by arr_ptr

    Arguments: num_rows - Number of rows of Matrix object
               num_columns - Number of columns of Matrix object
               arr_ptr - array with num_rows*num_columns elements

    Returns: None
    */
    Matrix(size_t num_rows, size_t num_columns, float * arr_ptr);

    /* 
    Copy constructor: Constructs a new instance of Matrix class which
    is a deep copy of the matrix instance passed in

    Arguments: const Matrix &mat - Reference to the matrix instance which
                                   is to be copied

    Returns: None
    */
    Matrix (const Matrix &mat);

    /*
    Definition: Getter of rows for non-member functions

    Arguments: none

    Returns: num_rows - Number of rows of (private) 2D array
    */
    int get_rows() const;

    /*
    Definition: Getter for columns non-member functions

    Arguments: none

    Returns: num_columns - Number of columns of (private) 2D array
    */
    int get_cols() const;

    /*
    Definition: Getter for privated 2D array matrix for
    non member functions

    Arguments: none

    Returns: matrix - (private) 2D array which internally represents
                      the matrix
    */
    float** get_matrix();

    /*
    Matrix Addition Operator Overloading: Adds the elements of the
    two instances of Matrix class (The current instance and another
    instance)

    Arguments: const Matrix rhs - The other Matrix instance 

    Returns: sum - A new instance of Matrix class which has the added elements
    */
    Matrix operator+(const Matrix rhs);

    /*
    Matrix Addition Operator Overloading: Subtracts the elements of the
    two instances of Matrix class (The current instance and another
    instance)

    Arguments: const Matrix rhs - The other Matrix instance 

    Returns: difference - A new instance of Matrix class which has the subtracted elements
    */
    Matrix operator-(const Matrix rhs);

    /*
    Matrix Multiplication Operator Overloading: Multiplies the elements
    of the current instance and another instance of Matrix class

    Arguments: const Matrix rhs - The other Matrix instance 

    Returns: multiplied - A new instance of Matrix class which has the multiplied elements
    */
    Matrix operator*(const Matrix rhs);

    /*
    Unary negation Operator Overloading: Negates each element of the
    current instance

    Arguments: none 

    Returns: negated - A new instance of Matrix class which has the negated elements
    */
    Matrix operator-();

    /*
    Bracket Operator Overloading (non const): Returns the row of a matrix as a float
    pointer.

    Arguments: int i: Index of row to be returned 

    Returns: matrix[i] - Pointer to row of a private 2D array which internally represents
                         the matrix
    */
    float* operator [](int i);

    /*
    Bracket Operator Overloading (const): Returns the row of a const matrix as a float
    pointer.

    Arguments: int i: Index of row to be returned 

    Returns: matrix[i] - Pointer to row of a private 2D array which internally represents
                         the matrix
    */
    const float* operator[](int i) const;

    /*
    Definition: Turns an instance's rows into columns, and columns into rows

    Arguments: None

    Returns: transposed - A new instance of Matrix class which has the transposed
                          matrix
    */
    Matrix transpose();

    /*
    Definition: Getter for non-member functions

    Arguments: none

    Returns: Number of rows of (private) 2D array
    */
    Matrix submatrix(size_t row_start, size_t row_end, size_t column_start, size_t column_end);

    /*
    Destructor: Deallocates memory used to store the internal 
    2 D array, and references the pointers stored within to NULL

    Arguments: none

    Returns: none
    */
    ~Matrix();

private:
    // Declaring pointer to pointer which will be used to internally
    // represent matrix
    float **matrix;
    // Declaring value which will be used to inialize all elements of
    // the matrix, if that specific constructor is called
    float init;
    // Number of rows of matrix
    int num_rows;
    // Number of columns of matrix
    int num_columns;
}; 

/*
Insertion operator overloading: Prints all elements of matrix row by row

Arguments: ostream& out - Reference to output
           mat - Matrix instance to be printed

Returns: out - Output
*/
ostream& operator<<(ostream& out,Matrix mat);

/*
Extraction operator overloading: Reads num_rows*num_columns space seperated
elements from the input stream, and populates the elements of the matrix row
by row.

Arguments: istream& in - Reference to input
           &mat - Reference to Matrix instance to be printed

Returns: in - Input
*/
istream& operator>>(istream& in, Matrix &mat);
#endif