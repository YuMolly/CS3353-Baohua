//
//  sortAlgos.hpp
//  data_generator
//
//  Created by MollyYu on 9/9/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef sortAlgos_hpp
#define sortAlgos_hpp
#include "Sort.hpp"

class sortAlgos{
public:
    void bubble(std::vector<int>&);
    void mergeCut(std::vector<int>&,int,int);
    void merge(std::vector<int>&,int,int,int);
    void insertion(std::vector<int>&);
    int getCounter();
    std::chrono::duration<double> getTime();
private:
    int counter = 0;
    std::chrono::duration<double> time_span;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
};
#endif /* sortAlgos_hpp */
