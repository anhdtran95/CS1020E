//=====================================================================
// FILE: BinarySearchTree.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <cstdlib>
#include "BinarySearchTree.h"
using namespace std;


BinarySearchTree::BinarySearchTree()
: _root(NULL) {
}


bool BinarySearchTree::isEmpty() {

    // Add your code here.
    return (_root == NULL);
}


void BinarySearchTree::insert(int elem) {

    // Add your code here.
    if(isEmpty()){
        _root = new TreeNode(elem);
        return;
    }else{
        TreeNode *curr = _root, *temp = NULL; // current pointer
    
        while (curr != NULL){
            if(elem <= curr->getElement()){
                if(curr->getLeftChild() != NULL){
                    curr = curr->getLeftChild();
                }else{
                    temp = new TreeNode(elem);
                    curr->setLeftChild(temp);
                    break;
                }
                
            }else{
                if(curr->getRightChild() != NULL){
                    curr = curr->getRightChild();
                }else{
                    temp = new TreeNode(elem);
                    curr->setRightChild(temp);
                    break;
                }

            }

        }
    }
    
}


int BinarySearchTree::findMin() {

    // Add your code here.
    if(isEmpty()){
        return 0;
    }else{
        TreeNode *curr = _root;
        while(curr->getLeftChild() != NULL){
            curr = curr->getLeftChild();
        }
        return curr->getElement();

    }

}


int BinarySearchTree::findMax() {

    // Add your code here.
    if(isEmpty()){
        return 0;
    }else{
        TreeNode *curr = _root;
        while(curr->getRightChild() != NULL){
            curr = curr->getRightChild();
        }
        return curr->getElement();
    }

}


int BinarySearchTree::findDepth(int elem) {

    // Add your code here.
    int depth = 1;
    if(isEmpty()){
        return 0;
    }else{
        TreeNode *curr = _root;
        while(curr->getElement() != elem){
            if(curr->getElement() > elem){
                if(curr->getLeftChild()){
                    curr = curr->getLeftChild();
                }else{
                    return 0;
                }
                
            }else{
                if(curr->getRightChild()){
                    curr = curr->getRightChild();
                }else{
                    return 0;
                }
                
            }
            depth++;
        }
        return depth;
    }

}


// Add more if necessary.

