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
#include <fstream>
using namespace std;
using namespace std::chrono;

searchAlgo::searchAlgo(int depth,int scr){
    totalCost = 0.0;
    //size = x;
    path_r.push_back(scr);//recusive for list on DFS
    path_d.push_back(scr);//recusive for matrix on DFS
    explored.push_back(scr);//recusive record for list on BFS
    explored1.push_back(scr);//recusive record for  matrix on BFS
    q_c1.push(scr);//queue contanier for recusive list on BFS
    q_c2.push(scr);//queue contanier for recusive matrix on BFS
}

void searchAlgo::setN_Path(std::vector<std::pair<std::string, int>> x){
    Nodes_in_path = x;
}
void searchAlgo::setN_e(std::vector<std::pair<std::string, int>> x){
    Nodes_explored = x;
}
void searchAlgo::setD(std::vector<std::pair<std::string, int>> x){
    Dist = x;
}
void searchAlgo::setA(std::vector<std::pair<std::string, float>>y){
    avr_cost = y;
}
std::vector<std::pair<std::string, int>> searchAlgo::getN_Path(){
    return Nodes_in_path;
}
std::vector<std::pair<std::string, int>> searchAlgo::getN_e(){
    return Nodes_explored;
}
std::vector<std::pair<std::string, float>> searchAlgo::getA(){
    return avr_cost;
}
std::vector<std::pair<std::string, int>> searchAlgo::getD(){
    return Dist;
}

void searchAlgo::SLi_DFS(vector<vector<int>> adj, vector<vector<int>>* position,vector<vector<float>>* cost,int scr,int des){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    
    vector<bool> visited(adj.size(),false);
    stack<int>path;// not private valuable exist only in function
    path.push(scr);
    int temp1;
    int count;
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
            int counter = -1;
            for (int i = 0; i < adj[scr-1].size(); ++i){
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
    
    output<<"The adjlist in DFS method ";
    cout<<"The iterative path for adjlist in DFS method is: ";
    stack<int>s;
    vector<int>retured_path;
    int t;
    while(!path.empty()){
        t = path.top();
        path.pop();
        s.push(t);
    }
    while(!s.empty()){
        retured_path.push_back(s.top());
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    output.close();
    string methodName = "The method is adjList in DFS of iterative method";
    costCal(retured_path,position, cost,methodName);
}

void searchAlgo::SLr_DFS(vector<bool>*visited, vector<vector<int>>* position,vector<vector<int>> adj, int scr,int des){
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
                SLr_DFS(visited,position,adj, c, des);
            }
        }
    }
    
}
void searchAlgo::SMr_DFS(vector<bool>*visited, vector<vector<int>>* position, int** adM,int Msize,int scr,int des){
   
    int c;
    if((*visited)[des-1]){
        return;
    }
    else{
        (*visited)[scr-1] = true;

        for(int i =0;i<Msize;++i){
            c = adM[scr-1][i];// =0,1
            
            if(!(*visited)[i] && c != 0){//has path and not visited
                if((*visited)[des-1] == false){//if des does't not be visited
                    (*visited)[i] = true;
                    path_d.push_back(i+1);
                }
                SMr_DFS(visited,position,adM, Msize,i+1, des);
            }
        }
    }
    
}

