//=====================================================================
// FILE: TreeNode.cpp
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
#include "TreeNode.h"
using namespace std;


TreeNode::TreeNode()
: _elem(0), _left(NULL), _right(NULL) {
}

TreeNode::TreeNode(int elem)
: _elem(elem), _left(NULL), _right(NULL) {
}

int TreeNode::getElement() {
    return _elem;
}

TreeNode* TreeNode::getLeftChild() {
    return _left;
}

TreeNode* TreeNode::getRightChild() {
    return _right;
}

void TreeNode::setElement(int elem) {
    _elem = elem;
}

void TreeNode::setLeftChild(TreeNode* node) {
    _left = node;
}

void TreeNode::setRightChild(TreeNode* node) {
    _right = node;
}

// Add more if necessary.

