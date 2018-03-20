//=====================================================================
// FILE: Token.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef Token_h
#define Token_h

#include <string>
using namespace std;

class Token {
private:
    string _token;

public:
    Token(string tokenStr);
    bool isLeftParenthesis();
    bool isRightParenthesis();
    bool isNumber();
    bool isOperator();
   
    string getToken();
    void setToken(string tokenStr);

    int getNumberValue();
    bool isAddition();
    bool isSubtraction();
    bool isMultiplication();
    bool isDivision();

    // Add more if necessary.

};

#endif
