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
    void SMr_DFS(std::vector<bool>*,int**,int,int,int);
    void SMi_DFS(int**,int*,int,int,int);
    
    void SLr_BFS(std::vector<bool>*,std::vector<std::vector<int>>,int,int);
    void SLi_BFS(std::vector<std::vector<int>>,int,int);
    void SMr_BFS(std::vector<bool>*,int**,int,int,int);
    void SMi_BFS(int**,int*,int,int,int);
    
    void SL_Dijkstra(std::vector<std::vector<float>>*,std::vector<std::vector<int>>,int,int);
    void SM_Dijkstra(std::vector<std::vector<float>>*,int**,int,int,int);
    void printS_Dijkstra(std::vector<int>,std::vector<std::vector<float>>*, int ,int);
    
    void SL_A_star(std::vector<std::vector<int>>*,std::vector<std::vector<float>>*,std::vector<std::vector<int>>,int,int);
    void SM_A_star(std::vector<std::vector<int>>*,std::vector<std::vector<float>>*,int**,int,int);
    
    void printS_D_A(std::vector<int>,std::vector<std::vector<float>>*, int ,int);
    //void printS_A(std::vector<int>,std::vector<std::vector<float>>*, int ,int);
    
    float costCal(std::vector<int>,std::vector<std::vector<float>>*);
    void Stats(std::string);
private:
    std::vector<int>path_r;//LIST_DFS_r
    std::vector<int>path_b;//LIST_BFS_r
    std::vector<int>path_d;//MATRIX_DFS_r
    std::vector<int>path_m;//MATRIX_BFS_r
    std::vector<int>explored;//node were explored in LIST_BFS_r
    std::vector<int>explored1;//node were explored in Matrix_BFS_r
    std::queue<int>q_c1;//LIST_BFS_r queue contanier
    std::queue<int>q_c2;//Matrix_BFS_r queue contanier
    int size;
    float totalCost;
};
#endif /* searchAlgo_hpp */
