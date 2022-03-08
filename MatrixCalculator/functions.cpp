#include <iostream>
#include <algorithm> // .find
#include <fstream>
#include <cstring>
#include <string>
#include "functions.h"

using namespace std;

void intro()
{
	cout << "+---MENU------------------------------------------------+" << "\n";
	cout << "|                                                       |" << "\n";
	cout << "|   Avaliable parameters:                               |" << "\n"; 
	cout << "|   [  -a  ]                                            |" << "\n";
	cout << "|        Should contain input file with Matrix 'A'      |" << "\n";
	cout << "|   [  -b  ]                                            |" << "\n";
	cout << "|        Should contain input file with Matrix 'B'      |" << "\n";
	cout << "|   [  -o  ]                                            |" << "\n";
	cout << "|        Should contain name for output file            |" << "\n";
	cout << "|   [  -operation  ]                                    |" << "\n";
	cout << "|        Should contain type of operation,              |" << "\n";
	cout << "|        that user wants to be performed on the Matrix  |" << "\n";
	cout << "|   Examples:                                           |" << "\n";
	cout << "|         Add                                           |" << "\n";
	cout << "|         Substract                                     |" << "\n";
	cout << "|         Multiply                                      |" << "\n";
	cout << "|         Transform                                     |" << "\n";
	cout << "|         Determinant                                   |" << "\n";
	cout << "|         Inverse                                       |" << "\n";
	cout << "+-------------------------------------------------------+" << "\n";
};

void writeToFile(matrixStruct* matrix, ofstream& file_result)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            file_result << matrix->arrData[i][j];
            if (j != matrix->columns - 1)
                file_result << ";";
        }
        file_result << "\n";
    }
}

double** readMatrixInputFile(ifstream& file, int& matrixRowsint, int& matrixColumnsint)
{
    if (file.good())
    {
        string text;
        string matrixRows;
        string matrixColumns;
        getline(file, text);

        if (text[0] == '#')
        {
            int found;
            found = text.find(";");
            matrixRows = text.substr(1, found - 1);
            matrixColumns = text.substr(found + 1);
            cout << "matrixRows =" << matrixRows << endl;
            matrixRowsint = stoi(matrixRows); // changes string to int
            cout << "matrixRowsint =" << matrixRowsint << endl;
            matrixColumnsint = stoi(matrixColumns);
            cout << "matrixColumnsint =" << matrixColumnsint << endl;
        }
        else
        {
            cout << "Incorrect first line of the input file." << endl;
            return 0;
        }
        double** arrMatrix = createNewArray(matrixRowsint, matrixColumnsint);

        int j = 0;
        while (getline(file, text))
        {
            for (int i = 0; i < matrixColumnsint; i++)
            {
                int found;
                found = text.find(";");
                arrMatrix[j][i] = stoi(text.substr(0, found));
                text = text.substr(found + 1);
            }
            text = " ";
            j++;
        }
        return arrMatrix;
    }
    else
    {
        cout << "Error! Couldn't open!" << endl;
        return 0;
    }

}

void operations(char* param_v[], matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (strcmp(param_v[8], "add") == 0)
    {
        addOperation(matrixA, matrixB, file_result);
        cout << "add" << endl;
    }
    if (strcmp(param_v[8], "substract") == 0)
    {
        substractOperation(matrixA, matrixB, file_result);
        cout << "substract" << endl;
    } 
    if (strcmp(param_v[8], "multiply") == 0)
    {
        multiplyOperation(matrixA, matrixB, file_result);
        cout << "multiply" << endl;
    }
    if (strcmp(param_v[8], "transform") == 0)
    {
        transformOperation(matrixA, matrixB, file_result);
        cout << "transform" << endl;
    }
    if (strcmp(param_v[8], "determinant") == 0)
    {
        determinantOperation(matrixA, matrixB, file_result);
        cout << "determinant" << endl;
    }
    if (strcmp(param_v[8], "inverse") == 0)
    {
       inverseOperation(matrixA, matrixB, file_result);
       cout << "inverse" << endl;
    }
}

void addOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->rows == matrixB->rows && matrixA->columns == matrixB->columns)
    {
        for (int i = 0; i < matrixA->rows; i++)
        {
            for (int j = 0; j < matrixA->columns; j++)
            {
                file_result << matrixA->arrData[i][j] + matrixB->arrData[i][j];
                if (j != matrixA->columns - 1)
                    file_result << ";";
            }
            file_result << "\n";
        }
    }
    else
        cout << "Can't perform addition. Matrices have different dimensions." << endl;
};

void substractOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->rows == matrixB->rows && matrixA->columns == matrixB->columns)
    {
        for (int i = 0; i < matrixA->rows; i++)
        {
            for (int j = 0; j < matrixA->columns; j++)
            {
                file_result << matrixA->arrData[i][j] - matrixB->arrData[i][j];
                if (j != matrixA->columns - 1)
                    file_result << ";";
            }
            file_result << "\n";
        }
    }
    else
        cout << "Can't perform substraction. Matrices have different dimensions." << endl;
}

void multiplyOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->columns == matrixB->rows)
    {
        for (int i = 0; i < matrixB->columns; i++)
        {
            for (int j = 0; j < matrixB->columns; j++)
            {
                double h = 0;
                for (int k = 0; k < matrixB->rows; k++)
                {
                    h = h + matrixA->arrData[i][k] * matrixB->arrData[k][j];
                }
                file_result << h;
                if (j != matrixA->columns - 1)
                    file_result << ";";
            }
            file_result << "\n";
        }
    }
    else
        cout << "Can't perform multiplication. Matrices have wrong dimensions." << endl;
}

void transformOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->columns > 0)
    {
        file_result << "Matrix A transponent:" << endl;

        matrixStruct* arrTemp = new matrixStruct;
        //arrTemp->arrData = createNewArray(matrixA->rows, matrixA->columns);
        arrTemp->rows = matrixA->rows;
        arrTemp->columns = matrixA->columns;

        arrTemp->arrData = transformOperationPart(matrixA->rows, matrixA->columns,matrixA->arrData);
        writeToFile(arrTemp, file_result);
        clearMemory(arrTemp->arrData, arrTemp->rows);
        delete arrTemp;
    }
    else
        file_result << "Can't calculate transponent of matrix A. There is no data." << endl;

    if (matrixB->columns > 0)
    {
        file_result << "Matrix B transponent:" << endl;

        matrixStruct* arrTemp2 = new matrixStruct;
        //arrTemp2->arrData = createNewArray(matrixB->rows, matrixB->columns);
        arrTemp2->rows = matrixB->rows;
        arrTemp2->columns = matrixB->columns;

        arrTemp2->arrData = transformOperationPart(matrixB->rows, matrixB->columns, matrixB->arrData);
        writeToFile(arrTemp2, file_result);
        clearMemory(arrTemp2->arrData, arrTemp2->rows);
        delete arrTemp2;
    }
    else
        file_result << "Can't calculate transponent of matrix B. There is no data." << endl;
}

double** transformOperationPart(int rows, int columns, double** matrix)
{
    double** arrTemp = createNewArray(rows, columns);

    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arrTemp[j][i] = matrix[i][j];
        }
    }
    return arrTemp;
}

void determinantOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->rows == matrixA->columns)
    {
        file_result << "Matrix A determinant:" << endl;
        file_result << determinantOperationPart(matrixA->rows, matrixA->columns, matrixA->arrData) << endl;
    }
    else 
        file_result << "Can't calculate determinant of matrix A. Matrix A is not square." << endl;

    if (matrixB->rows == matrixB->columns)
    {
        file_result << "Matrix B determinant:" << endl;
        file_result << determinantOperationPart(matrixB->rows, matrixB->columns, matrixB->arrData) << endl;
    }
    else
        file_result << "Can't calculate determinant of matrix B. Matrix B is not square." << endl;
}

