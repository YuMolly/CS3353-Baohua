//
//  searchAlgo.hpp
//  lab2
//
//  Created by MollyYu on 10/7/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef searchAlgo_hpp
#define searchAlgo_hpp

#include <stdio.h>
#include <iostream>
#include <stack>
//#include "adjList.hpp"
#include "adjMatrix.hpp"
class searchAlgo{
public:
    searchAlgo(int);
    void SL_DFS(std::vector<std::vector<int>>,int,int);
    void SM_DFS(adjMatrix*,int,int);
    void S_BFS(int,int);
    void S_Dijkstra(int,int);
    void S_A_star(int,int);
    void display();
private:
    int size;
    bool visited[100];
    std::stack<int>path;
};
#endif /* searchAlgo_hpp */
