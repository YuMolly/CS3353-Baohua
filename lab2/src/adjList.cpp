//
//  adjList.cpp
//  lab2
//
//  Created by MollyYu on 10/8/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "adjList.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
adjList::adjList(){
    vector<int> temp;
    vector<vector<int>> temp1;
    temp1.push_back(temp);
    adj_list = temp1;
    totalCost = 0.0;
}
void adjList::addEdge(string scr,string des){
    int head;
    head = stoi(scr);
    int child;
    child = stoi(des);
    for(int i = adj_list.size();i<head;i++){
        vector<int>temp;
        adj_list.push_back(temp);
    }
    adj_list[head-1].push_back(child);
}
std::vector<std::vector<int>> adjList::getList(){
    return adj_list;
}

float adjList::Cost(string x, string y, float cost){
    return totalCost;
}

void adjList::display(){
    for(int i = 0;i<adj_list.size();i++){
        cout << i + 1 << "-> ";
        for(int j = 0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<' ';
        }
        cout << '\n';
    }

}
