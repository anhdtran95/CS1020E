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
#include <cstdlib>
#include "Keyboard.h"
using namespace std;

//P p Q q

int main() {

    Keyboard keyboard;

    // Add your code here.
    int noOfOps;
    cin >> noOfOps;

    string typeOfOp;
    char character;
    int charNum;

    for(int i = 0; i < noOfOps; i++){
        cin >> typeOfOp;
        if(typeOfOp == "insert"){
            cin >> character;
            keyboard.insertChar(character);
            // keyboard.printLine();
            continue;
        }
        if(typeOfOp == "left"){
            cin >> charNum;
            keyboard.moveCursorLeft(charNum);
            // keyboard.printLine();
            continue;
        }
        if(typeOfOp == "right"){
            cin >> charNum;
            keyboard.moveCursorRight(charNum);
            // keyboard.printLine();
            continue;
        }
        if(typeOfOp == "delete"){
            keyboard.deleteChar();
            // keyboard.printLine();
            continue;
        }
    }
    keyboard.printLine();

    return 0;
}
