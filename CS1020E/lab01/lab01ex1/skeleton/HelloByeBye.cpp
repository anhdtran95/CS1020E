//=====================================================================       
// FILE: HelloByeBye.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu.
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <iostream>
#include <string>

using namespace std;


int main() 
{
    string name;

    cout << "What is your name? ";
    getline(cin, name);

    //=======================
    // WRITE YOUR CODE BELOW.
    //=======================
    
    cout << "Hello how many times? ";

    int time;
    cin >> time;

    if (time != 0){
        for (int i = 1; i <= time; i++){
            cout << i << ": Hello, " << name << "." << endl;
        }
    }

    //=======================

    cout << "Bye-bye!" << endl;

    return 0;
}
