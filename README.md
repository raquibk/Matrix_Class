Running Instructions: Simply run the command line argument 'make' to compile the final executable.
                      Please ensure that main.cpp, matrix.cpp, and matrix.h are in the same directory.
                      Then, run the program by typing ./we4_solution

Files included: <p> - README </p>
                <p> - matrix.h: This is a header file which contains all the declarations, and the
                             operator overloading of the class Matrix(). </p>
                <p> - matrix.cpp: This file contains the body of all the methods, operator overloading
                               of class Matrix() declared in matrix.h </p>
                <p> - Makefile: This Makefile compiles matrix.h, matrix.cpp into one single object file
                             namely matrix.o </p>

Targets of Makefile- 1. we4_solution: The final executable
                     2. clean: Cleans (removes) all object files created

Notes and Assumptions:
'matrix.cpp' is a program which defines a new data structure, called Matrix. A Matrix mathematically has
'n' rows, and 'm' columns and has n*m elements in it. Several mathematical and computational
operations can be applied to the matrix class, including:
- Matrix Addition
- Matrix Subtraction
- Matrix Multiplication
- Unary Negation
- Matrix Transposition 
- Getting a Submatrix 
- Bracket Operator
- ostream Insertion Operator
- istream Extraction Operator

The operators/methods assume the following:
Addition, Subtraction: They assume that the 2 Matrices being added have the EXACT same dimensions
Multiplication: It assumes that the first matrix has dimensions (n,m) and second matrix has dimensions
                (m, k).
Submatrix: It assumes that row_start, row_end <= num_rows+1 and column_start, column_end <= num_cols +1
