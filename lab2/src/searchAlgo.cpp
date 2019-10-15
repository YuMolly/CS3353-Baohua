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
#include <queue>
#include <functional>
using namespace std;

searchAlgo::searchAlgo(int x,int scr){
    size = x;
    path_r.push_back(scr);
    explored.push_back(scr);
    temp.push(scr);
}

void searchAlgo::SLr_DFS(vector<bool>*visited, vector<vector<int>> adj, int scr,int des){
    int c;
    if((*visited)[des-1]){
        return;
    }
    else{
        if(!(*visited)[scr-1])
            (*visited)[scr-1] = true;
        
        for(int i =0;i<adj[scr-1].size();++i){
            c = adj[scr-1][i];
            if(!(*visited)[c-1] && c != 0){
                if((*visited)[des-1] == false){
                    (*visited)[c-1] = true;
                    path_r.push_back(c);
                }
                SLr_DFS(visited,adj, c, des);
            }
        }
    }
}

void searchAlgo::SLi_DFS(vector<vector<int>> adj, int scr,int des){
    vector<bool> visited(adj.size(),false);
    stack<int>path;
    path.push(scr);
    int temp1,temp2;
    int count;
    int counter = -1;
   while(!visited[des-1]){
        count = 0;
        for(int j = 0;j<adj[scr-1].size();j++){
            temp1 = adj[scr-1][j];
            if(visited[temp1-1]){
                count++;
            }
            if(count == adj[scr-1].size()){
               path.pop();
               break;
            }
        }
            scr = path.top();
            if(!visited[scr-1]){
                visited[scr-1] = true;
            }
        
            for (int i = 0; i <= adj[scr-1].size(); ++i){
                counter++;
                int temp = adj[scr-1][counter];
                //cout<<temp<<endl;
                if (!visited[temp-1]){
                    scr = temp;
                    path.push(temp);
                    visited[temp-1] = true;
                    counter = -1;
                }
                if(visited[des-1]){
                    break;
                }
                
            }
    }
    
    cout<<"The iterative path is: ";
    stack<int>s;
    int t;
    while(!path.empty()){
        t = path.top();
        path.pop();
        s.push(t);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void searchAlgo::SMr_DFS(vector<bool>*visited,vector<vector<int>> adj, int scr,int des){
    
}

void searchAlgo::SMi_DFS(vector<vector<int>> adj, int scr,int des){
    
}

void searchAlgo::SLr_BFS(vector<bool> *visited,vector<vector<int>>adj,int scr,int des){
    int c;
    if((*visited)[des-1]){
        //path_b.push_back(c);
        return;
    }
    else{
        if(!(*visited)[scr-1])
            (*visited)[scr-1] = true;
        
        for(int i = 0; i<adj[scr-1].size();i++){
            c = adj[scr-1][i];
            if(!(*visited)[c-1]){
                (*visited)[c-1] = true;
                explored.push_back(c);//node exporled
                temp.push(c);
            if((*visited)[des-1]){
                path_b.push_back(c);
                return;
            }
            }
            
        }
        c = temp.front();
        path_b.push_back(c);
        temp.pop();
        //cout<<"c is: "<<c<<endl;
        SLr_BFS(visited,adj,c,des);
    }
    
}

void searchAlgo::SLi_BFS(vector<vector<int>>adj,int scr,int des){
    vector<bool> visited(adj.size(),false);
    queue<int>path;
    vector<int>p;//create another vector to store the path
    path.push(scr);
    int s;// to store pathh
    int temp1;
    while(!visited[des-1]){
        if(!visited[scr-1]){
            visited[scr-1] = true;
        }
        scr = path.front();
        for (int i = 0; i < adj[scr-1].size(); ++i){
            int temp = adj[scr-1][i];
            if (!visited[temp-1]){
                path.push(temp);
                visited[temp-1] = true;
            }
            else if(visited[des-1]){
                break;
            }
            
        }
        s = path.front();
        p.push_back(s);
        path.pop();
        scr = path.front();
    }
    p.push_back(des);
    cout<<"The path is: ";
    for(int j = 0;j<p.size();j++){
        cout<<p[j]<<" ";
    }
    
}

void searchAlgo::SMr_BFS(vector<bool>*visited, vector<vector<int>>adj,int scr,int des){
    
}

void searchAlgo::SMi_BFS(vector<vector<int>>adj,int scr,int des){
    
}

void searchAlgo::SL_Dijkstra(vector<vector<float>>* cost, vector<vector<int>> adj, int scr, int des){
    cout<<"Dijkstra method on adjlist. From "<<scr<<" to "<<des<<endl;
    vector<float> distance;//to store cost
    int n = adj.size();
    for(int i = 0; i<n;i++){
        //intialize all scr to des are infinite
        distance.push_back(10000000);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
    
    pq.push(make_pair(scr, 0));
    distance[scr-1] = 0;
    while(pq.empty() == false){
        int parent = pq.top().first;
        cout<<"MIN IS: "<<parent<<endl;//==scr
        pq.pop();
        for(int i = 0; i<adj[parent].size();i++){
            int child = adj[parent-1][i];
            float weights = (*cost)[parent-1][child-1];
            if(distance[child] > distance[parent] + weights ){
                distance[child] = distance[parent] + weights;
                pq.push(make_pair(child, distance[child]));
            }
        }
    }
    printSL_Dijkstra(&distance,scr);
}
void searchAlgo::printSL_Dijkstra(vector<float>*dist,int scr){
    cout << "\nPrinting the shortest paths for node " << scr << ".\n";
    for(int i = 0; i < (*dist).size(); i++)
    {
        cout << "The distance from node " << scr << " to node " << i << " is: " << (*dist)[i] << endl;
    }
}
void searchAlgo::SM_Dijkstra(int scr, int des){
    
}

void searchAlgo::SL_A_star(int scr, int des){
    
}

void searchAlgo::SM_A_star(int scr, int des){
    
}

void searchAlgo::Stats(string methodName){
    cout<<"The recusive path is: ";
    if(methodName == "Lr_DFS"){
        for(int i = 0;i<path_r.size();i++){
        cout<<path_r[i]<<" ";
       }
    }
    else if (methodName == "Lr_BFS"){
        for(int i = 0;i<path_b.size();i++){
            cout<<path_b[i]<<" ";
        }
    }
    
    
}
