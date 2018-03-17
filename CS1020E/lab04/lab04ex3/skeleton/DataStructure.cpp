//=====================================================================
// FILE: DataStructure.cpp
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
#include <cstdlib>
#include "DataStructure.h"
using namespace std;

// Add your code here.
DataStructure::DataStructure(int id){
    this->id = id;
}

int DataStructure::getId(){
    return id;
}

DataStructure* DataStructure::getPrev(){
    return prev;
}

DataStructure* DataStructure::getNext(){
    return next;
}

void DataStructure::assignPrev(DataStructure* prevPtr){
    prev = prevPtr;
}

void DataStructure::assignNext(DataStructure* nextPtr){
    next = nextPtr;
}