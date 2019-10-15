//
//  adjMatrix.hpp
//  lab2
//
//  Created by MollyYu on 10/13/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef adjMatrix_hpp
#define adjMatrix_hpp

#include <stdio.h>
#include <iostream>

class adjMatrix{
public:
    adjMatrix(int);
    ~adjMatrix();
    void addEdge(std::string,std::string);
    int** getMatrix();
    int getMatrixSize();
    int*columnSize();//count each scr has how mant child
    //float Cost(std::string,std::string,float);
    void display();
private:
    int** matrix;
    int depth;
    float totalCost;
    int column_Size[100];
};
#endif /* adjMatrix_hpp */
