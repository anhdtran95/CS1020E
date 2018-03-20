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

int evaluate (queue<Token> sizeOfThree){// the input for this is a queue of size 3 or of size 1

    if(sizeOfThree.size() == 3){// if queue is of size 3 which means Int => Op => Int
        int firstNum = sizeOfThree.front().getNumberValue();
        sizeOfThree.pop();
        Token op =  sizeOfThree.front();
        sizeOfThree.pop();
        int secondNum = sizeOfThree.front().getNumberValue();

        if(op.isAddition())       return firstNum + secondNum;
        if(op.isSubtraction())    return firstNum - secondNum;
        if(op.isMultiplication()) return firstNum * secondNum;
        if(op.isDivision())       return firstNum / secondNum;

    }else{// this means queue only contain 1 int for cases like ( 90 )

        return sizeOfThree.front().getNumberValue();
    }
}

//calculate is defined after evaluate because calculate calls evaluate
int calculate(queue<Token> input, queue<Token> evalQueue, queue<Token> tempQueue, queue<Token> empty){

    if(input.size() == 0){//when everything is pushed onto the other queue
        return  evaluate(evalQueue);// evalqueue will always be the queue to be evaluated
    }else 
    if(input.front().isLeftParenthesis()){// if left parenthesis, dont care about it
        input.pop();
    }else
    if(input.front().isRightParenthesis()){// when right parenthesis starts doing calculation

        tempQueue = empty;//most efficient way of clearing a queue
        while(evalQueue.size() > 3){
            tempQueue.push(evalQueue.front());

            evalQueue.pop();
        }
        Token curToken(to_string(evaluate(evalQueue)));
        tempQueue.push(curToken);//tempQueue is sort of like a temporary queue to store evalqueue when its being evaluated

        evalQueue = tempQueue;// after that evalQueue is updated accordingly
        input.pop();

    }else{      
        evalQueue.push(input.front());
        input.pop();
    }
    
    return calculate(input,evalQueue,tempQueue,empty);// this function keeps returning itself until input queue is empty
}


int main() {

    queue<Token> inputExpr;
    string tmp;

    // Add your code here if necessary.

    while (cin >> tmp) {
        Token curToken(tmp);
        inputExpr.push(curToken);
    } 

    queue<Token> evalQueue;//empty queue
    queue<Token> tempQueue;//empty queue
    queue<Token> empty;//empty and constant
    
    int exprValue = calculate(inputExpr, evalQueue, tempQueue, empty);
    
    cout << exprValue << endl;

    

    return 0;
}
