//
//  Sort.hpp
//  data_generator
//
//  Created by MollyYu on 9/11/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <vector>
#include "Algorithm.hpp"

class Sort : public Algorithm{
public:
    Sort();
    ~Sort();
    std::vector<int> load(std::string);
    void Setselect(Sort::selection);
    selection select();
    void execute(std::vector<int>&,int,int);
    void display();
    void state();
    void save(std::string,std::string);
private:
    std::vector<int> sorted;
    selection my_select;
    int counter;
    std::chrono::duration<double> time_span;
};
#endif /* Sort_hpp */
