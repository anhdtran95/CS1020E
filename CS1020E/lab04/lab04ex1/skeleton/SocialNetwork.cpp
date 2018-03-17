//=====================================================================
// FILE: SocialNetwork.cpp
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
#include "SocialNetwork.h"

// Add your code here.
SocialNetwork::SocialNetwork(){}
    
Person * SocialNetwork::addPerson(string name){// shouldnt it return void
    Person *newPerson;
    newPerson = new Person(name);
    persons.push_back(newPerson);
    return newPerson;//return last element
}
    
Group * SocialNetwork::addGroup(string name){
    Group *newGroup;
    int newId = groups.size()+1;//create next id for group
    newGroup = new Group(newId,name);
    groups.push_back(newGroup);
    return newGroup;//return last element
}
    
Person * SocialNetwork::findPerson(string name){
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->getName() == name){
            return persons[i];
        }
    }
}
    
Group * SocialNetwork::findGroup(string name){
    for(int i = 0; i < groups.size(); i++){
        if(groups[i]->getName() == name){
            return groups[i];
        }
    }
}

void SocialNetwork::createjoin(string person, string group){
    Group *groupPointer;
    Person *personPointer;


    //check if group exists then create group    
    if(!checkGroup(group)){
        groupPointer = addGroup(group);
    }else{
        groupPointer = findGroup(group);
    
    }

    //check if person exists then create person
    if(!checkPerson(person)){
        personPointer = addPerson(person);
    }else{
        personPointer = findPerson(person);
    }


    if(!personPointer->checkGroup(groupPointer->getId()) || !groupPointer->checkMember(person)){
        personPointer->joinGroup(groupPointer->getId());
        groupPointer->addMember(personPointer);

        //cout << personPointer->getName() << " just joined " << groupPointer->getName() << " with ID: " << groupPointer->getId() << endl;
    }


}

void SocialNetwork::quit(string person, string group){
    Group *groupPointer = findGroup(group);
    Person *personPointer = findPerson(person);


    if(personPointer->checkGroup(groupPointer->getId()) || groupPointer->checkMember(person)){
        personPointer->quitGroup(groupPointer->getId());
        groupPointer->delMember(personPointer->getName());
        //cout << personPointer->getName() << " just quit " << groupPointer->getName() << " with ID: " << groupPointer->getId() << endl;

    }

}
    
string SocialNetwork::answerQuery1(){
    sortGroups();
    Group * groupPointer = groups[0];
    for(int i = 0; i < groups.size(); i++){
        if(groups[i]->getNumOfMembers() > groupPointer->getNumOfMembers()){
            groupPointer = groups[i];
        }
    }
    return groupPointer->getName();
}
    
string SocialNetwork::answerQuery2(){
    sortPersons();

    Person *personPointer = persons[0];
    int countKnow = 0;
    int countTemp = 0;
    for(int i = 0; i < persons.size(); i++){
        countTemp = 0;
        for(int j = 0; j < persons.size(); j++){
            if(j == i){
                continue;
            }else{
                if(persons[i]->know(persons[j])){
                    //cout << persons[i]->getName() << " knows " << persons[j]->getName() << endl;
                    countTemp++;
                }
            }
        }
        if(countTemp > countKnow){
            //cout << "countTem is: " << countTemp << endl;
            //cout << "countKnow is: " << countKnow << endl;
            countKnow = countTemp;
            personPointer = persons[i];
        }
    }
    return personPointer->getName();

}

bool SocialNetwork::checkPerson(string name){
    bool found = false;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->getName() == name){
            found = true;
        }
    }
    return found;
}

bool SocialNetwork::checkGroup(string name){
    bool found = false;
    for(int i = 0; i < groups.size(); i++){
        if(groups[i]->getName() == name){
            found = true;
        }
    }
    return found;
}

//sort groups alphabetically
void SocialNetwork::sortGroups(){
    int size = groups.size();
    Group * groupArr[size];//create a temP array
    Group * pointerTemp;
    for(int i = 0; i < size; i++){
        groupArr[i] = groups[i];
    }

    for(int i = 0; i < size; i++){
        for(int j = i+1; j< size; j++){
            string name1 = groupArr[i]->getName();
            string name2 = groupArr[j]->getName();
            if(name1.compare(name2) > 0){
                // cout << name1 << " " << name2 << endl;
                pointerTemp = groupArr[i];
                groupArr[i] = groupArr[j];
                groupArr[j] = pointerTemp;
            }
        }
    }

    groups.clear();
    for(int i = 0; i < size; i++){
        groups.push_back(groupArr[i]);
    }

}

void SocialNetwork::sortPersons(){
    int size = persons.size();
    Person * personArr[size];//create a temP array
    Person * pointerTemp;
    for(int i = 0; i < size; i++){
        personArr[i] = persons[i];
    }

    for(int i = 0; i < size; i++){
        for(int j = i+1; j< size; j++){
            string name1 = personArr[i]->getName();
            string name2 = personArr[j]->getName();
            if(name1.compare(name2) > 0){
                // cout << name1 << " " << name2 << endl;
                pointerTemp = personArr[i];
                personArr[i] = personArr[j];
                personArr[j] = pointerTemp;
            }
        }
    }

    persons.clear();
    for(int i = 0; i < size; i++){
        persons.push_back(personArr[i]);
    }

}