//
//  data_generator.h
//  data_generator
//
//  Created by MollyYu on 9/6/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef data_generator_h
#define data_generator_h
#include<iostream>
#include<string>
class data_generator {
public:
    void random_data();
    void revesed_data();
    void unique_data();
    void partial_data();
    void readfile();
    void writefile();
    void bubble();
    void insertion();
    void mergeCut(int*,int,int);
    void merge(int*,int,int,int);
};
#endif /* data_generator_h */
