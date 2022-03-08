#include <iostream>
#include <algorithm> // .find
#include <fstream>
#include <cstring>
#include <string>
#include "functions.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
/*Matrix calculator (loading from file and saving to file) Add, subtract, multiply, transform,
determinant, inverse of the matrix operations needs to be implemented. Matrix in files can have
different sizes. The format of matrix file is size (2 numbers divided by semicolon, lines start with #) in
the fisrt line and then matrix data divided by semicolons example:
#2;2
1;1
2;2
Program should get following switches from console:
-a input file for A matrix
-b input file for B matrix
-o output file with resutls of calcuation or error message if calcualtions cannot be performed
-operation 'name' – name of operation to be performed, example „operation add”*/

using namespace std;

void get_param(int param_c, char* param_v[], const char* compare, std::string& output_v)
{
    for (int i = 0; i < param_c; i++)
    {
        if (strcmp(param_v[i], compare) == 0 && i + 1 < param_c)
            output_v = param_v[i + 1];
    }
} //  the title of a file

int main(int param_c, char* param_v[])
{
    intro();
    
    std::string file_a = "";
    std::string file_b = "";
    std::string file_result = "";
    

    get_param(param_c, param_v, "-a", file_a);
    get_param(param_c, param_v, "-b", file_b);
    get_param(param_c, param_v, "-o", file_result);

    int matrixRowsintA = NULL;
    int matrixColumnsintA = NULL;
    int matrixRowsintB = NULL;
    int matrixColumnsintB = NULL;

    matrixStruct* arrA = new matrixStruct; 
    matrixStruct* arrB = new matrixStruct;

    //arrA->rows = NULL;
    //arrB->rows = NULL;
    arrA->arrData = createNewArray(matrixRowsintA, matrixColumnsintA);
    arrB->arrData = createNewArray(matrixRowsintB, matrixColumnsintB);

    std::ifstream a;
    std::ifstream b;
    std::ofstream c;

    if (strcmp(param_v[1], "-a") == 0)
    {
        a.open(file_a, std::ios::in);    //permission to read data from file
        arrA->arrData = readMatrixInputFile(a, arrA->rows, arrA->columns);
    }
    else
        cout << "Incorrect first argument. Correct input: -a fileInputA -b fileInputB -o fileOutput -operation typeOfOperation" << endl;

    if (strcmp(param_v[3], "-b") == 0)
    {
        b.open(file_b, std::ios::in);    //permission to read data from file
        arrB->arrData = readMatrixInputFile(b, arrB->rows, arrB->columns);
    }
    else
        cout << "Incorrect second argument. Correct input: -a fileInputA -b fileInputB -o fileOutput -operation typeOfOperation" << endl;
   
    if (strcmp(param_v[5], "-o") == 0)
    {
        c.open(file_result, std::ios::out);     //permission to write data to file
    }
    else
        cout << "Incorrect third argument. Correct input: -a fileInputA -b fileInputB -o fileOutput -operation typeOfOperation" << endl;

    if (strcmp(param_v[7], "-operation") == 0)
    {
        operations(param_v, arrA, arrB, c);
    }
    else
        cout << "Incorrect fourth argument. Correct input: -a fileInputA -b fileInputB -o fileOutput -operation typeOfOperation" << endl;


    a.close();
    b.close();
    c.close();
    clearMemory(arrA->arrData, arrA->rows);
    clearMemory(arrB->arrData, arrB->rows);
    delete arrA;
    delete arrB;
    return(0);
}