void searchAlgo::SMi_DFS(int** adM,vector<vector<int>> *position,vector<vector<float>> *cost,int* columnS,int Msize,int scr,int des){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    
    vector<bool> visited(Msize,false);
    stack<int>path;
    path.push(scr);
    int temp1;
    int count;
    
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
        //cout<<"The scr is: "<<scr<<endl;
        if(!visited[scr-1]){
            visited[scr-1] = true;
        }
        int counter = -1;
        for (int i = 0; i < Msize; ++i){
            counter++;
            int temp = adM[scr-1][counter];
            //cout<<"i is: "<<i<<endl;
            visited[scr-1] = true;
            if (!visited[counter]&& temp !=0){
                i = 0;
                scr = counter+1;
                path.push(scr);
                //cout<<"push what: "<<scr<<endl;
                //visited[scr-1] = true;
                
                counter = -1;
            }
            
           if(visited[des-1]){
                break;
            }
            
        }
    }
    
    cout<<"The iterative path for adjMatrix in DFS method is: ";
    output<<"The adjMatrix in DFS method ";
    stack<int>s;
    vector<int>retured_path;
    int t;
    while(!path.empty()){
        t = path.top();
        path.pop();
        s.push(t);
    }
    while(!s.empty()){
        retured_path.push_back(s.top());
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    output.close();
    string methodName = "The method is adjMatrix in DFS of iterative method.";
    costCal(retured_path, position,cost,methodName);
}

void searchAlgo::SLr_BFS(vector<bool> *visited,vector<vector<int>>* position,vector<vector<int>>adj,int scr,int des){
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
        SLr_BFS(visited,position,adj,c,des);
    }
    
}

void searchAlgo::SLi_BFS(vector<vector<int>>adj,vector<vector<int>>* position,vector<vector<float>>*cost,int scr,int des){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
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
    cout<<"The iterative path for adjMatrix in BFS is: ";
    output<<"The adjMatrix in BFS ";
    for(int j = 0;j<p.size();j++){
        cout<<p[j]<<" ";
    }
    cout<<endl;
    string methodName = "The method is adjList in BFS of iterative method.";
    costCal(p,position, cost,methodName);
}

void searchAlgo::SMr_BFS(vector<bool>*visited, vector<vector<int>>* position,int**adM,int Msize, int scr,int des){

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
        //cout<<"scr is: "<<scr<<endl;
        SMr_BFS(visited,position,adM,Msize,scr,des);
    }
    
}

void searchAlgo::SMi_BFS(int**adM,vector<vector<int>>* position,vector<vector<float>>*cost,int* columns,int Msize,int scr,int des){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
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
    cout<<"The iterative path for adjMatrix in BFS is: ";
    output<<"The iterative path for adjMatrix in BFS ";
    for(int j = 0;j<p.size();j++){
        cout<<p[j]<<" ";
    }
    cout<<endl;
    output.close();
    string methodName = "The method is adjMatrix in BFS of iterative method.";
    costCal(p,position, cost,methodName);
}

void searchAlgo::SL_Dijkstra(vector<vector<float>>* cost, vector<vector<int>>* position,vector<vector<int>> adj, int scr, int des){
    cout<<"The path for adjList in Dijkstra is: ";
    //cout<<"Dijkstra method on adjlist. From "<<scr<<" to "<<des;
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
    string methodName = "The method is adList in Dijkstra method.";
    printS_D_A(path,position,cost,scr,des,methodName);
    
}

void searchAlgo::SM_Dijkstra(vector<vector<float>>* cost,vector<vector<int>>* position,int** adM,int Msize,int scr, int des){
    cout<<"The path for adjMatrix in Dijkstra is: ";
    //cout<<"Dijkstra method on adjMatrix. From "<<scr<<" to "<<des;
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
        cout<<".";
    }
    path.push_back(des);
    string methodName = "The method is adLMatrix in Dijkstra method.";
    printS_D_A(path,position,cost,scr,des,methodName);
    Fn(path, position, cost,Msize);
}

