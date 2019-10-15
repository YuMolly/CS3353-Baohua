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
    void DFS(int,int);
    void BFS(int,int);
    void Dijkstra(int,int);
    void Cost(std::string,std::string,float);
    std::vector<std::vector<float>> getCost();
    void Stats(std::string);
    void printcost();
private:
    int depth;//size for create adjlist and matrix
    int wei;//size for cost
    std::vector<std::vector<float>> cost;
    int position;
    adjList *adj;
    adjMatrix *adM;
    searchAlgo *search;
};
#endif /* Graph_hpp */
