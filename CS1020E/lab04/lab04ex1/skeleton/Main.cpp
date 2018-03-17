//=====================================================================
// FILE: Main.cpp
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
#include "SocialNetwork.h"

int main() {
    SocialNetwork *sn = new SocialNetwork();

    // Add your code here.
    int numOfOps;
    cin >> numOfOps;
    string opType;
    string person;
    string group;
    int queryType;
    
    for (int i = 0; i < numOfOps; i++){
        cin >> opType;
        if(opType == "Createjoin"){
            //createjoin
            cin >> person >> group;
            sn->createjoin(person,group);
            continue;
        }
        if(opType == "Quit"){
            //quit
            cin >> person >> group; 
            sn->quit(person,group);
            continue;
        }
        if(opType == "Query"){
            cin >> queryType;
            switch (queryType){
                case 1:
                    //find group with most members and first alphabetically
                    //cout << "answering Query 1" << endl;
                    cout << sn->answerQuery1() << endl;
                    break;
                case 2:
                    //find people who knows most other or and first aphabetically
                    //basically count all people that are in the same group as the
                    //person and exclude the duplicate
                    //cout << "answering Query 2" << endl;
                    cout << sn->answerQuery2() << endl;
                    break;
                }
            continue;
        }
        
    }


    return 0;
}
