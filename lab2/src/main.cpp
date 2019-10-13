//
//  main.cpp
//  lab2
//
//  Created by Bill on 10/13/19.
//  Copyright © 2019 Molly Yu. All rights reserved.
//

#include <stdio.h>
#include "Graph.hpp"


int main(){
    Graph a;
    a.loadGraph("graph.txt");
    a.display();
}
