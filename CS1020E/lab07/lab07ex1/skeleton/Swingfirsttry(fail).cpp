//=====================================================================
// FILE: Swing.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
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
    // push an entire array into stack
    // for stack... popping will remove 5 4 3 2 1 not 1 2 3 4 5
    for(int i = 0; i < size; i++){
        check.push(arr[i]);
        // cout << arr[i] << " ";
    }

    //do something with the stack
    

    stack<int> checkCopy = check;//copy the entire stack
    int count = 0;
    int currTree;
    int nextTree;
    int maxMiddleHeight = 0;


    while(!check.empty()){
        checkCopy = check;
        maxMiddleHeight = 0;
        currTree = checkCopy.top();//get the first element out of the list
        checkCopy.pop();

        if(checkCopy.size() == 1){
            count++;
            break;
        }

        //cant use checkcopy.top() when only has 1 member
        
        while(checkCopy.size() > 0){

            nextTree = checkCopy.top();

            if(maxMiddleHeight < nextTree){
                maxMiddleHeight = nextTree;
                count++;

            }
            
            if(nextTree >= currTree){
                break;
            }

            checkCopy.pop();

        }
        
        check.pop();
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
