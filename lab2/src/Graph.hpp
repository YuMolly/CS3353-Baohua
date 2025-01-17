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
    void A_star(int,int);
    void Cost(std::string,std::string,float);
    std::vector<std::vector<float>> getCost();
    std::vector<std::vector<int>> getPosition();
    void Stats(std::string);
    void printcost();
    void printTime();
    void printPosition();
    void sentTime();
    void AVG();
private:
    int depth;//size for create adjlist and matrix
    int wei;//size for cost
    std::vector<std::vector<float>> cost;
    std::vector<std::vector<int>> node_position;
    //int position;
    adjList *adj;
    adjMatrix *adM;
    searchAlgo *search;
    std::chrono::duration<double> time_span_1;
    std::chrono::high_resolution_clock::time_point t_1;
    std::chrono::high_resolution_clock::time_point t_2;
    std::vector<std::pair<std::string, double>> time;
    std::vector<std::pair<std::string, int>> Nodes_in_path;
    std::vector<std::pair<std::string, int>> Nodes_explored;
    std::vector<std::pair<std::string, int>> Dist;
    std::vector<std::pair<std::string, float>> avr_cost;
    
};
#endif /* Graph_hpp */
