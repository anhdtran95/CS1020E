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
    if (_token == "(") return true;
    return false;
}


bool Token::isRightParenthesis() {
    if (_token == ")") return true;
    return false;
}


bool Token::isOperator() {
    if (_token == "+") return true;
    if (_token == "-") return true;
    if (_token == "*") return true;
    if (_token == "/") return true;
    return false;
}


string Token::getToken() {
    return _token;
}


void Token::setToken(string tokenStr) {
    _token = tokenStr;
}


bool Token::isAddition() {
    if (_token == "+") return true;
    return false;
}


bool Token::isSubtraction() {
    if (_token == "-") return true;
    return false;
}


bool Token::isMultiplication() {
    if (_token == "*") return true;
    return false;
}


bool Token::isDivision() {
    if (_token == "/") return true;
    return false;
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


int Token::getNumberValue() {

    // Add your code here.
    if (isNumber()){

        return stoi(_token);
    }
}


// Add more if necessary.

