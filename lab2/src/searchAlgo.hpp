//
//  searchAlgo.hpp
//  lab2
//
//  Created by MollyYu on 10/7/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef searchAlgo_hpp
#define searchAlgo_hpp

#include <stdio.h>

class searchAlgo{
public:
    void DFS(int,int);
    void BFS(int,int);
    void Dijkstra(int,int);
    void A_star(int,int);
};
#endif /* searchAlgo_hpp */
