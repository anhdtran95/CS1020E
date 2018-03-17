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
#include <stack>
#include "Token.h"
using namespace std;


int main() {

    // Add your code here.

    string postfix(""), tmp;

    stack<Token> charStack;
   

    while (cin >> tmp) {

        // Add your code here.
        Token tokenObj = Token(tmp);
        if(tokenObj.isNumber())
            postfix = postfix + tokenObj.getToken() + " ";

        if(tokenObj.isLeftParenthesis())
            charStack.push(tokenObj);

        if(tokenObj.isRightParenthesis()){

            while(charStack.top().getToken() != "("){
                postfix = postfix + charStack.top().getToken() + " ";
                charStack.pop();
            }
            charStack.pop();
        }

        if(tokenObj.isOperator()){

            while(!charStack.empty() && charStack.top().getToken() != "(" && (tokenObj.hasLowerPrecedenceThan(charStack.top()) || tokenObj.hasEqualPrecedenceTo(charStack.top()))){
                postfix = postfix + charStack.top().getToken() + " ";
                charStack.pop();
            }
            charStack.push(tokenObj);
        }


    }

    // Add your code here.
    while(!charStack.empty()){
        postfix = postfix + charStack.top().getToken() + " ";
        charStack.pop();
    }


    cout << postfix << endl;

    return 0;
}
