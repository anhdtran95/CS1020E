//=====================================================================
// FILE: Token.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include "Token.h"


Token::Token(string tokenStr): _token(tokenStr) {
}


bool Token::isLeftParenthesis() {
    // Add your code here.
    return (_token == "(");

}


bool Token::isRightParenthesis() {
    // Add your code here.
    return (_token == ")");

}


bool Token::isOperator() {
    // Add your code here.
    return (_token == "*" || _token == "+" || _token == "-" || _token == "/" );

}


bool Token::isNumber() {
    // Add your code here.
    return( 
        _token[0] == '0' ||
        _token[0] == '1' ||
        _token[0] == '2' ||
        _token[0] == '3' ||
        _token[0] == '4' ||
        _token[0] == '5' ||
        _token[0] == '6' ||
        _token[0] == '7' ||
        _token[0] == '8' ||
        _token[0] == '9' 
    );

}


bool Token::hasLowerPrecedenceThan(Token& another) {
    // Add your code here.
    return ((_token == "+" || _token == "-") && (another.getToken() == "*" || another.getToken() == "/"));

}


bool Token::hasEqualPrecedenceTo(Token& another) {
    // Add your code here.

    if(
        ((_token == "+" || _token == "-") && (another.getToken() == "+" || another.getToken() == "-")) || 
        ((_token == "*" || _token == "/") && (another.getToken() == "*" || another.getToken() == "/")) 
    ){
        return true;
    }else{
        return false;
    }

}


string Token::getToken() {
    return _token;
}


void Token::setToken(string tokenStr) {
    _token = tokenStr;
}


    // Add more if necessary.
