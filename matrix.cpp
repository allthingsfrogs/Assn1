#include "matrix.hpp"
#include <fstream>
#include <algorithm>
using namespace std;

//Pre: Must be a main() for this constructor to be used in
//     File hosting main() must include matrix.hpp at the top
MatrixType::MatrixType() 
{
    numRows = 0;
    numCols = 0;
}
//Post: Must construct an object of MatrixType with 0 rows and 0 columns

//Pre: Needs MatrixType Object to exist to alter it
void MatrixType::MakeEmpty()
{
    numRows = 0;
    numCols = 0;
}
//Post: Must set number of columns and rows equal to zero, giving an empty matrix

//Pre: Needs a MatrixType object with empty matrix
//     rowSize and colSize must be ints
void MatrixType::SetSize(int rowsSize, int colSize)
{
    if (numRows == 0 and numCols == 0) {
        numRows = rowsSize;
        numCols = colSize;
        fill(values[0], values[0] + numRows * numCols, 0); //from <algorithm>, zero-fills in O(N) instead of O(N^2) like double forloops does
    }
    else {
        cout << "Cannot set size of an already filled array, empty it first." << endl;
    }
}
//Post: Must give user an array in their MatrixType object that is set to their specified dimensions, filled with zeros

//Pre: Needs a MatrixType object with an array to store items into
//     item, row and col must be ints 
void MatrixType::StoreItem(int item, int row, int col) //
{
    values[row][col] = item;
}
//Post: Must store item into the correct index in Matrix

//Pre: Needs 3 MatrixType objects to exist beforehand, the target, the matrix to add to target's index values, and a result matrix
void MatrixType::Add(MatrixType otherOperand, MatrixType &result)
{   
    int temp = 0;
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++) {
                temp = values[i][j] + otherOperand.values[i][j];
                result.StoreItem(temp, i, j);
            //    cout << result.values[i][j] << endl;
            }
        }
}
//Post: Must store values into correct indexes
//      Must not alter first or second MatrixType object matrixes, only the third

//Pre: Needs 3 MatrixType objects to exist beforehand, the target, the matrix to sub from target's index values, and a result matrix
void MatrixType::Sub(MatrixType otherOperand, MatrixType &result)
{
    int temp = 0;
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++) {
                temp = values[i][j] - otherOperand.values[i][j];
                result.StoreItem(temp, i, j);
            //    cout << result.values[i][j] << endl;
            }
        }
}
//Post: Must store values into correct indexes
//      Must not alter first or second MatrixType object matrixes, only the third

//Pre: Needs 3 MatrixType objects to exist beforehand, the target, the matrix to multiply to target's index values, and a result matrix
void MatrixType::Mult(MatrixType otherOperand, MatrixType &result)
{
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < otherOperand.numCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < numCols; k++){
                result.values[i][j] += values[i][k] * otherOperand.values[k][j];
            }
        }
    }
}
//Post: Must store values into correct indexes
//      Must not alter first or second MatrixType object matrixes, only the third

//Pre: Needs a MatrixType object to print from to already exist
//     Needs an ostream object to have been delcared in main()
//     Needs an output file to exist in directory 
void MatrixType::Print(ofstream &outfile)
{
    outfile.open("output.txt", ios::app);//ios:app allows for appending to file, does not overwrite contents
    outfile << "\n";
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            outfile << values[i][j];
        }
        outfile << "\n";
    }
    outfile.close();
}
//Post: Must accurately print the target MatrixType objects' array into an output file
//      Must close output file when finished printing

//Pre: Needs 2 MatrixType objects to exist to compare their rows/columns 
bool MatrixType::AddSubCompatible(MatrixType otherOperand) //can only add matrices if they have the same dimensions
{
    if (numRows == otherOperand.numRows and numCols == otherOperand.numCols) return true;
    else {
        cout << "These two matrices aren't add/sub compatible." << endl;
        return false;      
    }
}
//Post: Must compare the rows and columns of both the target and operand MatrixType objects' arrays
//      Must return a bool main() can use that reflects their add/sub compatibility, either true or false

//Pre: Must compare the rows and columns ofthe target MatrixType objects's array with the columns of the operand MatrixType objects array
bool MatrixType::MultCompatible(MatrixType otherOperand) //can only mult matrices if matrix1 has numRows equal to numCols of matrix2
{
    if (numRows == otherOperand.numCols and numCols == otherOperand.numRows) return true;
    else {
        cout << "These two matrices aren't mult compatible." << endl;
        return false;
    }
}
//Post: Must compare the rows and columns of both the target and operand MatrixType objects' arrays
//      Must return a bool main() can use that reflects their multiplication compatibility, either true or false


//Pre: There needs to be a MatrixType Object already existing for this function to be called on
int getNumRows(MatrixType &matrix)
{
    return matrix.numRows;
}
//Post: Must return the MatrixType's array's number of rows

//Pre: There needs to be a MatrixType Object already existing for this function to be called on
int getNumCols(MatrixType &matrix)
{
    return matrix.numCols;
}
//Post: Must return the MatrixType's array's number of rows
