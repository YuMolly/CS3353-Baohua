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
#include <queue>
#include <vector>
//#include "adjList.hpp"
#include "adjMatrix.hpp"
class searchAlgo{
public:
    searchAlgo(int,int);
    void SLr_DFS(std::vector<bool>*,std::vector<std::vector<int>>,int,int);
    void SLi_DFS(std::vector<std::vector<int>>,int,int);
    void SMr_DFS(std::vector<bool>*,std::vector<std::vector<int>>,int,int);
    void SMi_DFS(std::vector<std::vector<int>>,int,int);
    
    void SLr_BFS(std::vector<bool>*,std::vector<std::vector<int>>,int,int);
    void SLi_BFS(std::vector<std::vector<int>>,int,int);
    void SMr_BFS(std::vector<bool>*,std::vector<std::vector<int>>,int,int);
    void SMi_BFS(std::vector<std::vector<int>>,int,int);
    
    void SL_Dijkstra(std::vector<std::vector<float>>*,std::vector<std::vector<int>>,int,int);
    void printSL_Dijkstra(std::vector<float>*,int );
    void SM_Dijkstra(int,int);
    void SL_A_star(int,int);
    void SM_A_star(int,int);
    

    void Stats(std::string);
private:
    std::vector<int>path_r;//DFS_r
    std::vector<int>path_b;//DBS_r
    std::vector<int>explored;//node were explored
    std::queue<int>temp;//r_BFS;
    int size;
};
#endif /* searchAlgo_hpp */
