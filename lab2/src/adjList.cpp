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
    //head = nullptr;
    depth = 0;
    //counter = 0;
}
adjList::~adjList(){
    
}
void adjList::addEdge(string scr,string des){
    
    int head;
    head = stoi(scr);
    int child;
    child = stoi(des);
    //cout<<"Head is :"<<head<<endl;
    //cout<<"child is : "<<child<<endl;
    for(int i = adj_list.size();i<head;i++){
        vector<int>temp;
        adj_list.push_back(temp);
    }
    adj_list[head-1].push_back(child);
    //adj[child].push_back(head);
    //cout<<"size is "<<adj.size()<<endl;
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
