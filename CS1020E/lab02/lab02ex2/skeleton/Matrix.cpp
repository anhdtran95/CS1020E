//=====================================================================
// FILE: Matrix.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include "Matrix.h"
#include <iostream>


// Add more methods if necessary.
Matrix::Matrix(int size){
    _size = size;
    _matrix = new int *[size];
    for(int i = 0; i < size; i++){
        _matrix[i] = new int[size];
    }
}

Matrix::~Matrix(){
    for (int i = 0; i< _size; i++)
        delete _matrix[i];
    delete [] _matrix;
}

void Matrix::assign(int i, int j, int elem){
    _matrix[i][j] = elem;
}

int Matrix::printElem(int i, int j){
    return _matrix[i][j];
}

void Matrix::rotate(int degrees) {
    // transform the matrix by rotating the matrix 
    int noOfTimes = degrees/90;
    int tempMat[_size][_size];
    for(int k = 0; k< noOfTimes; k++){

        for(int i = 0; i < _size; i++){
            for(int j = 0; j < _size; j++){
                tempMat[i][j] = _matrix[i][j];
            }
        }

        for(int i = 0; i < _size; i++){
            for(int j = 0; j < _size; j++){
                _matrix[i][j] = tempMat[_size - 1 - j][i];
            }
        }

    }

}


void Matrix::reflectX() {
    // transform the matrix by reflecting it about the x-axis
    int tempMat[_size][_size];

    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            tempMat[i][j] = _matrix[i][j];
        }
    }

    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            _matrix[i][j] = tempMat[_size - 1 - i][j];
        }
    }

}


void Matrix::reflectY() {
    // transform the matrix by reflecting it about the y-axis

    int tempMat[_size][_size];

    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            tempMat[i][j] = _matrix[i][j];
        }
    }

    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            _matrix[i][j] = tempMat[i][_size - 1 -j];
        }
    }

}


void Matrix::operate(string operation, string type) {
    // transform matrix according to input operation and type
    if (operation == "Reflect"){
        if (type == "x"){
            Matrix::reflectX();
        }else{
            Matrix::reflectY();
        }
    }else{

        int degree = stoi(type);
        Matrix::rotate(degree);
    }

}
