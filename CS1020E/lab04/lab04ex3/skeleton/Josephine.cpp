//=====================================================================
// FILE: Josephine.cpp
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
#include <string>
#include <cstdlib>
#include "DataStructure.h"
using namespace std;


int main()
{
    // Add your code here.
    int noOfCases;
    int N,K;
    cin >> noOfCases;
    for(int i = 0; i < noOfCases; i++){
        cin >> N >> K;

        DataStructure *currNode = NULL, *tempNode = NULL, *headNode = NULL;
        for(int j = 0; j<N; j++){
            currNode = new DataStructure(j+1);

            currNode->assignPrev(tempNode);

            if(j == 0){
                headNode = currNode;
            }else{
                tempNode->assignNext(currNode);//because when j = 0 temNode is still NULL
            }
            tempNode = currNode; 

            if(j == N-1){
                currNode->assignNext(headNode);
                headNode->assignPrev(currNode);
            }
        }
        /*
        DataStructure * pointer = headNode;
        for(int i = 0; i < 20; i++){
            cout << pointer->getId() << endl;
            pointer = pointer->getNext();
        }
        
        DataStructure * pointer = headNode;
        for(int i = 0; i < 20; i++){
            cout << pointer->getId() << endl;
            pointer = pointer->getPrev();
        }
        */

        //what to do with K

        DataStructure *tempCurr = headNode;
        DataStructure *tempPrev,*tempNext;
        int count = 1;

        while(tempCurr->getNext() != tempCurr){//or getPrev
            tempPrev = tempCurr->getPrev();
            tempNext = tempCurr->getNext();
            if(count == K){
                count = 0;
                cout << tempCurr->getId() << " ";
                tempPrev->assignNext(tempNext);
                tempNext->assignPrev(tempPrev);
                delete tempCurr;
                //continue;
            }
            tempCurr = tempNext;
            count++;
        }
        cout << tempCurr->getId() << " " << endl;
        


    }

    return 0;
}
