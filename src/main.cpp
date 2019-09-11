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
//#include "data_generator.h"
//#include "Algorithm.hpp"
#include "Sort.hpp"
//#include "sortAlgos.hpp"
enum selection{
    BUBBLE = 0,
    MERGE = 1,
    INSERTION = 2
} select;

int main(){
    //srand(time(NULL));
    //data_generator r;
    //r.random_data();
    //r.revesed_data();
    //r.unique_data();
    //r.partial_data();
    //r.readfile();
    //r.writefile();
    //r.bubble();
    //r.insertion();
    //int a[] = {9,2,4,6,3,8,1,0};
    //r.mergeCut(a,0,7);
    
    Algorithm *a = new Sort();
    Sort sel;
    std::vector<int> b;
    //std::vector<std::string> filename;
    std::vector<std::string> filename1;
    int counter = 0;
    /*filename = {
        "100000random.txt",
        "100000reversed.txt",
        "100000unique.txt",
        "100000partial.txt"
        
    };*/
    filename1 = {
        "1000random.txt",
        "1000reversed.txt",
        "1000unique.txt",
        "1000partial.txt"
        
    };
    
    for(int i=0;i<4;i++){
        //loop all algos
        //counter++;
        //std::cout<<"The counter is"<<counter<<std::endl;
        b = a->load(filename1.at(i));
        std::cout<<"the file name is:"<<filename1.at(i)<<std::endl;
        for(int j=0;j<7;j++){
            // loop all data files
            //b = a->load(filename.at(j));
            sel.Setselect(Sort::BUBBLE);
            a->execute(b,0,b.size()-1);
            a->display();
            sel.Setselect(Sort::MERGE);
            a->execute(b,0,b.size()-1);
            a->display();
            sel.Setselect(Sort::INSERTION);
            a->execute(b,0,b.size()-1);
            a->display();
        }
    }
    //for(int i =0; i<b.size();i++)
        //std::cout<<"b is : "<<b.at(i)<<std::endl;
    
    std::cout<<"Here!"<<std::endl;
    return 0;
    
}
