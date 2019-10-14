//
//  searchAlgo.cpp
//  lab2
//
//  Created by MollyYu on 10/7/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "searchAlgo.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

searchAlgo::searchAlgo(int x){
    size = x;
    for(int i = 0;i<100;i++){
        visited[i] = false;
    }
    
}
void searchAlgo::SL_DFS(vector<vector<int>> adj, int scr,int des){
    cout<<"Here"<<endl;
    int temp = 0;
    int t,s;
    // wrong with recursive!!
    while(true){
        if(scr == des){
            path.push(des);
            break;
        }
        else{
        for(int i =0;i<size;i++){
            path.push(scr);
            visited[scr-1] = true;//scr=i+1
            for(int j = 1;j<adj[scr-1].size();j++){
                temp = adj[scr-1][j-1];
                s = temp-1;
                if(visited[s]){
                    temp = adj[scr-1][j];
                    SL_DFS(adj,temp, des);
                }
                else
                    SL_DFS(adj,temp, des);
                
            }
        }
        
        }//end else
    }
}

void searchAlgo::display(){
 
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
}
