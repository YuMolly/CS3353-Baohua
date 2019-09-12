//
//  main.cpp
//  data_generator
//
//  Created by MollyYu on 9/6/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <vector>
#include "Sort.hpp"
enum selection{
    BUBBLE = 0,
    MERGE = 1,
    INSERTION = 2
};

int main(){
    Sort a;
    std::string path;
    std::vector<int> b;
    std::vector<std::string> filename;
    filename = {
        "100000random.txt",
        "100000reversed.txt",
        "100000unique.txt",
        "100000partial.txt"
        
    };
    
    for(int i=0;i<3;i++)
        {
        if(i == 0)
        {
            a.Setselect(Sort::BUBBLE);
            std::cout << "Bubble" << std::endl;
        }
        else if(i == 1)
        {
            a.Setselect(Sort::MERGE);
            std::cout << "Merge" << std::endl;
        }
        else if (i ==2)
        {
            a.Setselect(Sort::INSERTION);
            std::cout << "Insertion" << std::endl;
        }
        for(int j=0;j<4;j++){
            b = a.load(filename.at(j));
            std::cout<<"the file name is:"<<filename.at(j)<<std::endl;
            a.execute(b,0,b.size()-1);
            a.state();
            a.save(path, filename.at(j));

      }
    }
    std::cout<<"Done!"<<std::endl;
    return 0;
    
}
