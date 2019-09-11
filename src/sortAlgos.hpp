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

};
#endif /* sortAlgos_hpp */
