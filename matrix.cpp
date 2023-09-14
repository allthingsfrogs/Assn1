#include "matrix.hpp"
#include <fstream>
#include <algorithm>
using namespace std;

MatrixType::MatrixType() 
{
    numRows = 0;
    numCols = 0;
}

void MatrixType::MakeEmpty()
{
    numRows = 0;
    numCols = 0;
}

void MatrixType::SetSize(int rowsSize, int colSize)
{
    if (numRows == 0 and numCols == 0) {
        numRows = rowsSize;
        numCols = colSize;
        fill(values[0], values[0] + numRows * numCols, 0); //from <algorithm>, zero-fills in O(N) instead of O(N^2) like double for loops 
    }
    else {
        cout << "Cannot set size of an already filled array, empty it first." << endl;
    }
}

void MatrixType::StoreItem(int item, int row, int col) //
{
    values[row][col] = item;

    /*for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++){
            if (i == row and j == col) values[i][j] = item;
        }
    }
    */
}

void MatrixType::Add(MatrixType otherOperand, MatrixType &result)
{   
    int temp = 0;
   // if (AddSubCompatible(otherOperand)){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++) {
             //   result.values[i][j] = values[i][j] + otherOperand.values[i][j]; //matrix 1's elements are added to matrix 2
                temp = values[i][j] + otherOperand.values[i][j];
                result.StoreItem(temp, i, j);
                cout << result.values[i][j] << endl;
            }
        }
   // }

}

void MatrixType::Sub(MatrixType otherOperand, MatrixType &result)
{
    int temp = 0;
   // if (AddSubCompatible(otherOperand)){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++) {
            //    result.values[i][j] = values[i][j] - otherOperand.values[i][j]; //matrix 2's elements are subtracted from matrix 1
                temp = values[i][j] - otherOperand.values[i][j];
                result.StoreItem(temp, i, j);
                cout << result.values[i][j] << endl;
            }
        }
   //  }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType &result)
{
   // if (MultCompatible(otherOperand)) { //first check to see if 2 Ms can be multiplied
     //   int resultSize = numRows * otherOperand.numCols;
      //  result.SetSize(resultSize, resultSize); //make result matrix size = numCol * otherOperand.numRows to hold solution of each dot product 
   // }
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < otherOperand.numCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < numCols; k++){
                result.values[i][j] += values[i][k] * otherOperand.values[k][j];
            }
        }
    }

}

void MatrixType::Print(ofstream &outfile)
{
    //ofstream outfile;
    outfile.open("output.txt", ios::app);//ios:app allows for appending to file, does not overwrite contents

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            outfile << values[i][j];
        }
        outfile << endl;
    }
    outfile.close();
}

bool MatrixType::AddSubCompatible(MatrixType otherOperand) //can only add matrices if they have the same dimensions
//in test driver:
//use this function to check if the result matrix is the same size as the two matrices being added, If not then use SetSize to do so
{
    if (numRows == otherOperand.numRows and numCols == otherOperand.numCols) return true;
    else {
        cout << "These two matrices aren't add/sub compatible." << endl;
        return false;      
    }
}

bool MatrixType::MultCompatible(MatrixType otherOperand) //can only mult matrices if matrix1 has numRows equal to numCols of matrix2
{
    if (numRows == otherOperand.numCols and numCols == otherOperand.numRows) return true;
    
    else {
        cout << "These two matrices aren't mult compatible." << endl;
        return false;
    }
}
