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
//using namespace std;

class Algorithm{
public:
    virtual std::vector<int> load(std::string) = 0;
    /*enum selection{
        BUBBLE = 0,
        MERGE,
        INSERTION,
        LAST
    };*/
    //selection select();
    //virtual void execute() = 0;
    //virtual void display();
    //virtual void stats();
    //virtual void save();
//private:
    //Algorithm::selection my_select;
};
#endif /* Algorithm_hpp */

