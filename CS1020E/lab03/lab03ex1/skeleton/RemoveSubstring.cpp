//=====================================================================
// FILE: RemoveSubstring.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
// I moved the function definition down after int main()
//=====================================================================


#include <iostream>
using namespace std;


// Returns the length of the null-terminated string s.
int stringLength(char s[]);


// Add other necessary functions.
int findString(char parent[], char child[]);


const int maxSize = 101;

int main() 
{
    char str[maxSize], sub[maxSize];

    cin >> str;
    cin >> sub;

    // TODO: Remove from str all occurrences of sub.

    int strLen = stringLength(str);
    int subLen = stringLength(sub); 
    int a = strLen;    
    // COPY ENTIRE string to a new Substring
    char newSub[maxSize];
    for (int i = 0; i < strLen; i++){
        newSub[i] = str[i];
    }

    while(findString(newSub, sub) > 0){                 //while the newSub contains sub

        int pos = findString(newSub, sub);              //pos = position of sub in the new Sub
        a = a - subLen - pos + 1;
        for (int i = 0; i < a; i++){              //new Sub is created from its previous version excluding whatever is in front
            newSub[i] = newSub[i+pos+subLen-1];
            
        }

        newSub[a] = '\0';
        pos = findString(str, sub);

        for (int i = 0; i < strLen; i++){               //new String is created from its previous version excluding the sub
            str[i+pos-1]= newSub[i];
        }
    }
    
    cout << "\"" << str << "\"" << endl;
    
    // system("pause");

    return 0;
}

int stringLength(char s[]) {
    if (s == NULL) {
        return 0;
    } else {
        int i = 0;
        while (s[i] != '\0') { i++; }
        return i;
    }
}

int findString(char parent[],char child[]){
    bool found = false;
    int i;

    if (parent == NULL || child == NULL){
        return 0;
    }else{
        int parentSize = stringLength(parent);
        int childSize = stringLength(child);

        for (i = 0; i < parentSize; i++){
            
            if (found){
                break;
            }

            if (parent[i] == child[0]){
                for (int j = 1; j <= childSize; j++){
                    if(j == childSize){
                        found = true;
                        break;
                    }
                    if (parent[i+j] == child[j]){
                        continue;
                    }else{
                        found = false;
                        break;
                    }
                }

            }else{
                continue;
            }

        }
    }

    if (found){
        return i;
    }else{
        return 0;
    }
}