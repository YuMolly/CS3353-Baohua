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
    enum selection{
        BUBBLE = 0,
        MERGE = 1,
        INSERTION = 2
    };
    void Setselect(Sort::selection);
    selection select();
    void execute(std::vector<int>&,int,int);
    void display();
private:
    std::vector<int> sorted;
    selection my_select;
};
#endif /* Sort_hpp */
