//=====================================================================
// FILE: Keyboard.cpp
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
#include "Keyboard.h"
using namespace std;

// Add your code here.

Keyboard::Keyboard(){
    _head = new Node;
    _head->letter = '\0';
    _cursor = new Node;
    _tail = new Node;
    _cursor = _head;
    _tail = _head;

    _cursor->prev = NULL;
    _cursor->next = NULL;

}

void Keyboard::moveCursorLeft(int k){
    for(int i = 0;i<k;i++){
        if(_cursor->prev == NULL){
            break;
        }
        _cursor = _cursor->prev;
        // cout << "cursor is currently at letter: " << _cursor->letter << endl;
        //cout << _head->prev << endl;
    }
}
    
void Keyboard::moveCursorRight(int k){
    for(int i = 0;i<k;i++){
        if(_cursor->next == NULL){
            break;
        }
        _cursor = _cursor->next;
        // cout << "cursor is currently at letter: " << _cursor->letter << endl;
    }
}
    
void Keyboard::insertChar(char newLetter){

    Node *dummy = new Node;
    dummy->letter = newLetter;

    //cout << "Inserting " << newLetter << endl;
    
    if(_cursor->prev == NULL){//if cursor is at the very beginning of line
        dummy->prev = NULL;
        _head = dummy;
        //cout << _head->letter << endl;
    }else{
        if(_cursor->next == NULL){
            _tail->next = NULL;
            _tail = dummy;
        }
        _cursor->prev->next = dummy;
        dummy->prev = _cursor->prev;    
    }        
    dummy->next = _cursor;
    _cursor->prev = dummy;
    

}
    
void Keyboard::deleteChar(){
    if(_cursor->prev == NULL){//if cursor is at the very beginning of line
        return;
    }else{
        if(_cursor->prev->prev == NULL){
            _cursor->prev = NULL;
            _head = _cursor;
        }else{
            _cursor->prev->prev->next = _cursor;
            _cursor->prev = _cursor->prev->prev;
            _cursor = _head;
        }
        
    }
}
    
void Keyboard::printLine(){
    //cout << "printing something" << endl;
    Node *ptr = new Node;
    ptr = _head;
    while(ptr->letter != '\0'){
        cout << ptr->letter;
        ptr = ptr->next;
    }
    cout << endl;
}

