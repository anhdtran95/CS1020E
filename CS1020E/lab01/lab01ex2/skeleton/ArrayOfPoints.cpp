//=====================================================================       
// FILE: ArrayOfPoints.cpp
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

using namespace std;


struct Point {
    int x;
    int y;
};


int main() 
{
    int noOfTimes;

    cin >> noOfTimes;
    
    Point *pointArr;

    pointArr = new Point[noOfTimes];

    for (int i = 0; i < noOfTimes; i++){
        cin >> pointArr[i].x;
        cin >> pointArr[i].y;
    }
    
    for (int i = noOfTimes - 1 ; i >= 0; i--){
        cout << "Point " << i << ": (" << pointArr[i].x << ", " << pointArr[i].y << ")" << endl;
    }
    
    delete [] pointArr;
    pointArr = NULL;
    /* cout << "Point " << 1 << ": (" << pointArr[1].x << ", " << pointArr[1].y << ")" << endl; */

    
    return 0;
}
