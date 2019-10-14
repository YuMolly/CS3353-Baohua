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
    weight = 0;
    position = 0;
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
    /*string temp,scr,des;
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
        
    }*/
    file.close();
    ////////////
    ////////////
    /*float weights;
    int pos1,pos2;
    string b;
    string node1,node2;
    string leave,cost;
    while(w){
        while(getline(w,b)){
            pos1 = b.find(',');
            node1 = b.substr(0,pos1);
            leave = b.substr(pos1+1,b.length()-pos1+1);
            pos2 = leave.find(',');
            node2 = leave.substr(0,leave.find(','));
            cost = leave.substr(pos2+1,leave.length());
            //cout<<"node1 is:"<<node1<<endl;
            //cout<<"node2 is:"<<node2<<endl;
            //cout<<"cost is:"<<cost<<endl;
            weights = stof(cost);
            //cout<<"weights is:"<<weights<<endl;
            
            //adM->Cost(node1,node2,weights);
        }
        
    }
    w.close();*/
    //////////
    //////////
    /*int x,y,z;
    int pos3,pos4,pos5;
    string c;
    string node3,dem;
    while(p){
        while(getline(p,c)){
            pos3 = c.find(',');
            node3 = c.substr(0,pos3);
            dem = c.substr(pos3+1,c.length()-pos3+1);
            pos4 = dem.find(',');
            x = stoi(dem.substr(0,pos4));
            dem = dem.substr(pos4+1,dem.length()-pos4+1);
            pos5 = dem.find(',');
            y = stoi(dem.substr(0,pos5));
            z = stoi(dem.substr(pos5+1));
            //cout<<"Node3 is: "<<node3<<endl;
            //cout<<"x is: "<<x<<endl;
            //cout<<"y is: "<<y<<endl;
            //cout<<"z is: "<<z<<endl;
        }
        
    }
    p.close();*/
}


void Graph::DFS(string x,string y){
    //select which search algo need to be compile
    int scr,des;
    searchAlgo*temp;
    temp = new searchAlgo(depth);
    search = temp;
    scr = stoi(x);
    des = stoi(y);
    vector<vector<int>> temp1;
    temp1= adj->getList();
    search->SL_DFS(temp1,scr, des);
}


void Graph::display(){
    //adj->display();
    //adM->display();
    search->display();
}
