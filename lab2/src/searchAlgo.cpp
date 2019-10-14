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
    /*for(int i = 0;i<100;i++){
        visited[i] = false;
    }*/
    
}
void searchAlgo::SLr_DFS(vector<vector<int>> adj, int scr,int des){
    cout<<"Here"<<endl;
    int temp = 0;
    int t,s;
    /*
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
    }*/
   /* int c;
    visited[scr] = true;
    cout<<scr<<" ";
    if(c == scr){
        cout<<"done"<<endl;
    }
    else{
        for(int child:adj[scr]){
            c = child;
            if(!visited[child]){
                SLr_DFS(adj, child, des);
            }
        }
    }*/
}

void searchAlgo::SLi_DFS(std::vector<std::vector<int>> adj, int scr,int des){
    vector<bool> visited(adj.size(),false);
    stack<int>path;
    path.push(scr);
    //int s;
    int temp1,temp2;
    int count;
    int counter = -1;
    //scr = path.top();
    while(!visited[des-1]){
        //cout<<"adj: "<<adj[scr-1].size();
        count = 0;
        for(int j = 0;j<adj[scr-1].size();j++){
            
            temp1 = adj[scr-1][j];
            //cout<<"temp1 "<<temp1<<" ";
            //cout<<"temp1: "<<temp1<<" ";
            if(visited[temp1-1]){
                count++;
                //cout<<"count: "<<count<<" ";
            }
            if(count == adj[scr-1].size()){
               
                path.pop();
                //temp2 = path.top();
                break;
            }
        }
            scr = path.top();
            //cout<<"ha"<<scr<<" ";
            if(!visited[scr-1]){
                
                //cout<<"path is: "<<scr<<" ";
                visited[scr-1] = true;
            }
            //size = adj[scr].size();
            //int j = 1;
        
            for (int i = 0; i <= adj[scr-1].size(); ++i){
                //s = adj[scr-1].size();
                //cout<<"the size is: "<<s<<endl;
                counter++;
                int temp = adj[scr-1][counter];
                //cout<<temp<<endl;
                if (!visited[temp-1]){
                    scr = temp;
                    path.push(temp);
                    visited[temp-1] = true;
                    counter = -1;
                    //s = path.top();
                    //cout<<s<<" ";
                }
                if(visited[des-1]){
                    break;
                }
                
            }
    }
    //path.push(des);
    cout<<"path is: ";
    stack<int>s;
    int t;
    while(!path.empty()){
        t = path.top();
        //cout<<path.top()<<"<- ";
        path.pop();
        s.push(t);
    }
    while(!s.empty()){
        //t = s.top();
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void searchAlgo::display(){
 
    
}
