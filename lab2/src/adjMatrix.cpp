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

void adjMatrix::display(){
    for(int i = 0;i<depth;i++){
        for(int j = 0; j<depth;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
