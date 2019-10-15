//
//  main.cpp
//  lab2
//
//  Created by MollyYu on 10/13/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Graph.hpp"
using namespace std;

int main(){
    Graph a;
    a.loadGraph("graph.txt","weights.txt","positions.txt");
    string x =  "1";
    string y = "6";
    int scr,des;
    scr = stoi(x);
    des = stoi(y);
    //a.DFS(scr,des);
    a.BFS(scr, des);
    //a.Dijkstra(scr,des);
    //a.Stats("Mr_BFS");
    //a.printcost();
}
