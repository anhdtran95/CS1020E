//=====================================================================
// FILE: findwords.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
// I changed query to an array
//=====================================================================


#include <iostream>
#include <string>
using namespace std;
// Add more variables and functions if necessary.
string getStringHor_ltr(string mat[], int rowNo);
string getStringVert_ttb(string mat[], int colNo, int numOfRows);
string getStringDiag_bltr(string mat[], int rowNo, int colNo, int numOfRows, int numOfCols);
string getStringDiag_tlbr(string mat[], int rowNo, int colNo, int numOfRows, int numOfCols);
string reverse(string str);
int main()
{   

	int row, col;
	cin >> row;
	cin >> col;
	string matrix[row];
	for(int i = 0; i < row; i++){
		cin >> matrix[i];
	}
	int queryNo;
	cin >> queryNo;
	string query[queryNo];
	for(int i = 0; i < queryNo; i++){
		cin >> query[i];
	}

	string strToComp;
	for (int i = 0; i < queryNo; i++){
		bool found = false;
		for (int j = 0; j < row; j++){//horizontal left to right
			strToComp = getStringHor_ltr(matrix,j);
			// cout << strToComp << endl;
			if(strToComp.find(query[i]) <= strToComp.length()){
				found = true;
				
				break;
			}
			strToComp = reverse(getStringHor_ltr(matrix,j));//horizontal right to left
			// cout << strToComp << endl;
			if(strToComp.find(query[i]) <= strToComp.length()){
				found = true;
				
				break;
			}
		}
		if(found){
			cout << "YES" << endl;
			continue;
		}

		for (int j = 0; j < col; j++){
			strToComp = getStringVert_ttb(matrix,j, row);//vertical top to bottom
			// cout << strToComp << endl;
			if(strToComp.find(query[i]) <= strToComp.length()){
				found = true;
				// cout << strToComp << endl;
				break;
			}
			strToComp = reverse(getStringVert_ttb(matrix,j, row));//vertical bottom to top
			// cout << strToComp << endl;
			if(strToComp.find(query[i]) <= strToComp.length()){
				found = true;
				// cout << strToComp << endl;
				break;
			}
		}
		if(found){
			cout << "YES" << endl;
			continue;
		}

		for (int j = 0; j < row; j++){
			for(int k = 0; k < col; k++){
				if(j != (row - 1) && k != 0){
					continue;
				}
				strToComp = getStringDiag_bltr(matrix,j,k,row,col);//diagonal bottom left- top right
				// cout << strToComp << endl;
				if(strToComp.find(query[i]) <= strToComp.length()){
					found = true;
					// cout << strToComp << endl;
					break;
				}
				strToComp = reverse(getStringDiag_bltr(matrix,j,k,row,col));//diagonal topright- bottomleft
				// cout << strToComp << endl;
				if(strToComp.find(query[i]) <= strToComp.length()){
					found = true;
					// cout << strToComp << endl;                   
					break;
				}
			}
			if(found){
				break;
			}
			for(int k = 0; k < col; k++){
				if(j != 0 && k != 0){
					continue;
				}
				strToComp = getStringDiag_tlbr(matrix,j,k,row,col);//diagonal top left-bottomright
				// cout << strToComp << endl;
				if(strToComp.find(query[i]) <= strToComp.length()){
					found = true;
					// cout << strToComp << endl;
					break;
				}
				strToComp = reverse(getStringDiag_tlbr(matrix,j,k,row,col));//diagonal bottomright -topleft
				// cout << strToComp << endl;
				if(strToComp.find(query[i]) <= strToComp.length()){
					found = true;
					// cout << strToComp << endl;
					break;
				}
			}
		}
		if(found){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	//system("pause");
	return 0;
}
string reverse(string str){
	string output = "";
	int strLen = str.length();
	for (int i = 0; i< strLen; i++){
		output += str[strLen-i - 1];
	}
	return output;
}
string getStringHor_ltr(string mat[], int rowNo){                                            //left to right
	return mat[rowNo];
}
string getStringVert_ttb(string mat[], int colNo, int numOfRows){                            //top to bottom
	string output = "";
	for(int i = 0; i < numOfRows; i++){
		output += mat[i][colNo];
	}
	return output;
}
string getStringDiag_bltr(string mat[], int rowNo, int colNo, int numOfRows, int numOfCols){     //bot-left to top-right

	string output = "";
	int i = 0;
	while(rowNo - i >= 0 && colNo + i < numOfCols){
		output += mat[rowNo-i][colNo+i];
		i++;
	}
	return output;
}
string getStringDiag_tlbr(string mat[], int rowNo, int colNo, int numOfRows, int numOfCols){     //top-left to bot-right
	string output = "";
	int i = 0;
	while(rowNo + i < numOfRows && colNo + i < numOfCols){
		output += mat[rowNo+i][colNo+i];
		i++;
	}
	return output;
}

