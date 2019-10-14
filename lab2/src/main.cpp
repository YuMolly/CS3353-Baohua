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
    string scr = "5";
    string des = "15";
    a.DFS(scr,des);
    a.display();
}
