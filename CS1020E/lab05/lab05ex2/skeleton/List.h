//=====================================================================
// FILE: List.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef List_h
#define List_h

#include <cstdlib>  // for NULL.
using namespace std;


class List {
private:
    struct Node {
        int value;
        Node *next;
        Node(int x) : value(x), next(NULL) {} // Constructor.
    };

    Node *_head;  // The linked list has a dummy head node.

public:
    // List constructor.
    List();

    // Add a new node, that contains the value x, to the end of the list.
    void push_back(int x);

    // Reorder the list according to the problem description.
    void reorderList();

    // Output the data items in the list in sequence.
    void printList();
};

#endif
