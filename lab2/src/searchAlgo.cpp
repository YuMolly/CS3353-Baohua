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
#include <cmath>
using namespace std;

searchAlgo::searchAlgo(int x,int scr){
    totalCost = 0.0;
    size = x;
    path_r.push_back(scr);//recusive for list on DFS
    path_d.push_back(scr);//recusive for matrix on DFS
    explored.push_back(scr);//recusive record for list on BFS
    explored1.push_back(scr);//recusive record for  matrix on BFS
    q_c1.push(scr);//queue contanier for recusive list on BFS
    q_c2.push(scr);//queue contanier for recusive matrix on BFS
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
    stack<int>path;// not private valuable exist only in function
    path.push(scr);
    int temp1;
    int count;
    int counter = -1;
   while(!visited[des-1]){
        count = 0;
        for(int j = 0;j<adj[scr-1].size();j++){
            temp1 = adj[scr-1][j];//temp1
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
                int temp = adj[scr-1][counter];//temp
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
    
    cout<<"The iterative path for adjlist in DFS method is: ";
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

void searchAlgo::SMr_DFS(vector<bool>*visited,int** adM, int Msize,int scr,int des){
    int c;
    if((*visited)[des-1]){
        return;
    }
    else{
        if(!(*visited)[scr-1])
            (*visited)[scr-1] = true;

        for(int i =0;i<Msize;++i){
            c = adM[scr-1][i];// =0,1
            
            if(!(*visited)[i] && c != 0){//has path and not visited
                if((*visited)[des-1] == false){//if des does't not be visited
                    (*visited)[i] = true;
                    path_d.push_back(i+1);
                }
                SMr_DFS(visited,adM, Msize,i+1, des);
            }
        }
    }
}

void searchAlgo::SMi_DFS(int** adM, int* columnS,int Msize,int scr,int des){
    vector<bool> visited(Msize,false);
    stack<int>path;
    path.push(scr);
    int temp1;
    int count;
    int counter = -1;
    while(!visited[des-1]){
        count = 0;
        for(int j = 0;j<Msize;j++){
            temp1 = adM[scr-1][j];
            if(visited[j]&& temp1 != 0){
                count++;
            }
            if(count == columnS[scr-1]){
                path.pop();
                break;
            }
        }
        
        scr = path.top();
        cout<<"The scr is: "<<scr<<endl;
        if(!visited[scr-1]){
            visited[scr-1] = true;
        }
        
        for (int i = 0; i < Msize; ++i){
            counter++;
            int temp = adM[scr-1][counter];
            cout<<"i is: "<<i<<endl;
            visited[scr-1] = true;
            if (!visited[counter]&& temp !=0){
                i = 0;
                scr = counter+1;
                path.push(scr);
                cout<<"push what: "<<scr<<endl;
                //visited[scr-1] = true;
                
                counter = -1;
            }
            
           if(visited[des-1]){
                break;
            }
            
        }
    }
    
    cout<<"The iterative path for adjMatrix in DFS method is: ";
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
                q_c1.push(c);
            if((*visited)[des-1]){
                path_b.push_back(c);
                return;
            }
            }
        }
        c = q_c1.front();
        path_b.push_back(c);
        q_c1.pop();
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

void searchAlgo::SMr_BFS(vector<bool>*visited, int**adM,int Msize, int scr,int des){
    int c;
    //q_c2.push(scr);
    if((*visited)[des-1]){
        //path_b.push_back(c);
        return;
    }
    else{
        if(!(*visited)[scr-1])
            (*visited)[scr-1] = true;
        
        for(int i = 0; i<Msize;i++){
            c = adM[scr-1][i];
            
            if(!(*visited)[i]&&c!=0){
                (*visited)[i] = true;
                explored1.push_back(i);//node exporled
                q_c2.push(i+1);
                if((*visited)[des-1]){
                    path_m.push_back(des);
                    return;
                }
            }
        }
        scr = q_c2.front();
        q_c2.pop();
        //scr = q_c2.front();
        path_m.push_back(scr);
        cout<<"scr is: "<<scr<<endl;
        SMr_BFS(visited,adM,Msize,scr,des);
    }
}

void searchAlgo::SMi_BFS(int**adM,int* columns,int Msize,int scr,int des){
    vector<bool> visited(Msize,false);
    queue<int>path;
    vector<int>p;//create another vector to store the path
    vector<int>explored_Mi_BFS;//recod te explored node
    path.push(scr);
    int s;// to store path
    int temp1;
    while(!visited[des-1]){
        if(!visited[scr-1]){
            visited[scr-1] = true;
        }
        scr = path.front();
        for (int i = 0; i < Msize; ++i){
            int temp = adM[scr-1][i];//temp=0or1
            if (!visited[i]&& temp!=0){
                path.push(i+1);//queue
                explored_Mi_BFS.push_back(i);//explored node recorder
                visited[i] = true;
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

void searchAlgo::SL_Dijkstra(vector<vector<float>>* cost, vector<vector<int>> adj, int scr, int des){
    cout<<"Dijkstra method on adjlist. From "<<scr<<" to "<<des;
    vector<int>path;//record for the shortest path
    vector<float> distance;//to store cost
    int n = adj.size();
    for(int i = 0; i<n;i++){
        //intialize all scr to des are infinite
        distance.push_back(10000000);
    }
    priority_queue<pair<int,float>> pq;
    
    pq.push(make_pair(scr, 0));
    distance[scr-1] = 0;
    while((pq.empty() == false)&&(distance[des-1]> pq.top().second)){
        int parent = pq.top().first;
        path.push_back(parent);
        //cout<<"parent IS: "<<parent<<endl;//==scr
        pq.pop();
        for(int i = 0; i<adj[parent-1].size();i++){
            int child = adj[parent-1][i];
            float weights = (*cost)[parent-1][child-1];//get the cost from parent to child
            if(distance[child-1] > distance[parent-1] + weights ){
                distance[child-1] = distance[parent-1] + weights;
                //cout<<"distance child is: "<<distance[child-1]<<endl;
                pq.push(make_pair(child, distance[child-1]));
            }
        }
    }
    path.push_back(des);
    printS_D_A(path,cost,scr,des);
}

void searchAlgo::SM_Dijkstra(vector<vector<float>>* cost,int** adM,int Msize,int scr, int des){
    cout<<"Dijkstra method on adjMatrix. From "<<scr<<" to "<<des;
    vector<int>path;//record for the shortest path
    vector<float> distance;//to store cost
    for(int i = 0; i<Msize;i++){//????what's the size for distance
        //intialize all scr to des are infinite
        distance.push_back(10000000);
    }
    priority_queue<pair<int,float>> pq;
    
    pq.push(make_pair(scr, 0));
    distance[scr-1] = 0;
    while((pq.empty() == false)&&(distance[des-1]> pq.top().second)){
        int parent = pq.top().first;
        path.push_back(parent);
        //cout<<"parent IS: "<<parent<<endl;//==scr
        pq.pop();
        for(int i = 0; i<Msize;i++){
            int child = adM[parent-1][i];// 1 or 0
            //cout<<"child is: "<<child<<endl;
            //cout<<"i is:"<<i<<endl;
            if(child!=0){
                float weights = (*cost)[parent-1][i];//get the cost from parent to child
                if(distance[i] > distance[parent-1] + weights ){
                    distance[i] = distance[parent-1] + weights;
                    //cout<<"distance child is: "<<distance[child-1]<<endl;
                    pq.push(make_pair(i+1, distance[i]));
                }
            }
        }
    }
    path.push_back(des);
    printS_D_A(path,cost,scr,des);
}

void searchAlgo::SL_A_star(vector<vector<int>>* position,vector<vector<float>>* cost,vector<vector<int>> adj,int scr, int des){
    cout<<"A* method on adjlist. From "<<scr<<" to "<<des;
    vector<int>path;//record for the shortest path
    vector<int> distance;//to store cost
    int n = adj.size();
    int dist;
    int power = 2;
    int x,x1;
    int y,y1;
    int z,z1;
    x = (*position)[scr-1][0];
    x1 =(*position)[des-1][0];
    y = (*position)[scr-1][1];
    y1 =(*position)[des-1][1];
    z = (*position)[scr-1][2];
    z1 =(*position)[des-1][2];
    dist = pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);//the distance from scr to des(max)
    for(int i = 0; i<n;i++){
        //intialize all scr to des are the max
        distance.push_back(dist);
    }
    priority_queue<pair<int,int>> pq;
    
    pq.push(make_pair(scr,dist));
    distance[scr-1] = dist;//for scr which has 'dist' distance to des
    while((pq.empty() == false)&&(distance[scr-1]-distance[des-1] == 0)){
        int parent = pq.top().first;
        path.push_back(parent);
        //cout<<"parent IS: "<<parent<<endl;//==scr
        //cout<<"parent distance is: "<<endl;
        pq.pop();
        for(int i = 0; i<adj[parent-1].size();i++){
            int child = adj[parent-1][i];
            x = (*position)[child-1][0];
            y = (*position)[child-1][1];
            z = (*position)[child-1][2];
            dist= pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
            distance[child-1] = dist;
            if(distance[child-1] < distance[parent-1]){
                //cout<<"distance child is: "<<distance[child-1]<<endl;
                pq.push(make_pair(child,distance[child-1]));
            }
        }
    }
    path.push_back(des);
    printS_D_A(path,cost,scr,des);
}

void searchAlgo::SM_A_star(vector<vector<int>>* position,vector<vector<float>>* cost,int** adM,int scr, int des){
    
}

void searchAlgo::printS_D_A(vector<int>p,vector<vector<float>>* cost,int scr,int des){
    cout << "\nPrinting the shortest paths from node " << scr << " to node "<< des<<endl;
    cout << "The path is: ";
    for(int i = 0; i < p.size(); i++)
    {
        cout <<p[i] <<" ";
    }
    cout<<endl;
    costCal(p, cost);
    
}

float searchAlgo::costCal(vector<int> path, vector<vector<float> > * cost){
    int n,n1;
    float totalCost;
    for(int i = 0;i<path.size()-1;i++){
        n = path[i];
        n1 = path[i+1];
        totalCost+=(*cost)[n-1][n1-1];
    }
    cout<<"The total cost is: "<<totalCost<<endl;
    cout<<endl;
    return totalCost;
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
    else if (methodName == "Mr_DFS"){
        for(int i = 0;i<path_d.size();i++){
            cout<<path_d[i]<<" ";
        }
    }
    else if (methodName == "Mr_BFS"){
        for(int i = 0;i<path_m.size();i++){
            cout<<path_m[i]<<" ";
        }
    }
}
