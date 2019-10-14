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
    void SLr_DFS(std::vector<std::vector<int>>,int,int);
    void SLi_DFS(std::vector<std::vector<int>>,int,int);
    void SMr_BFS(std::vector<std::vector<int>>,int,int);
    void SMi_BFS(std::vector<std::vector<int>>,int,int);
    void SL_Dijkstra(int,int);
    void SM_Dijkstra(int,int);
    void SL_A_star(int,int);
    void SM_A_star(int,int);
    void display();
private:
    int size;
};
#endif /* searchAlgo_hpp */
