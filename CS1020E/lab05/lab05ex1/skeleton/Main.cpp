//=====================================================================
// FILE: Main.cpp
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
#include "BinarySearchTree.h"
using namespace std;


int main() {

    // Add your code here.
    BinarySearchTree *tree;
    tree = new BinarySearchTree();

    int N;
    cin >> N;
    string query;
    int elem;

    for(int i = 0; i < N; i++){
        cin >> query;
        if(query == "INSERT"){
            cin >> elem;
            tree->insert(elem);

            continue;
        }
        if(query == "FINDMIN"){
            //cout << "min: ";
            cout << tree->findMin() << endl;

            continue;
        }
        if(query == "FINDMAX"){
            //cout << "max: ";
            cout << tree->findMax() << endl;

            continue;
        }
        if(query == "FIND"){
            cin >> elem;
            //cout << "findings: ";
            cout << tree->findDepth(elem) << endl;

            continue;
        }
    }

    return 0;
}
