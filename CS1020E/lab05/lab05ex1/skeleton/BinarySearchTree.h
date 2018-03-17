//=====================================================================
// FILE: BinarySearchTree.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "TreeNode.h"


class BinarySearchTree {
private:
    TreeNode* _root;  // Pointer to the root node of the BST.

public:
    BinarySearchTree();

    bool isEmpty();
    void insert(int elem);
    int findMin();
    int findMax();
    int findDepth(int elem);

    // Add more if necessary.

};

#endif