double determinantOperationPart(int rows, int columns, double** matrix)
{
    int c, tmpi, i, j, tmpj;
    double d = 0;
    double** arrTemp = createNewArray(rows, columns);

    if (rows == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else
    {
        for (c = 0; c < rows; c++)
        {
            tmpi = 0;
            for (i = 1; i < rows; i++)
            {
                tmpj = 0;
                for (j = 0; j < rows; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    arrTemp[tmpi][tmpj] = matrix[i][j];
                    tmpj++;
                }
                tmpi++;
            }
            d = d + (pow(-1, c) * matrix[0][c] * determinantOperationPart(rows-1, columns-1,arrTemp));
        }
    }
   
    clearMemory(arrTemp, rows);
    arrTemp = nullptr;
    return d;

}

double** complementOperation(matrixStruct* matrix)
{

    matrixStruct* arrMatrixMini = new matrixStruct;
    arrMatrixMini->arrData = createNewArray(matrix->rows-1, matrix->columns-1);
    matrixStruct* arrTemp = new matrixStruct;
    arrTemp->arrData = createNewArray(matrix->rows, matrix->columns);

    if (matrix->rows == matrix->columns)
    {
        if (determinantOperationPart(matrix->rows, matrix->columns, matrix->arrData) != 0)
        {
            cout<< "Matrix complemented:" << endl;

            for (int i = 0; i < matrix->columns; i++)
            {
                for (int j = 0; j < matrix->columns; j++)
                {
                    int x = 0;
                    for (int k = 0; k < matrix->rows; k++)
                    {
                        if (k == i)
                        {
                            continue;
                        }
                        int y = 0;

                        for (int l = 0; l < matrix->rows; l++)
                        {
                            if (l == j)
                            {
                                continue;
                            }
                            arrMatrixMini->arrData[x][y] = matrix->arrData[k][l];
                            y++;
                        }
                        x++;
                    }
                    if ((i + j) % 2 == 0)
                        arrTemp->arrData[i][j] = determinantOperationPart(matrix->rows - 1, matrix->columns - 1, arrMatrixMini->arrData);
                    else
                        arrTemp->arrData[i][j] = -determinantOperationPart(matrix->rows - 1, matrix->columns - 1, arrMatrixMini->arrData);

                }
            }
            clearMemory(arrMatrixMini->arrData, matrix->rows - 1);
            delete arrMatrixMini;
            return arrTemp->arrData;
        }
        else
            cout << "Can't perform inversion of matrix A. Matrix A determinant is zero." << endl;
    }
    else
        cout << "Can't perform inversion of matrix A. Matrix A is not square." << endl;
    return 0;
}

void inverseOperation(matrixStruct* matrixA, matrixStruct* matrixB, ofstream& file_result)
{
    if (matrixA->rows == matrixA->columns)
    {
        file_result << "Matrix A inverted:" << endl;
        inverseOperationPart(matrixA, file_result);
    }
    else
        file_result << "Can't calculate inverted matrix A. Matrix A is not square." << endl;

    if (matrixB->rows == matrixB->columns)
    {
        file_result << "Matrix B inverted:" << endl;
        inverseOperationPart(matrixB, file_result);
    }
    else
        file_result << "Can't calculate inverted matrix B. Matrix B is not square." << endl;
}

void inverseOperationPart(matrixStruct* matrix, ofstream& file_result)
{
    if (matrix->rows == matrix->columns)
    {
        if (determinantOperationPart(matrix->rows, matrix->columns, matrix->arrData) != 0)
        {
            matrixStruct* arrTemp = new matrixStruct;
            arrTemp->arrData = createNewArray(matrix->rows, matrix->columns);
            arrTemp->rows = matrix->rows;
            arrTemp->columns = matrix->columns;

            double tmp = 0;

            for (int i = 0; i < matrix->rows; i++) 
            {
                for (int j = 0; j < matrix->rows; j++) 
                {
                    arrTemp->arrData[i][j] = matrix->arrData[i][j];
                }
            }
            tmp = 1 / (determinantOperationPart(matrix->rows, matrix->columns, matrix->arrData));

            arrTemp->arrData = transformOperationPart(matrix->rows, matrix->columns, complementOperation(matrix));

            for (int i = 0; i < matrix->rows; i++)
            {
                for (int j = 0; j < matrix->columns; j++)
                {
                    arrTemp->arrData[i][j] *= tmp;
                }
            }

            writeToFile(arrTemp, file_result);
            clearMemory(arrTemp->arrData, matrix->rows);
            delete arrTemp;


        }
        else
            file_result << "Can't calculate inversion, determinant is equal 0." << endl;
    }
}

void clearMemory(double** arrTemp, int matrixRowsint)
{
    if (arrTemp != nullptr)
    {
        for (int i = 0; i < matrixRowsint; i++)
        {
            delete[] arrTemp[i];
        }
        delete[] arrTemp;
        arrTemp = nullptr;
    }
}

double** createNewArray(int rows, int columns)
{
    double** arrTemp;
    arrTemp = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        arrTemp[i] = new double[columns];
    }
    return arrTemp;
}