void searchAlgo::SL_A_star(vector<vector<int>>* position,vector<vector<float>>* cost,vector<vector<int>> adj,int scr, int des){

    cout<<"The path for adjList in A* is: ";
    //cout<<"A* method on adjlist. From "<<scr<<" to "<<des;
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
        distance.push_back(1000000);
    }
    priority_queue<pair<int,int>,vector< pair<int, int> >, greater<pair<int, int>> > pq;
    
    pq.push(make_pair(scr,dist));
    distance[scr-1] = dist;//for scr which has 'dist' distance to des
    while((pq.empty() == false)){
        int parent = pq.top().first;
        path.push_back(parent);
        //cout<<"parent IS: "<<parent<<endl;//==scr
        //cout<<"parent distance is: "<<endl;
        pq.pop();
        for(int i = 1; i<adj[parent-1].size();i++){
            int child = adj[parent-1][i];
            x = (*position)[child-1][0];
            y = (*position)[child-1][1];
            z = (*position)[child-1][2];
            dist= pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
            
            
            if(distance[child-1] == 1000000){
                distance[child-1] = dist;
                //cout<<"distance child is: "<<distance[child-1]<<endl;
                pq.push(make_pair(child,distance[child-1]));
            }
        }
        cout<<".";
    }
    path.push_back(des);
    string methodName = "The method is adList in A* method.";
    printS_D_A(path,position,cost,scr,des,methodName);
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    output<<"Print F(n) for A* method in adjList:";
    output.close();
    Fn(path, position, cost,n);
}

void searchAlgo::SM_A_star(vector<vector<int>>* position,vector<vector<float>>* cost,int** adM,int Msize,int scr, int des){
    cout<<"The path for adjMatrix in A* is: ";
    //cout<<"A* method on adjMatrix. From "<<scr<<" to "<<des;
    vector<int>path;//record for the shortest path
    vector<int> distance;//to store cost
    //vector<bool>vis;
    //int n = Msize;
    int dist;
    int power = 2;
    int x,x1;
    int y,y1;
    int z,z1;
    //vis[scr-1] = true;
    x = (*position)[scr-1][0];
    y = (*position)[scr-1][1];
    z = (*position)[scr-1][2];
    x1 = (*position)[des-1][0];
    y1 = (*position)[des-1][1];
    z1 = (*position)[des-1][2];
    dist= pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
    //cout<<"The distance is: "<<dist<<endl;
    for(int i = 0; i<Msize;i++){
        //intialize all scr to des are the max
        distance.push_back(10000000);
    }
    priority_queue<pair<int,int>,vector< pair<int, int> >, greater<pair<int, int> >> pq;
    
    pq.push(make_pair(scr,dist));
    distance[scr-1] = dist;//for scr which has 'dist' distance to des
    while((pq.empty() == false)){
        int parent = pq.top().first;
        path.push_back(parent);
        //cout<<"parent IS: "<<parent<<endl;//==scr
        //cout<<"parent distance is: "<<endl;
        pq.pop();
        for(int i = 0; i<Msize;i++){
            int child = adM[parent-1][i];//==1 or 0
            if(child !=0){
                x = (*position)[i][0];
                y = (*position)[i][1];
                z = (*position)[i][2];
                dist= pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
                distance[i] = dist;
                //vis[i] = true;
                if(des == i+1){
                    for(int j = 0;j<=pq.size();j++){
                        if(pq.empty()==false){
                            pq.pop();
                        }
                    }
                }
                else if((distance[i] < pq.top().second)){
                    //cout<<"distance child is: "<<distance[child-1]<<endl;
                    pq.push(make_pair(i+1,distance[i]));
                }
            }
        }
        cout<<".";
    }
    path.push_back(des);
    string methodName = "The method is dMatrix in A* method.";
    printS_D_A(path,position,cost,scr,des,methodName);
    //cout<<"Print F(n) for A* method in adjMatrix:";
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    output<<"Print F(n) for A* method in adjList:";
    output.close();
    Fn(path, position, cost,Msize);
}

void searchAlgo::printS_D_A(vector<int>p,vector<vector<int>>* position,vector<vector<float>>* cost,int scr,int des,string method_Name){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    for(int i = 0; i < p.size(); i++)
    {
        cout <<p[i] <<" ";
    }
    cout<<endl;
    cout<<"The total nodes explored in path is: "<<p.size()<<endl;
    output<<"The total nodes explored in path is: "<<p.size()<<endl;
    output.close();
    costCal(p, position,cost,method_Name);
    
}

