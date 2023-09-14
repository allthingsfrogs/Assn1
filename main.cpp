#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "matrix.hpp"
using namespace std;

int main() {

    //make a map to keep track of matrices made by user
    unordered_map<string, MatrixType> userMatrices;

//    int inMatrices;
//  MatrixType userMatrix;
//  MatrixType resultMatrix;
//  string matrix1Name;
//  string matrix2Name;
    int choice;
    int userRows = 0;
    int userCols = 0;
    MatrixType userMatrix;
    MatrixType myArr[9];
    int myArrIndex;
    int myArrIndex2;
    int myArrIndex3;
    ofstream outfile;
    int val = 0;
    int row = 0;
    int col = 0;
    string cont;
   
while (true) {
    cout << "Enter a number: " << endl << "1 - GetNewMatrix" << endl << "2 - AddMatrices" << endl;
    cout << "3 - SubMatrices" << endl << "4 - MulMatrices" << endl << "5 - PrintMatrix" << endl;
    cout << "6 - Quit" << endl; 

    cin >> choice;
    switch (choice)
    {
    case 1: //GetNewMatrix
        cout << "Enter number of rows, columns:" << endl;
        //if user input are ints, make matrix out of user inputted dimensions
        if (cin >> userRows and cin >> userCols){ 
            userMatrix.MakeEmpty();
            userMatrix.SetSize(userRows, userCols);
        }
        //if they arent, cin goes into error state, clear it, ignore following input, break to menu
        else { 
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //return 0;
            break;
        }

        //after user makes matrix, ask for dimensions
        while (true) {
            cout << "Enter value, row, column:" << endl;
            if (cin >> val and cin >> row and cin >> col){ 
                userMatrix.StoreItem(val, row, col);
                cout << "Press Q to quit, anything else to continue" << endl;
                cin >> cont;
                if (cont == "Q" or cont == "q") {
                    cout << "Name your matrix a number 0 - 9." << endl;
                    cin >> myArrIndex;
                    break;
                }
            }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

        }
       // userMatrices.insert(make_pair(matrix1Name, userMatrix));
        myArr[myArrIndex] = userMatrix;
        //cout << "Matrix " << matrix1Name << " added." << endl;
        cout << "Matrix " << myArrIndex << " added." << endl;
        break;


    case 2: //AddMatrices
        cout << "Type name of an established matrix (0 - 9):" << endl;
        //cin >> matrix1Name;
        //inMatrices = userMatrices.count(matrix1Name);
        cin >> myArrIndex;
        cout << "Type name of another established matrix to add to the first (0 - 9)." << endl;
        cin >> myArrIndex2;
        cout << "What will the result matrix be named? (0 - 9, excluding already taken values)" << endl;
        cin >> myArrIndex3;
        //add check to see if myArrIndex3 was named over an already existing index
        //add check to see if AddCompatible
        userMatrix.MakeEmpty();
        userMatrix.SetSize(userRows, userCols);
        myArr[myArrIndex3] = userMatrix;

        myArr[myArrIndex].Add(myArr[myArrIndex2], myArr[myArrIndex3]);
        break;
/*
        if (inMatrices) {
            cout << "Type name of another established matrix to add to the first." << endl;
            cin >> matrix2Name;
            inMatrices = userMatrices.count(matrix2Name);
            
            if (inMatrices) {
                userMatrices.at(matrix1Name).Add(userMatrices.at(matrix2Name),resultMatrix);
                cout << "Name the result matrix:" << endl;
                cin >> matrix1Name;    
                userMatrices.insert(make_pair(matrix1Name, resultMatrix));
                cout << "Matrix " << matrix1Name << " added." << endl;
                break;
            }
            else {
                cout << "No matrix with that name exists." << endl;
                break;
            }
        } 
        else {
            cout << "No matrix with that name exists." << endl;
            break;
        }
        break;
    */
    case 3:
        cout << "Type name of an established matrix (0 - 9):" << endl;
        cin >> myArrIndex;
        //check to see if a matrix exists at myArr[myArrIndex]
        cout << "Type name of another established matrix to sub from the first (0 - 9)." << endl;
        cin >> myArrIndex2;
        //check if a matrix exists at myArr[myArrIndex2]

        //add check for compatability
        cout << "What will the result matrix be named? (0 - 9, excluding already taken values)" << endl;
        cin >> myArrIndex3;
        //add check to see if matrix already exists at myArr{myArrIndex3} do next 3 lines if all is good
        userMatrix.MakeEmpty();
        userMatrix.SetSize(userRows, userCols);
        myArr[myArrIndex3] = userMatrix;

        myArr[myArrIndex].Sub(myArr[myArrIndex2], myArr[myArrIndex3]);
        break;

    case 4:
        cout << "Type name of an established matrix (0 - 9):" << endl;
        cin >> myArrIndex;
        cout << "Type name of another established matrix to mult from the first (0 - 9)." << endl;
        cin >> myArrIndex2;
        cout << "What will the result matrix be named? (0 - 9, excluding already taken values)" << endl;
        cin >> myArrIndex3;
        //add check to see if myArrIndex3 was named over an already existing index
        //add check to see if MultCompatible
        userMatrix.MakeEmpty();
        userMatrix.SetSize(userRows, userCols);
        myArr[myArrIndex3] = userMatrix;

        myArr[myArrIndex].Mult(myArr[myArrIndex2], myArr[myArrIndex3]);
        break;

    case 5: //MatrixPrint
        cout << "Enter name of matrix to print (number 1 - 9):" << endl;
      //  cin >> matrix1Name;
      //  inMatrices = userMatrices.count(matrix1Name);

        cin >> myArrIndex;
        myArr[myArrIndex].Print(outfile);
        break;

        /*
        if (inMatrices) {
            userMatrices.at(matrix1Name).Print(outfile); 
            break;
        }
        else {
            cout << "No matrix with that name exists." << endl;
            break;
        }
        */
    
    case 6:
        return 0;

    default:
        break;
    }

   }
    return 0;
}
