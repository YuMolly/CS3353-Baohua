//
//  Sort.cpp
//  data_generator
//
//  Created by MollyYu on 9/11/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "Sort.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
Sort::Sort(){
    //cout<<"The funciton is working"<<endl;
}
Sort::~Sort(){
    //cout<<"!!"<<endl;
}
vector<int> Sort::load(string filename){
    ifstream file;
    file.open(filename);
    int a;
    vector<int> num;
    if(!file)
        cout<<"The file fail to open"<<endl;
    else
        cout<<"The file can open successfully!"<<endl;
    while(file){
        file>>a;
        num.push_back(a);
    }
    file.close();
    return num;
}
/*
 void Algorithm::::setSelection(Algorithm::selection select){
 my_select = select;
 }
 sort::selection select(){
 return my_select;
 }
 void Algorithm::execute(){
 sortAlgos a;
 switch(my_select){
 case BUBBLE:
 a.bubble();
 break;
 case MERGE:
 a.merge();
 break;
 case INSERTION:
 a.insertion();
 break;
 
 }
 
 }
 */
