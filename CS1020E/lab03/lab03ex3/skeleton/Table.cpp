//=====================================================================
// FILE: Table.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include "Table.h"

Table::Table(){}

Table::Table(string name, int capacity){
    _name = name;
    _capacity = capacity;
    _group = NULL;                  //always initialize your ointer
}

int Table::getCapacity(){
    return _capacity;
}
    
string Table::getName(){
    return _name;
}

bool Table::addGroup(Group* group){//return true if add successfully false if not
    if(_group==NULL){   // if currently there is no grou
         _group = group;
        return true;   
    }
    else{
        return false;
    }
}
    
bool Table::removeGroup(){// return true all the time because you can always kick eole out of your restaurant
    _group = NULL;
    return true;
}
    
Group* Table::getGroup(){// return current grou sitting there
    return _group;
}

