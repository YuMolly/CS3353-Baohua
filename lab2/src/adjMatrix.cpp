//
//  adjMatrix.cpp
//  lab2
//
//  Created by MollyYu on 10/13/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "adjMatrix.hpp"
#include <iostream>
#include <string>
using namespace std;

adjMatrix::adjMatrix(int size){
    int** temp = new int*[size];
    column_Size[size];
    for(int i = 0; i < size; i++){
        temp[i] = new int[size];
        
    }
    matrix = temp;
    for (int i = 0; i< size; i++){
        for(int j = 0;j<size;j++){
            matrix[i][j] = 0;
        }
        
    }
    depth = size;
    totalCost = 0.0;
}

adjMatrix::~adjMatrix(){
    delete matrix;
}

void adjMatrix::addEdge(string scr, string des){
    int row = 0;
    int column = 0;
    row = stoi(scr);
    column = stoi(des);
    //cout<<"row is:"<<row<<endl;
    //cout<<"column is:"<<column<<endl;
    matrix[row-1][column -1] = 1;
}

int* adjMatrix::columnSize(){
    int counter;
    for(int i =0;i<depth;i++){
        counter = 0;
        for(int j = 0;j<depth;j++){
            if(matrix[i][j] == 1){
                counter++;
            }
        }
        column_Size[i] = counter;
        //cout<<"row is:"<<i<<"column size is: "<<counter<<endl;
    }
    return column_Size;
}

int ** adjMatrix::getMatrix(){
    return matrix;
}
int adjMatrix::getMatrixSize(){
    return depth;
}
void adjMatrix::display(){
    for(int i = 0;i<depth;i++){
        for(int j = 0; j<depth;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
