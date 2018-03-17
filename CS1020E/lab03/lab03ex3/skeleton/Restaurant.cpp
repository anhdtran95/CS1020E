//=====================================================================
// FILE: Restaurant.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <vector>
#include <iostream>
#include "Table.h"
using namespace std;



int main() {
    vector<Table*> tables;
    
    vector<Group*> groups;

    // get input
    int noOfTable;
    cin >> noOfTable;
    
    Table* tablesTemp[noOfTable];
    Table* pointerTemp;

    string tableName;
    int tableCap;

    //Store all table in a temporary array
    for (int i = 0; i < noOfTable; i++){
        cin >> tableName >> tableCap;
        tablesTemp[i] = new Table(tableName, tableCap);
        
    }

    //SORT TABLE IN ALPHABETICAL ORDER HERE

    for (int i = 0; i < noOfTable; i++){
        for (int j = i + 1; j < noOfTable; j++){
            string name1 = tablesTemp[i]->getName();
            string name2 = tablesTemp[j]->getName();
            
            if(name1.compare(name2) > 0){
                // cout << name1 << " " << name2 << endl;
                pointerTemp = tablesTemp[i];
                tablesTemp[i] = tablesTemp[j];
                tablesTemp[j] = pointerTemp;
            }
        }
    }

    for (int i = 0; i < noOfTable; i++){
        // cout << tablesTemp[i]->getName() << endl;
        tables.push_back(tablesTemp[i]);
    }

    //Proceed with query

    int noOfQuery;
    cin >> noOfQuery;

    int Q_type;
    string Q_groupName;
    int Q_noOfPeople;
    string Q_tableName;
    bool okay;
    // process queries 

    for(int i = 0; i < noOfQuery; i++){
        cin >> Q_type;
        
        switch (Q_type){
            case 1:
                okay = false;
                cin >> Q_groupName >> Q_noOfPeople >> Q_tableName;

                groups.push_back(new Group(Q_groupName, Q_noOfPeople));  //uery number 1 always initialize a grou, if table occuied then it will deconstruct

                // if no of eole > caacity or table occuied then outut not ossible or else outut table name
                for (int i = 0; i < noOfTable; i++){
                    if((tables[i]->getName().compare(Q_tableName) == 0) && (tables[i]->getGroup() == NULL) && (tables[i]->getCapacity() >= Q_noOfPeople)){//if found the table
                        okay = true;
                        tables[i]->addGroup(groups.back());//always add the latest group
                        cout << Q_tableName << endl;
                        break;
                    }
                }
                if (!okay){
                    cout << "not possible" << endl;
                    groups.pop_back();//delete that group
                }
                
                break;
            
            case 2:
                okay = false;
                cin >> Q_groupName >> Q_noOfPeople;

                groups.push_back(new Group(Q_groupName, Q_noOfPeople));  //uery number 1 always initialize a grou, if table occuied then it will deconstruct

                // if no of eole > caacity or table occuied then outut not ossible or else outut table name
                for (int i = 0; i < noOfTable; i++){
                   
                    if((tables[i]->getGroup() == NULL) && (tables[i]->getCapacity() >= Q_noOfPeople)){//if found the table
                        okay = true;
                        tables[i]->addGroup(groups.back());//always add the latest group
                        cout << tables[i]->getName() << endl;
                        break;
                    }
                }
                if (!okay){
                    cout << "not possible" << endl;
                    groups.pop_back();//delete that group
                }
                
                break;
            
            case 3:
                cin >> Q_groupName;
                for (int i = 0; i < noOfTable; i++){
                    if((tables[i]->getGroup() != NULL) && (tables[i]->getGroup()->getName().compare(Q_groupName) == 0)){//if found the group 
                        tables[i]->removeGroup();//delete that group
                        break;
                    }
                }

                for (int i = 0; i < groups.size(); i++){
                    if(groups[i]->getName().compare(Q_groupName) == 0){//if found the group
                        groups.erase(groups.begin()+i);//delete that group
                        break;
                    }
                }

                break;
            
            case 4:

                okay = false;
                cin >> Q_groupName;

                
                for (int i = 0; i < noOfTable; i++){
                    if((tables[i]->getGroup() != NULL) && (tables[i]->getGroup()->getName().compare(Q_groupName)) == 0){//go find the table
                        okay = true;
                        cout << tables[i]->getName()<< endl;
                        break;
                    }
                }
                
                
                if(!okay){
                    cout << "invalid" << endl;
                }
                break;
            
            case 5:

                okay = false;
                cin >> Q_tableName;
                for (int i = 0; i < noOfTable; i++){
                    if((tables[i]->getGroup() != NULL) && (tables[i]->getName().compare(Q_tableName) == 0)){//if found the table  
                        okay = true;
                        cout << tables[i]->getGroup()->getName()<< endl;
                        break;
                    }
                }
                if(!okay){
                    cout << "invalid" << endl;
                }

                break;            
        }
    }

    // delete everything
    for (int i = 0; i < noOfTable; i++){
        delete tables[i];
        delete tablesTemp[i];
    }
    // delete [] tablesTemp;
    tables.clear();
    for (int i = 0; i < groups.size(); i++){
        delete groups[i];
    }
    groups.clear();

    //system("pause");
    return 0;
}
