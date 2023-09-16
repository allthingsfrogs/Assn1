#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "matrix.hpp"
using namespace std;

ofstream outfile; //ostream object for output.txt

void die() { //if theres a bad input, throw error, clear cin error state
    cout << "BAD INPUT" << endl;
    outfile.open("output.txt", ios::app);//ios:app allows for appending to file, does not overwrite contents
    outfile << "\nBAD INPUT\n";
    outfile.close();
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice, myArrIndex, myArrIndex2, myArrIndex3, arrSize;
    int userRows = 0, userCols = 0, val = 0, row = 0, col = 0; 
    MatrixType userMatrix; //temp matrix
    MatrixType myArr[9]; //array that hold user's matricex
    //ofstream outfile; //ostream object for output.txt
    string quit; //user input to quit
   
    while (true) {
        cout << "Enter a number: " << endl << "1 - GetNewMatrix" << endl << "2 - AddMatrices" << endl;
        cout << "3 - SubMatrices" << endl << "4 - MulMatrices" << endl << "5 - PrintMatrix" << endl;
        cout << "6 - Quit" << endl; 
        if (cin >> choice and choice >=0 and choice <=6){
            switch (choice) {

                case 1: //GetNewMatrix
                cout << "Enter number of rows, columns:" << endl; //ask user for desired matrix dimensions 
                if (cin >> userRows and cin >> userCols){  //if user input are ints, make matrix out of user inputted dimensions
                    userMatrix.MakeEmpty();
                    userMatrix.SetSize(userRows, userCols);
                }
                else { //if they arent, cin goes into error state, clear it, ignore following input, break to menu
                    die();
                    break;
                }
                //while (true)
                for (int i = 0; i < userRows; i++) { //after user makes matrix, ask for values for each index in matrix. values will be zero otherwise
                    for (int j = 0; j < userCols; j++) {
                        cout << "Enter value for [" << i << "]" << "[" << j << "]:" << endl;
                        if (cin >> val){ //if user inputs are valid for a matrix index, store value into index 
                            userMatrix.StoreItem(val, i, j);
                        } 
                        else {
                            die();
                            break;
                        }
                    }
                }

                cout << "Name your matrix a number 0 - 9." << endl; //name matrix 0 - 9
                if (cin >> myArrIndex and myArrIndex >=0 and myArrIndex <=9) { //store newly made matrix into myArr w/ user given name as index
                    myArr[myArrIndex] = userMatrix;
                    cout << "Matrix " << myArrIndex << " added." << endl;
                    break; 
                }
                else {
                    die();
                    break;
                }
                break;

            case 2: //AddMatrices
                cout << "Type name of an established matrix (0 - 9):" << endl;
                if (cin >> myArrIndex and myArrIndex >= 0 and myArrIndex <= 9) { //if they type in 0-9, continue, else die
                    cout << "Type name of another established matrix to add to the first (0 - 9)." << endl;
                    if (cin >> myArrIndex2 and myArr[myArrIndex].AddSubCompatible(myArr[myArrIndex2])) { //checks if valid input and if arrays are add/sub compatible
                        cout << "What will the result matrix be named? (0 - 9)" << endl;
                        if (cin >> myArrIndex3 and myArrIndex3 >=0 and myArrIndex3 <=9){ //check input 
                            userRows = getNumRows(myArr[myArrIndex]); 
                            userCols = getNumCols(myArr[myArrIndex]);
                            userMatrix.MakeEmpty(); //make result array
                            userMatrix.SetSize(userRows, userCols); //set its size to be that of the two arrays
                            myArr[myArrIndex3] = userMatrix; //put it into myArr

                            myArr[myArrIndex].Add(myArr[myArrIndex2], myArr[myArrIndex3]); //Add two arrays and put that result into result array
                            break;  
                        }
                        else {
                            die();
                            break;
                        }
                    }
                    else { 
                        die();
                        break;
                    }
                }
                else { 
                    die();
                    break;
                }

    
            case 3: //SubMatrices
                cout << "Type name of an established matrix (0 - 9):" << endl;
                if (cin >> myArrIndex and myArrIndex >= 0 and myArrIndex <= 9) { //if they type in 0-9, continue, else die
                    cout << "Type name of another established matrix to subtract from the first (0 - 9)." << endl;
                    if (cin >> myArrIndex2 and myArr[myArrIndex].AddSubCompatible(myArr[myArrIndex2])) { //checks if valid input and if arrays are add/sub compatible
                        cout << "What will the result matrix be named? (0 - 9)" << endl;
                        if (cin >> myArrIndex3 and myArrIndex3 >=0 and myArrIndex3 <=9){ //check input 
                            userRows = getNumRows(myArr[myArrIndex]); 
                            userCols = getNumCols(myArr[myArrIndex]);
                            userMatrix.MakeEmpty(); //make result array
                            userMatrix.SetSize(userRows, userCols); //set its size to be that of the two arrays
                            myArr[myArrIndex3] = userMatrix; //put it into myArr

                            myArr[myArrIndex].Sub(myArr[myArrIndex2], myArr[myArrIndex3]); //Sub two arrays and put that result into result array
                            break;  
                        }
                        else {
                            die();
                            break;
                        }
                    }
                    else {
                        die();
                        break;
                    }
                }
                else { 
                    die();
                    break;
                }
                break;


            case 4: //MultMatrices
                cout << "Type name of an established matrix (0 - 9):" << endl;
                if (cin >> myArrIndex and myArrIndex >= 0 and myArrIndex <= 9) { //if they type in 0-9, continue, else die
                    cout << "Type name of another established matrix to multiply with the first (0 - 9)." << endl;
                    if (cin >> myArrIndex2 and myArr[myArrIndex].MultCompatible(myArr[myArrIndex2])) { //checks if valid input and if arrays are add/sub compatible
                        cout << "What will the result matrix be named? (0 - 9)" << endl;
                        if (cin >> myArrIndex3 and myArrIndex3 >=0 and myArrIndex3 <=9){ //check input 
                            userMatrix.MakeEmpty(); //make result array
                            userRows = getNumRows(myArr[myArrIndex]); 
                            userCols = getNumCols(myArr[myArrIndex2]);
                            userMatrix.SetSize(userRows, userCols); //set its size to be that of the two arrays
                            myArr[myArrIndex3] = userMatrix; //put it into myArr

                            myArr[myArrIndex].Mult(myArr[myArrIndex2], myArr[myArrIndex3]); //Mult two arrays and put that result into result array
                            break;  
                        }
                        else { 
                            die();
                            break;
                        }
                    }
                    else { 
                        die(); 
                        break;
                    }
                }
                else {
                    die();
                    break;
                }
                break;


            case 5: //MatrixPrint
                cout << "Enter name of matrix to print (number 0 - 9):" << endl;
                if (cin >> myArrIndex and myArrIndex >= 0 and myArrIndex <= 9){    
                    myArr[myArrIndex].Print(outfile);
                    break;
                }
                else { 
                    die();
                    break;
                }
                break;

            case 6: //Quit
                return 0;

            default:
                break;
            }
        }
        else die();
    }
    return 0;
}
