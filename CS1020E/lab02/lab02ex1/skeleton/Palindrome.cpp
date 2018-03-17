//=====================================================================
// FILE: Palindrome.cpp
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

using namespace std;


// Add other necessary function(s) here.
int checkPalind(int x);


int main()
{

    int x;
    cin >> x;
    
    int y = checkPalind(x);
    
    cout << y << endl;

    if (x == y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    // system("pause");
    return 0;
}

int checkPalind(int x){
    int y = 0;
    int remainder = 0;

    while(x > 0){
        
        remainder = x % 10;
        y = remainder + y *10;
        x = x/10;
    }
  
    return y;
}