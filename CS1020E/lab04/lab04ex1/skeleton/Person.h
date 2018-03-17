//=====================================================================
// FILE: Person.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef person_h
#define person_h

#include <string>
#include <vector>
using namespace std;

class Person{
private:
    string name;
    vector <int> groups;  // contain the group id's of the person's groups.

public:
    Person();
    Person(string name);

    string getName();
    void joinGroup(int grp);
    void quitGroup(int grp);
    int getNumOfGroups();
    int getGroup(int i);
    bool know(Person *p2);

    // Add more here if necessary.
    bool checkGroup(int grp);
};

#endif
