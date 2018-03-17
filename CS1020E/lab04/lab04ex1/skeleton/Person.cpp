//=====================================================================
// FILE: Person.cpp
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
#include <cstdlib>
#include "Person.h"

// Add your code here.

Person::Person(){};
Person::Person(string name){
    this->name = name;// only because I cant modify name to _name
}


string Person::getName(){
    return name;
}

void Person::joinGroup(int grp){
    if(!checkGroup(grp)){
        groups.push_back(grp);    
    }
}

void Person::quitGroup(int grp){
    if(checkGroup(grp)){
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] == grp){
                groups.erase(groups.begin() + i);
            }
        }
    }
}
    
int Person::getNumOfGroups(){
    return groups.size();
}
    
int Person::getGroup(int i){
    return groups[i];//return id of group
}
    
bool Person::know(Person *p2){
    //cout << "checking if " << name << " knows " << p2->getName() << endl;
    bool know = false;
    for(int i = 0; i < groups.size(); i++){
        for(int j = 0; j< p2->getNumOfGroups(); j++){
            if(groups[i] == p2->getGroup(j)){
                know = true;
            }
        }
    }
    return know;
}

bool Person::checkGroup(int grp){
    bool found = false;
    for (int i = 0; i < groups.size(); i++){
        if(groups[i] == grp){
            found = true;
        }
    }
    return found;
}