void searchAlgo::Fn(std::vector<int>p, std::vector<std::vector<int> > *position, std::vector<std::vector<float> > *cost,int size){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    output<<"F(n) = distance(1+cost)"<<endl;
    int n,n1 = 0;
    float totalCost =0.0;
    float dist = 0;
    int power = 2;
    float x,x1;
    float y,y1;
    float z,z1;
    for(int i = 0;i<size-1;i++){
        totalCost=(*cost)[i][i+1];
        x = (*position)[i][0];
        y = (*position)[i][1];
        z = (*position)[i][2];
        x1 = (*position)[i+1][0];
        y1 = (*position)[i+1][1];
        z1 = (*position)[i+1][2];
        dist = pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
        output<<"F("<<i+1<<")="<<dist*(totalCost+1)<<endl;
    }
    output<<endl;
    output.close();
}

void searchAlgo::costCal(vector<int> path,vector<vector<int>>* position, vector<vector<float> > * cost,string method_Name){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    int n,n1=0;
    float totalCost =0.0;
    int dist = 0;
    int power = 2;
    int x,x1;
    int y,y1;
    int z,z1;
    for(int i = 0;i<path.size()-1;i++){
        n = path[i];
        n1 = path[i+1];
        totalCost+=(*cost)[n-1][n1-1];
        x = (*position)[i][0];
        y = (*position)[i][1];
        z = (*position)[i][2];
        x1 = (*position)[i+1][0];
        y1 = (*position)[i+1][1];
        z1 = (*position)[i+1][2];
        dist += pow((x1-x),power)+pow((y1-y),power)+pow((z1-z),power);
    }
    output<<endl;
    output<<"The total cost is: "<<totalCost<<endl;
    avr_cost.push_back(make_pair(method_Name, totalCost));
    //std::cout << "??????????????????????";
    
    int pSize = path.size();
    output<<"The total nodes in returned path is: "<<path.size()<<endl;
    Nodes_in_path.push_back(make_pair(method_Name, pSize));
    
    output<<"The total distance is: "<<dist<<endl;
    Dist.push_back(make_pair(method_Name, dist));
    cout<<"The total cost is: "<<totalCost<<endl;
    cout<<"The total nodes in returned path is: "<<path.size()<<endl;
    cout<<"The total distance is: "<<dist<<endl;
    //vis[scr-1] = true;
    cout<<endl;
    output<<endl;
    output.close();
    //averageOthers();
}

void searchAlgo::Stats(string methodName,vector<vector<int>>* position,vector<vector<float>>* cost){
    fstream output;
    output.open("OutputFile.txt",fstream::app);
    if(methodName == "Lr_DFS"){
        string methodName1 = "The method is adjList in DFS of recusive method.";
        cout<<"The recusive path for adjList in DFS is: ";
        for(int i = 0;i<path_r.size();i++){
        cout<<path_r[i]<<" ";
       }
        cout<<endl;
        cout<<"The total nodes explored in path is: "<<path_r.size()<<endl;
        output<<"The total nodes explored in path is: "<<path_r.size()<<endl;
        output.close();
        costCal(path_r, position,cost,methodName1);

    }
    else if (methodName == "Lr_BFS"){
        output.open("OutputFile.txt",fstream::app);
        string methodName2 = "The method is adjList in BFS of recusive method.";
        cout<<"The recusive path for adjList in BFS is: ";
        for(int i = 0;i<path_b.size();i++){
            cout<<path_b[i]<<" ";
        }
        cout<<endl;
        cout<<"The total nodes explored in path is: "<<explored.size()<<endl;
        output<<"The total nodes explored in path is: "<<explored.size()<<endl;
        output.close();
        costCal(path_b,position ,cost,methodName2);
    }
    else if (methodName == "Mr_DFS"){
        output.open("OutputFile.txt",fstream::app);
        string methodName3 = "The method is adjMatrix in DFS of recusive method.";
        cout<<"The recusive path for adjMartix in DFS is: ";
        for(int i = 0;i<path_d.size();i++){
            cout<<path_d[i]<<" ";
        }
        cout<<endl;
        cout<<"The total nodes explored in path is: "<<path_d.size()<<endl;
        output<<"The total nodes explored in path is: "<<path_d.size()<<endl;
        output.close();
        costCal(path_d, position,cost,methodName3);
    }
    else if (methodName == "Mr_BFS"){
        output.open("OutputFile.txt",fstream::app);
        string methodName4 = "The method is adjMatrix in BFS of recusive method.";
        cout<<"The recusive path for adjMartix in BFS is: ";
        for(int i = 0;i<path_m.size();i++){
            cout<<path_m[i]<<" ";
        }
        cout<<endl;
        cout<<"The total nodes explored in path is: "<<explored1.size()<<endl;
        output<<"The total nodes explored in path is: "<<explored1.size()<<endl;
        output.close();
        costCal(path_m, position,cost,methodName4);
    }
}

