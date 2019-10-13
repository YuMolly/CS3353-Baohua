//
//  Graph.cpp
//  lab2
//
//  Created by MollyYu on 10/12/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "Graph.hpp"
//#include "adjList.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void Graph::loadGraph(string filename){
    ifstream file;
    file.open(filename);
    string a;
    string h;
    string head;
    //int length =0;
    if(!file)
        cout<<"The file fail to open"<<endl;
    else
        cout<<"The file can open successfully!"<<endl;
    
    while(file){
        // file can successfully open
        //getline string store in a
        while(getline(file,a)){
            //cout<<a<<endl;
            head = a.substr(0,a.find(','));
            //cout << "header: " << head << endl;
            a = a.substr(a.find(',')+1,a.length()-a.find(',')+1);
            while((a.find(',') != string::npos)){
                    h = a.substr(0,a.find(','));
                    adj.addEdge(head,h);
                    //cout<<"h1 is "<<h<<endl;
                a = a.substr(a.find(',')+1,a.length()-a.find(',')+1);
            }
            adj.addEdge(head,a);
            
            
        }
    }
    
    
    file.close();
}

void Graph::display(){
    adj.display();
}
