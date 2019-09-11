//
//  sortAlgos.cpp
//  data_generator
//
//  Created by MollyYu on 9/9/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "sortAlgos.hpp"
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

void sortAlgos::bubble(){
    int size = 10;
    int number[] = {3,4,6,2,8,1,5,6,2,5};
    int pre,curr = 0;
    for (int i =1;i<size;i++){
        for(int j = 1; j < size;j++){
            if(number[j] < number[j-1]){
                curr = number[j-1];
                pre = number[j];
                number[j-1] = pre;
                number[j] = curr;
            }
        }
    }
}
