//
//  Graph.hpp
//  lab2
//
//  Created by MollyYu on 10/12/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include "adjList.hpp"
class Graph{
public:
    void loadGraph(std::string);
    int weightGraph();
    int positionGraph();
    void display();
private:
    int weight;
    int position;
    adjList adj;
};
#endif /* Graph_hpp */
