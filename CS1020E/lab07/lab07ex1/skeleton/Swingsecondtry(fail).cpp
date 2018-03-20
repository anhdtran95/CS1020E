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
    // find a way to traverse thru the array and somehow use stack to get count
    // stack has push(), pop(), top(), size() and empty()
    // i think i need to use size for this 

    stack<int> checkCopy;
    int count = 0;
    int currTree;
    int nextTree;
    int maxHeight;

    for(int i = 0; i < size; i++){
        
        currTree = arr[i];
        check.push(currTree);
        checkCopy = check;
        maxHeight = 0;
        
        while(checkCopy.size() > 1){
            checkCopy.pop();
            nextTree = checkCopy.top();

            if(nextTree > maxHeight){
                count++;
                maxHeight = nextTree;
            }

            if(nextTree >= currTree){
                break;
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
