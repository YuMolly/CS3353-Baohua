//
//  adjList.hpp
//  lab2
//
//  Created by MollyYu on 10/8/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef adjList_hpp
#define adjList_hpp


#include <stdio.h>
#include <iostream>
#include <vector>

class adjList{
public:
    adjList();
    void addEdge(std::string,std::string);
    std::vector<std::vector<int>> getList();
    float Cost(std::string,std::string,float);
    void display();
private:
    //Node*head;
    float totalCost;
    std::vector<std::vector<int>> adj_list;
    //int depth;
    //int counter;
};
#endif /* adjList_hpp */
