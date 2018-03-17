//=====================================================================
// FILE: Transformation.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <iostream>
#include <string>
#include "Matrix.h"

int main() {
    // read input and create the Matrix object
    int size;
    int elem;
    cin >> size;
    
    Matrix mat(size);
    for(int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            cin >> elem;
            mat.assign(i,j,elem);
        }       
    }

    
    // for each operation, process the matrix

    int noOfOp;
    cin >> noOfOp;

    for(int i = 0; i < noOfOp; i++){
        string Op, type;

        cin >> Op >> type;
        mat.operate(Op, type); 
    }

    // output the final matrix


    for(int i = 0; i < size; i++){
        
        for (int j = 0; j< size; j++){
            cout << mat.printElem(i,j);
            if (j < (size - 1)){
                cout << " ";
            }
        }
        
        cout << endl; 
          
    }

    // system("pause");
    return 0;
}
