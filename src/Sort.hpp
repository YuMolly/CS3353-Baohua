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
#include "Algorithm.hpp"

class Sort : public Algorithm{
public:
    Sort();
    ~Sort();
    std::vector<int> load(std::string);
    //void execute();
};
#endif /* Sort_hpp */