void searchAlgo::setTime( vector<pair<string, double>> *t){
    time = t;
}

void searchAlgo::averageTime(){
    string functionName1 = (*time)[0].first;
    string functionName2 = (*time)[1].first;
    string functionName3 = (*time)[2].first;
    string functionName4 = (*time)[3].first;
    string functionName5 = (*time)[4].first;
    string functionName6 = (*time)[5].first;
    string functionName7 = (*time)[6].first;
    string functionName8 = (*time)[7].first;
    string functionName9 = (*time)[8].first;
    string functionName10 = (*time)[9].first;
    string functionName11 = (*time)[10].first;
    string functionName12 = (*time)[11].first;
    float avrTime1 = 0.0;
    float avrTime2 = 0.0;
    float avrTime3 = 0.0;
    float avrTime4 = 0.0;
    float avrTime5 = 0.0;
    float avrTime6 = 0.0;
    float avrTime7 = 0.0;
    float avrTime8 = 0.0;
    float avrTime9 = 0.0;
    float avrTime10 = 0.0;
    float avrTime11 = 0.0;
    float avrTime12 = 0.0;
    
    for(int i = 0;i< time->size();i++){
        if(functionName1 == (*time)[i].first){
            avrTime1 += (*time)[i].second;
        }
        else if(functionName2 == (*time)[i].first){
            avrTime2 += (*time)[i].second;
        }
        else if(functionName3 == (*time)[i].first){
            avrTime3 += (*time)[i].second;
        }
        else if(functionName4 == (*time)[i].first){
            avrTime4 += (*time)[i].second;
        }
        else if(functionName5 == (*time)[i].first){
            avrTime5 += (*time)[i].second;
        }
        else if(functionName6 == (*time)[i].first){
            avrTime6 += (*time)[i].second;
        }
        else if(functionName7 == (*time)[i].first){
            avrTime7 += (*time)[i].second;
        }
        else if(functionName8== (*time)[i].first){
            avrTime8 += (*time)[i].second;
        }
        else if(functionName9 == (*time)[i].first){
            avrTime9 += (*time)[i].second;
        }
        else if(functionName10 == (*time)[i].first){
            avrTime10 += (*time)[i].second;
        }
        else if(functionName11 == (*time)[i].first){
            avrTime11 += (*time)[i].second;
        }
        else if(functionName12 == (*time)[i].first){
            avrTime12 += (*time)[i].second;
        }
    }
    cout<<functionName1<<". The average execution time is: "<<avrTime1/100<<"s"<<endl;
    cout<<functionName2<<". The average execution time is: "<<avrTime2/100<<"s"<<endl;
    cout<<functionName3<<". The average execution time is: "<<avrTime3/100<<"s"<<endl;
    cout<<functionName4<<". The average execution time is: "<<avrTime4/100<<"s"<<endl;
    cout<<functionName5<<". The average execution time is: "<<avrTime5/100<<"s"<<endl;
    cout<<functionName6<<". The average execution time is: "<<avrTime6/100<<"s"<<endl;
    cout<<functionName7<<". The average execution time is: "<<avrTime7/100<<"s"<<endl;
    cout<<functionName8<<". The average execution time is: "<<avrTime8/100<<"s"<<endl;
    cout<<functionName9<<". The average execution time is: "<<avrTime9/100<<"s"<<endl;
    cout<<functionName10<<". The average execution time is: "<<avrTime10/100<<"s"<<endl;
    cout<<functionName11<<". The average execution time is: "<<avrTime11/100<<"s"<<endl;
    cout<<functionName12<<". The average execution time is: "<<avrTime12/100<<"s"<<endl;
    
}

