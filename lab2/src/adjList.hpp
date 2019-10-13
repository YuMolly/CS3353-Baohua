//
//  adjList.hpp
//  lab2
//
//  Created by MollyYu on 10/8/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef adjList_hpp
#define adjList_hpp

//#include "Graph.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

//#include "Node.hpp"
class adjList{
public:
    adjList();
    ~adjList();
    void addEdge(std::string,std::string);
    void display();
private:
    //Node*head;
    std::vector<std::vector<int>> adj_list;
    int depth;
    //int counter;
};
#endif /* adjList_hpp */
