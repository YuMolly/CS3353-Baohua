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
    //Algorithm *a = new sort();
    std::vector<int> b;
    std::vector<std::string> filename;
    int counter = 0;
    filename = {
        "100000random.txt",
        "100000reversed.txt",
        "100000unique.txt",
        "100000partial.txt"
        
    };
    /*
    for(int i=0;i<6;i++){
        //loop all algos
        b = a->load(filename.at(i));
        counter++;
        cout<<"The counter is"<<counter<<endl;
        for(int j=0;j<filename.size();j++){
            // loop all data files
            b = a->load(filename.at(i));
            //a->select();
            a->execute();
        }
    }
    for(int i =0; i<b.size();i++)
        cout<<"b is : "<<b.at(i)<<endl;
    
    cout<<"Here!"<<endl;
     */
}
