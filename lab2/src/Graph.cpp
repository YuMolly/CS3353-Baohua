//
//  Graph.cpp
//  lab2
//
//  Created by MollyYu on 10/12/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "Graph.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

Graph::Graph(){
    depth = 0;
    wei = 0;
    adM = nullptr;
    adj = nullptr;
    search = nullptr;
    
}

Graph::~Graph(){
    delete adM;
    delete adj;
    delete search;
}

void Graph::loadGraph(string filename,string weight,string position){
    // graph file
    ifstream file;
    file.open(filename);
    //weights file
    ifstream w;
    w.open(weight);
    //position file
    ifstream p;
    p.open(position);
    
    if(!file)
        cout<<"The "<<filename<<" file fail to open"<<endl;
    else
        cout<<"The "<<filename<<" file can open successfully!"<<endl;
    if(!w)
        cout<<"The "<<weight<<" file fail to open"<<endl;
    else
        cout<<"The "<<weight<<" file can open successfully!"<<endl;
    if(!p)
        cout<<"The "<<position<<" file fail to open"<<endl;
    else
        cout<<"The "<<position<<" file can open successfully!"<<endl;
   
    cout<<endl;
    
    string a,h,head;
    vector<string> header;
    vector<string> child;
    adjMatrix *temp1;
    adjList *temp2;
    temp2 = new adjList();
    adj = temp2;
while(file){
    // for adjList
    while(getline(file,a)){
        depth++;
        head = a.substr(0,a.find(','));
        header.push_back(head);
        a = a.substr(a.find(',')+1,a.length()-a.find(',')+1);
        child.push_back(a);
        while((a.find(',') != string::npos)){
            h = a.substr(0,a.find(','));
            adj->addEdge(head,h);
            a = a.substr(a.find(',')+1,a.length()-a.find(',')+1);
        }
        adj->addEdge(head,a);
    }
}
    //for adjMatrix
    string temp,scr,des;
    int pos;
    temp1 = new adjMatrix(depth);
    adM = temp1;
    for(int i = 0; i<depth;i++){
        scr = header[i];
        temp = child[i];//15,12...
        for(int j = 0;j<temp.size();j++){
            pos = temp.find(',');
            des = temp.substr(0,pos);
            temp = temp.substr(pos+1,temp.length());
            adM->addEdge(scr, des);
        }
        adM->addEdge(scr, temp);
        
    }
    file.close();
    ////////////
    ////////////
    float weights;
    int pos1,pos2;
    int depth1;
    string b;
    string node1,node2;
    int n1,n2;
    string leave,cost1;
    while(w){
        while(getline(w,b)){
            pos1 = b.find(',');
            node1 = b.substr(0,pos1);
            n1 = stoi(node1);
            leave = b.substr(pos1+1,b.length()-pos1+1);
            pos2 = leave.find(',');
            node2 = leave.substr(0,leave.find(','));
            n2 = stoi(node2);
            cost1 = leave.substr(pos2+1,leave.length());
            weights = stof(cost1);
            //cout<<"weights is :"<<weights<<endl;
            //depth1++;
            for(int i = cost.size(); i<n1; i++){
                vector<float> t1;
                cost.push_back(t1);
            }
            for(int j = cost[n1-1].size();j<n2;j++){
                cost[n1-1].push_back(0);
            }
            cost[n1-1][n2-1] = weights;
            //Cost(node1,node2,weights);
        }
        
    }
    w.close();
    //////////
    //////////
    int x,y,z;
    int pos3,pos4,pos5;
    int n3;
    string c;
    string node3,dem;
    while(p){
        while(getline(p,c)){
            pos3 = c.find(',');
            node3 = c.substr(0,pos3);
            n3 = stoi(node3);
            dem = c.substr(pos3+1,c.length()-pos3+1);
            pos4 = dem.find(',');
            x = stoi(dem.substr(0,pos4));
            dem = dem.substr(pos4+1,dem.length()-pos4+1);
            pos5 = dem.find(',');
            y = stoi(dem.substr(0,pos5));
            z = stoi(dem.substr(pos5+1));
            for(int i = node_position.size();i<n3;i++){
                vector<int> t2;
                node_position.push_back(t2);
            }
            for(int j = node_position[n3-1].size();j<3;j++){
                node_position[n3-1].push_back(0);
            }
            node_position[n3-1][0] = x;
            node_position[n3-1][1] = y;
            node_position[n3-1][2] = z;
        }
        
    }
    p.close();
}


