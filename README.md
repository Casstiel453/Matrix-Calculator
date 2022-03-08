# Matrix-Calculator

Matrix calculator (loading from file and saving to file) Add, subtract, multiply, transform, <br />
determinant, inverse of the matrix operations needs to be implemented. Matrix in files can have different sizes. <br /> <br />
The format of matrix file is size (2 numbers divided by semicolon, lines start with #) in the first line and then <br />
matrix data divided by semicolons, example:<br />
#2;2 <br />
1;1 <br />
2;2 <br /> <br />
Program should get following switches from console: <br />
-a input file for A matrix <br />
-b input file for B matrix <br />
-o output file with resutls of calcuation or error message if calcualtions cannot be performed <br />
-operation 'name' – name of operation to be performed, example „operation add” <br />

Files are text files. Each time the program starts, it displays a short menu, how to <br />
pass correct parameters. <br />
![image](https://user-images.githubusercontent.com/56159258/157210088-906d903b-7f27-4bdb-8330-707ae029ca34.png)
<br />
Program called with incorrect parameters prints an error message: <br />
Incorrect n-th argument.  <br />
Correct input:<br />
-a fileInputA -b fileInputB -o fileOutput -operation typeOfOperation <br /> <br />
Incorrect files are detected and cause a message: <br />
Error! Couldn't open! <br /> <br />
Incorrect first line of file content cause a message: <br />
Incorrect first line of the input file. <br />