void searchAlgo::averageOthers(){
    string functionName1 = avr_cost[0].first;
    string functionName2 = avr_cost[1].first;
    string functionName3 = avr_cost[2].first;
    string functionName4 = avr_cost[3].first;
    string functionName5 = avr_cost[4].first;
    string functionName6 = avr_cost[5].first;
    string functionName7 = avr_cost[6].first;
    string functionName8 = avr_cost[7].first;
    string functionName9 = avr_cost[8].first;
    string functionName10 = avr_cost[9].first;
    string functionName11 = avr_cost[10].first;
    string functionName12 = avr_cost[11].first;
    
    ///////////////////////////////////////////
    string functionName_1 = Dist[0].first;
    string functionName_2 = Dist[1].first;
    string functionName_3 = Dist[2].first;
    string functionName_4 = Dist[3].first;
    string functionName_5 = Dist[4].first;
    string functionName_6 = Dist[5].first;
    string functionName_7 = Dist[6].first;
    string functionName_8 = Dist[7].first;
    string functionName_9 = Dist[8].first;
    string functionName_10 = Dist[9].first;
    string functionName_11 = Dist[10].first;
    string functionName_12 = Dist[11].first;
    
    ///////////////////////////////////////////////
    string functionName__1 = Nodes_in_path[0].first;
    string functionName__2 = Nodes_in_path[1].first;
    string functionName__3 = Nodes_in_path[2].first;
    string functionName__4 = Nodes_in_path[3].first;
    string functionName__5 = Nodes_in_path[4].first;
    string functionName__6 = Nodes_in_path[5].first;
    string functionName__7 = Nodes_in_path[6].first;
    string functionName__8 = Nodes_in_path[7].first;
    string functionName__9 = Nodes_in_path[8].first;
    string functionName__10 = Nodes_in_path[9].first;
    string functionName__11 = Nodes_in_path[10].first;
    string functionName__12 = Nodes_in_path[11].first;
    
    ////////////////////////////////////////////////
    float totalCost1 = 0.0;
    float totalCost2 = 0.0;
    float totalCost3 = 0.0;
    float totalCost4 = 0.0;
    float totalCost5 = 0.0;
    float totalCost6 = 0.0;
    float totalCost7 = 0.0;
    float totalCost8 = 0.0;
    float totalCost9 = 0.0;
    float totalCost10 = 0.0;
    float totalCost11 = 0.0;
    float totalCost12 = 0.0;
    /////////////////////////
    int totalNode1 = 0;
    int totalNode2 = 0;
    int totalNode3 = 0;
    int totalNode4 = 0;
    int totalNode5 = 0;
    int totalNode6 = 0;
    int totalNode7 = 0;
    int totalNode8 = 0;
    int totalNode9 = 0;
    int totalNode10 = 0;
    int totalNode11 = 0;
    int totalNode12 = 0;
    //////////////////////////////
    int totalDist1 = 0;
    int totalDist2 = 0;
    int totalDist3 = 0;
    int totalDist4 = 0;
    int totalDist5 = 0;
    int totalDist6 = 0;
    int totalDist7 = 0;
    int totalDist8 = 0;
    int totalDist9 = 0;
    int totalDist10 = 0;
    int totalDist11 = 0;
    int totalDist12 = 0;
    //////////////////////////
    
    for(int i =0;i<avr_cost.size();i++){
        if(functionName1 == avr_cost[i].first){
            totalCost1 += avr_cost[i].second;
        }
        else if(functionName2 == avr_cost[i].first){
            totalCost2 += avr_cost[i].second;
        }
        else if(functionName3 == avr_cost[i].first){
            totalCost3 += avr_cost[i].second;
        }
        else if(functionName4 == avr_cost[i].first){
            totalCost4 += avr_cost[i].second;
        }
        else if(functionName5 == avr_cost[i].first){
            totalCost5 += avr_cost[i].second;
        }
        else if(functionName6 == avr_cost[i].first){
            totalCost6 += avr_cost[i].second;
        }
        else if(functionName7 == avr_cost[i].first){
            totalCost7 += avr_cost[i].second;
        }
        else if(functionName8 == avr_cost[i].first){
            totalCost8 += avr_cost[i].second;
        }
        else if(functionName9 == avr_cost[i].first){
            totalCost9 += avr_cost[i].second;
        }
        else if(functionName10 == avr_cost[i].first){
            totalCost10 += avr_cost[i].second;
        }
        else if(functionName11 == avr_cost[i].first){
            totalCost11 += avr_cost[i].second;
        }
        else if(functionName12 == avr_cost[i].first){
            totalCost12 += avr_cost[i].second;
        }
    }
    cout<<functionName1<<". The average cost is: "<<totalCost1/100<<endl;
    cout<<functionName2<<". The average cost is: "<<totalCost2/100<<endl;
    cout<<functionName3<<". The average cost is: "<<totalCost3/100<<endl;
    cout<<functionName4<<". The average cost is: "<<totalCost4/100<<endl;
    cout<<functionName5<<". The average cost is: "<<totalCost5/100<<endl;
    cout<<functionName6<<". The average cost is: "<<totalCost6/100<<endl;
    cout<<functionName7<<". The average cost is: "<<totalCost7/100<<endl;
    cout<<functionName8<<". The average cost is: "<<totalCost8/100<<endl;
    cout<<functionName9<<". The average cost is: "<<totalCost9/100<<endl;
    cout<<functionName10<<". The average cost is: "<<totalCost10/100<<endl;
    cout<<functionName11<<". The average cost is: "<<totalCost11/100<<endl;
    cout<<functionName12<<". The average cost is: "<<totalCost12/100<<endl;
/////////////////////////////////////////////////////////////////////////////////////
    
    for(int j = 0;j<Dist.size();j++){
        if(functionName_1 == Dist[j].first){
            totalDist1 += Dist[j].second;
        }
        else if(functionName_2 == Dist[j].first){
            totalDist2 += Dist[j].second;
        }
        else if(functionName_3 == Dist[j].first){
            totalDist3 += Dist[j].second;
        }
        else if(functionName_4 == Dist[j].first){
            totalDist4 += Dist[j].second;
        }
        else if(functionName_5 == Dist[j].first){
            totalDist5 += Dist[j].second;
        }
        else if(functionName_6 == Dist[j].first){
            totalDist6 += Dist[j].second;
        }
        else if(functionName_7 == Dist[j].first){
            totalDist7 += Dist[j].second;
        }
        else if(functionName_8 == Dist[j].first){
            totalDist8 += Dist[j].second;
        }
        else if(functionName_9 == Dist[j].first){
            totalDist9 += Dist[j].second;
        }
        else if(functionName_10 == Dist[j].first){
            totalDist10 += Dist[j].second;
        }
        else if(functionName_11 == Dist[j].first){
            totalDist11 += Dist[j].second;
        }
        else if(functionName_12 == Dist[j].first){
            totalDist12 += Dist[j].second;
        }
    }
    cout<<functionName_1<<". The average distance is: "<<totalDist1/100<<endl;
    cout<<functionName_2<<". The average distance is: "<<totalDist2/100<<endl;
    cout<<functionName_3<<". The average distance is: "<<totalDist3/100<<endl;
    cout<<functionName_4<<". The average distance is: "<<totalDist4/100<<endl;
    cout<<functionName_5<<". The average distance is: "<<totalDist5/100<<endl;
    cout<<functionName_6<<". The average distance is: "<<totalDist6/100<<endl;
    cout<<functionName_7<<". The average distance is: "<<totalDist7/100<<endl;
    cout<<functionName_8<<". The average distance is: "<<totalDist8/100<<endl;
    cout<<functionName_9<<". The average distance is: "<<totalDist9/100<<endl;
    cout<<functionName_10<<". The average distance is: "<<totalDist10/100<<endl;
    cout<<functionName_11<<". The average distance is: "<<totalDist11/100<<endl;
    cout<<functionName_12<<". The average distance is: "<<totalDist12/100<<endl;
    //////////////////////////////////////////////////////////////////////////////////
    
    for(int k = 0;k<Nodes_in_path.size();k++){
        if(functionName__1 == Nodes_in_path[k].first){
            totalNode1 += Nodes_in_path[k].second;
        }
        else if(functionName__2 == Nodes_in_path[k].first){
            totalNode2 += Nodes_in_path[k].second;
        }
        else if(functionName__3 == Nodes_in_path[k].first){
            totalNode3 += Nodes_in_path[k].second;
        }
        else if(functionName__4 == Nodes_in_path[k].first){
            totalNode4+= Nodes_in_path[k].second;
        }
        else if(functionName__5 == Nodes_in_path[k].first){
            totalNode5 += Nodes_in_path[k].second;
        }
        else if(functionName__6 == Nodes_in_path[k].first){
            totalNode6 += Nodes_in_path[k].second;
        }
        else if(functionName__7 == Nodes_in_path[k].first){
            totalNode7 += Nodes_in_path[k].second;
        }
        else if(functionName__8 == Nodes_in_path[k].first){
            totalNode8 += Nodes_in_path[k].second;
        }
        else if(functionName__9 == Nodes_in_path[k].first){
            totalNode9 += Nodes_in_path[k].second;
        }
        else if(functionName__9 == Nodes_in_path[k].first){
            totalNode9 += Nodes_in_path[k].second;
        }
        else if(functionName__10 == Nodes_in_path[k].first){
            totalNode10 += Nodes_in_path[k].second;
        }
        else if(functionName__11 == Nodes_in_path[k].first){
            totalNode11 += Nodes_in_path[k].second;
        }
        else if(functionName__12 == Nodes_in_path[k].first){
            totalNode12 += Nodes_in_path[k].second;
        }
    }
    cout<<functionName__1<<". The average number of Nodes in each path is: "<<totalNode1/100<<endl;
    cout<<functionName__2<<". The average number of Nodes in each path is: "<<totalNode2/100<<endl;
    cout<<functionName__3<<". The average number of Nodes in each path is: "<<totalNode3/100<<endl;
    cout<<functionName__4<<". The average number of Nodes in each path is: "<<totalNode4/100<<endl;
    cout<<functionName__5<<". The average number of Nodes in each path is: "<<totalNode5/100<<endl;
    cout<<functionName__6<<". The average number of Nodes in each path is: "<<totalNode6/100<<endl;
    cout<<functionName__7<<". The average number of Nodes in each path is: "<<totalNode7/100<<endl;
    cout<<functionName__8<<". The average number of Nodes in each path is: "<<totalNode8/100<<endl;
    cout<<functionName__9<<". The average number of Nodes in each path is: "<<totalNode9/100<<endl;
    cout<<functionName__10<<". The average number of Nodes in each path is: "<<totalNode10/100<<endl;
    cout<<functionName__11<<". The average number of Nodes in each path is: "<<totalNode11/100<<endl;
    cout<<functionName__12<<". The average number of Nodes in each path is: "<<totalNode12/100<<endl;
    
}
