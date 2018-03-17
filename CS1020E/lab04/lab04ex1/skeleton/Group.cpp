//=====================================================================
// FILE: Group.cpp
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
#include "Group.h"

// Add your code here.

Group::Group(){}
Group::Group(int id, string name){
    this->id = id;
    this->name = name;
}
    
int Group::getId(){
    return id;
}

string Group::getName(){
    return name;
}

void Group::addMember(Person *p){
    if(!checkMember(p->getName())){
        members.push_back(p);
    }
}

void Group::delMember(string name){
    if(checkMember(name)){
        for (int i = 0; i< members.size(); i++){
            if(members[i]->getName() == name){
                members.erase(members.begin() + i);
            }
        }
    }
}

int Group::getNumOfMembers(){
    return members.size();
}

Person * Group::getMember(int i){//return member at position i I suppose
    return members[i];
}

bool Group::checkMember(string name){
    bool found = false;
    for (int i = 0; i< members.size(); i++){
        if(members[i]->getName() == name){
            found = true;
        }
    }
    return found;

}
