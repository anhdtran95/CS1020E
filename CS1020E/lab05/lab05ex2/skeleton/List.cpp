//=====================================================================
// FILE: List.cpp
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
#include <cstdlib>
#include "List.h"
using namespace std;


List::List() {
    _head = new Node(-1);  // Add a dummy head node.
}


void List::push_back(int x) {

    // Add your code here.
    Node *next = NULL, *curr = _head;
    if(_head == NULL){
        _head = new Node(x);
    }else{
        next = new Node(x);
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = next;     
    }

}


void List::reorderList() {
    if ( _head->next == NULL || _head->next->next == NULL) return;

    // Add your code here.
    Node *curr = _head, *temp, *nextnext = NULL, *tempnext = NULL;
    bool next = true;//if last then take the last or if not then take the next so it toggles
    while(curr->next != NULL){
        temp = curr;
        if(next){
            curr = curr->next;
        }else{
            while(temp->next->next != NULL){//go to the near last
                temp = temp->next;
            }
            tempnext = temp->next;          //get the last element
            temp->next = NULL;              // set the near-last -> next to NULL to make it the last

            nextnext = curr->next;          //set a pointer for curr-> next
            curr->next = tempnext;          //now make curr->next the last
            tempnext->next = nextnext;      //now make the last->next = the next of curr
            curr = tempnext;                //update the curr pointer

        }
        next = !next;//alternate hahahaha
    }


}


void List::printList() {
    for (Node *n = _head->next; n != NULL; n = n->next) {
        cout << n->value << " ";
    }
}
