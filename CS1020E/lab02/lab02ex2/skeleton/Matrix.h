//=====================================================================
// FILE: Matrix.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <string>

using namespace std;

class Matrix {
    private:
        // Add more attributes and methods if necessary.
        
        int ** _matrix;
        int _size;

        void rotate(int degrees);
        void reflectX();
        void reflectY();

    public:
        // constructor
        Matrix(int size);
        
        void operate(string operation, string type);
        
        
        // Add more methods if necessary.
        void assign(int i, int j, int elem);
        int printElem(int i, int j);
        ~Matrix();

};
