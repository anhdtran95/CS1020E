//=====================================================================
// FILE: Swing.cpp
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
#include <stack>
using namespace std;


int numSwingPairs( int arr[], int size ) {
    stack<int> check;

    // Add your code here.

    int currTree;
    int count = 0;
    for(int i = 0; i < size; i++){
        
        currTree = arr[i];

        // cout << "curr tree is: " << currTree << endl;
        //if current stack is empty just push current tree 
        if(check.empty())
            check.push(currTree);
        else{

            //pop until the top is bigger than current tree
            while(!check.empty() && currTree > check.top()){
                check.pop();
                count++;
                // cout << "count is first: " << count << endl;
            }

            if(check.empty())
                check.push(currTree);
            else if(!check.empty() && currTree < check.top()){
                check.push(currTree);
                count++;
                // cout << "count is second: " << count << endl;
            }
            else if(currTree == check.top()){
                count++;
                // cout << "count is third: " << count << endl;
            }
                
        }
        

    }

    return count;

}


int main() {
    int N;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << numSwingPairs(arr, N) << endl;

    return 0;
}
