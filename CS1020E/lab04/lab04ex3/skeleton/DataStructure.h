//=====================================================================
// FILE: DataStructure.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

class DataStructure {
private:
    int id;
    DataStructure* next;
    DataStructure* prev;

public:
    DataStructure();

    // Add more here if necessary.
    DataStructure(int id);
    int getId();
    DataStructure* getPrev();
    DataStructure* getNext();
    void assignPrev(DataStructure* );
    void assignNext(DataStructure* );

};

#endif
