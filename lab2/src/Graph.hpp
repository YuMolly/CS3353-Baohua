//
//  Graph.hpp
//  lab2
//
//  Created by MollyYu on 10/12/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include "adjList.hpp"
#include "adjMatrix.hpp"
#include "searchAlgo.hpp"
class Graph{
public:
    Graph();
    ~Graph();
    void loadGraph(std::string,std::string,std::string);
    void DFS(std::string,std::string);
    void display();
private:
    int depth;
    int weight;
    int position;
    adjList *adj;
    adjMatrix *adM;
    searchAlgo *search;
};
#endif /* Graph_hpp */
