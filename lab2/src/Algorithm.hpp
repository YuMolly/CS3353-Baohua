//
//  Algorithm.hpp
//  data_generator
//
//  Created by MollyYu on 9/9/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


class Algorithm{
public:
    virtual std::vector<int> load(std::string) = 0;
    enum selection{
        BUBBLE = 0,
        MERGE = 1,
        INSERTION = 2
    };
    selection select();
    virtual void execute(std::vector<int>&,int,int) = 0;
    virtual void display() = 0;
    virtual void state() = 0;
    virtual void save(std::string,std::string) = 0;
};
#endif /* Algorithm_hpp */

