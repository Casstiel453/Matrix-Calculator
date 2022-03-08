#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;


/** The structure of the matrix 
@param rows number of rows in matrix
@param columns number of columns in matrix
@param arrData pointer to a pointer to a double (to the array of doubles)
*/
struct matrixStruct
{
    int rows;
    int columns;
    double** arrData;
};


/** The function writes matrix to the output file
@param matrix pointer to the structure of matrix 
@param file_result reference to the output file
*/
void writeToFile(matrixStruct* matrix, ofstream& file_result);


/** The function creates new array
@param matrixRowsint number of rows in array
@param matrixColumnsint number of columns in array
*/
double** createNewArray(int matrixRowsint, int matrixColumnsint);


/** The function cleares memory
@param arrTemp pointer to a pointer to a double (to the array of doubles) readed from input file
@param matrixRowsint number of rows in array
*/
void clearMemory(double** arrTemp, int matrixRowsint);


/** The function contains menu of the program
*/
void intro();


/** The function read matrix from input file, check if the inside of file is correctly prepared and return pointer to a pointer to an integer (to the integer array) readed from file
@param file reference to the file
@param matrixRowsint reference to the number of rows in array
@param matrixColumnsint reference to the number of columns in array
*/
double** readMatrixInputFile(ifstream& file, int& matrixRowsint, int& matrixColumnsint);


/** The function allows to perform different operations on two matrices
@param param_v[] pointer to an array of command line arguments 
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void operations(char* param_v[], matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function performs addition of two matrices and input result to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void addOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function performs substraction of two matrices and input result to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void substractOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function performs multiplication of two matrices and input result to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void multiplyOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function input result of transforming two matrices to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void transformOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function transforms matrix and returns it
@param rows number of rows in matrix 
@param columns number of columns in matrix 
@param matrix pointer to a pointer to a double (to the array of doubles) readed from input file
*/
double** transformOperationPart(int rows, int columns, double** matrix);


/** The function input result of calculation of the determinant to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void determinantOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function calculate determinant of matrix and return its value
@param rows number of rows in matrix
@param columns number of columns in matrix
@param matrix pointer to a pointer to a double (to the array of doubles) readed from input file
*/
double determinantOperationPart(int rows, int columns, double** matrix);


/** The function calculate a complement matrix and return it
@param matrix pointer to the structure of matrix 
*/
double** complementOperation(matrixStruct* matrix);


/** The function input result of inverting matrices to the output file
@param matrixA pointer to the structure of matrix A
@param matrixB pointer to the structure of matrix B
@param file_result reference to the output file
*/
void inverseOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result);


/** The function perform inversion of two matrices
@param matrix pointer to the structure of matrix 
@param file_result reference to the output file
*/
void inverseOperationPart(matrixStruct* matrix, ofstream& file_result);


#endif