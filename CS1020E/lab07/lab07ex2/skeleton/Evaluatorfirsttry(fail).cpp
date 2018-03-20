//=====================================================================
// FILE: Evaluator.cpp
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
#include <queue>
#include "Token.h"

using namespace std;


// Add your recursive function(s) here.
string print(queue<Token> lmao){
    queue<Token> lmaoCopy = lmao;
    string output = lmaoCopy.front().getToken();
    
    if(lmaoCopy.size() == 1){
        return output;
    }else{
        
        lmaoCopy.pop();
        return  output + " " + print(lmaoCopy);
    }
    
}

int evaluate (queue<Token> sizeOfThree){

    if(sizeOfThree.size() == 3){
        int firstNum = sizeOfThree.front().getNumberValue();
        sizeOfThree.pop();
        Token op =  sizeOfThree.front();
        sizeOfThree.pop();
        int secondNum = sizeOfThree.front().getNumberValue();

        if(op.isAddition())       return firstNum + secondNum;
        if(op.isSubtraction())    return firstNum - secondNum;
        if(op.isMultiplication()) return firstNum * secondNum;
        if(op.isDivision())       return firstNum / secondNum;

    }else{
        // cout << "only 1 member in the ueue" << endl;
        return sizeOfThree.front().getNumberValue();
    }
}

int main() {

    queue<Token> inputExpr;
    string tmp;

    // Add your code here if necessary.

    while (cin >> tmp) {
        Token curToken(tmp);
        inputExpr.push(curToken);
    }

    cout << print(inputExpr) << endl;

    queue<Token> inputEval;
    queue<Token> temp;
    queue<Token> empty;

    while(inputExpr.size() > 0){
        if(inputExpr.front().isLeftParenthesis()){
            inputExpr.pop();
            continue;
        }
        
        if(inputExpr.front().isRightParenthesis()){

            temp = empty;
            while(inputEval.size() > 3){
                temp.push(inputEval.front());
                inputEval.pop();

            }

            Token curToken(to_string(evaluate(inputEval)));
            temp.push(curToken);

            inputEval = temp;

            inputExpr.pop();
            continue;
        }
        inputEval.push(inputExpr.front());

        inputExpr.pop();
    }
    
    
    int exprValue = evaluate(inputEval);
    
    cout << exprValue << endl;

    

    return 0;
}