vector<vector<float>> Graph::getCost(){
    return cost;
}
vector<vector<int>> Graph::getPosition(){
    return node_position;
}

void Graph::DFS(int scr,int des){
    //select which search algo need to be compile
    searchAlgo*Nsearch;
    Nsearch = new searchAlgo(depth,scr);
    search = Nsearch;
    vector<vector<int>> temp1;//get adjlist
    int ** temp2;//get adjmatrix
    int matrixS;//get matrix size
    temp1= adj->getList();
    temp2 = adM->getMatrix();
    matrixS = adM->getMatrixSize();
    int* columnSize = adM->columnSize();
    vector<bool>v(temp1.size(),false);
    search->SLr_DFS(&v,temp1, scr, des);
    search->SLi_DFS(temp1,scr, des);
    //search->SMr_DFS(&v, temp2, matrixS,scr, des);
    //search->SMi_DFS(temp2,columnSize,matrixS, scr, des);
}

void Graph::BFS(int scr,int des){
    //select which search algo need to be compile
    searchAlgo*Nsearch;
    Nsearch = new searchAlgo(depth,scr);
    search = Nsearch;
    vector<vector<int>> temp1;//get adjlist
    int ** temp2;//get adjmatrix
    int matrixS;//get matrix size
    temp1= adj->getList();
    temp2 = adM->getMatrix();
    matrixS = adM->getMatrixSize();
    int* columnSize = adM->columnSize();
    vector<bool>v(temp1.size(),false);
    //search->SLr_BFS(&v,temp1,scr,des);
    //search->SLi_BFS(temp1,scr, des);
    //search->SMr_BFS(&v, temp2, matrixS,scr, des);
    //search->SMi_BFS(temp2,columnSize,matrixS, scr, des);
}

void Graph::Dijkstra(int scr,int des){
    searchAlgo*Nsearch;
    Nsearch = new searchAlgo(depth,scr);
    search = Nsearch;
    vector<vector<int>> temp1;//get adjlist
    int ** temp2;//get adjmatrix
    int matrixS;//get matrix size
    temp1= adj->getList();
    temp2 = adM->getMatrix();
    matrixS = adM->getMatrixSize();
    int* columnSize = adM->columnSize();
    vector<bool>v(temp1.size(),false);
    search->SL_Dijkstra(&cost, temp1, scr, des);
    //search->SM_Dijkstra(&cost,temp2,matrixS,scr,des);
}

void Graph::A_star(int scr, int des){
    searchAlgo*Nsearch;
    Nsearch = new searchAlgo(depth,scr);
    search = Nsearch;
    vector<vector<int>> temp1;//get adjlist
    int ** temp2;//get adjmatrix
    int matrixS;//get matrix size
    temp1= adj->getList();
    temp2 = adM->getMatrix();
    matrixS = adM->getMatrixSize();
    int* columnSize = adM->columnSize();
    vector<bool>v(temp1.size(),false);
    //search->SL_A_star(&node_position,&cost,temp1,scr,des);
    search->SM_A_star(&node_position,&cost,temp2,scr,des);
}

void Graph::Stats(string methodName){
    //adj->Stats();
    //adM->Stats();
    search->Stats(methodName);
}

void Graph::printcost(){
    for(int i = 0;i<cost.size();i++){
        
        for(int j=0;j<cost[i].size();j++){
            cout<<"From node :"<<i+1;
            cout<<" -> "<<j+1<<" cost is: "<< cost[i][j]<<endl;
        }
    }
}

void Graph::printPosition(){
    for(int i = 0;i<node_position.size();i++){
        cout<<"The position for "<<i+1<<" is "<<"( "<<node_position[i][0]<<",";
        cout<<node_position[i][1]<<","<<node_position[i][2]<<" )"<<endl;
    }
}
