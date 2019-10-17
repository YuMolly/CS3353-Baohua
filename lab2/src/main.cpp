//
//  main.cpp
//  lab2
//
//  Created by MollyYu on 10/13/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Graph.hpp"
using namespace std;

int main(int argc, char** argv){
    Graph a;
    
    a.loadGraph("largeGraph.txt","largeWeights.txt","largePositions.txt");
    
    //for test
    for(int i = 0;i<100;i++){//run 100 times
        srand(time(NULL));
        int scr = rand()%2500+1;
        int des = rand()%2500+1;
        a.DFS(scr,des);
        
        a.BFS(scr, des);
               
        a.Stats("Lr_DFS");
        a.Stats("Lr_BFS");
        a.Stats("Mr_DFS");
        a.Stats("Mr_BFS");
        a.Dijkstra(scr,des);
        a.A_star(scr, des);
        
        //a.printTime();
        a.sentTime();
        //a.AVG();
    }
    
    a.AVG();
    /*string x =  argv[1];
    string y =  argv[2];
    int scr = stoi(x);
    int des = stoi(y);*/
    //a.DFS(scr,des);
    //a.BFS(scr, des);
    //a.Dijkstra(scr,des);
    //a.A_star(scr, des);
    //a.Stats("Lr_DFS");
    //a.Stats("Lr_BFS");
    //a.Stats("Mr_DFS");
    //a.Stats("Mr_BFS");
    //a.printTime();
    
}
