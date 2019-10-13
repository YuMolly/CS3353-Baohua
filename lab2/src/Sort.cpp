//
//  Sort.cpp
//  data_generator
//
//  Created by MollyYu on 9/11/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "Sort.hpp"
#include "sortAlgos.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
Sort::Sort(){

}
Sort::~Sort(){
    
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
    cout<<"The size is:"<<num.size()<<endl;
    file.close();
    return num;
}

 void Sort::Setselect(Sort::selection select){
     my_select = select;
 }
Sort::selection Sort::select(){
    return my_select;
 }
void Sort::execute(vector<int> &number_arr,int start,int end){
     sortAlgos a;
     switch(my_select){
     case Sort::selection::BUBBLE:
         a.bubble(number_arr);
         sorted = number_arr;
         counter = a.getCounter();
         time_span = a.getTime();
         break;
     case Sort::selection::MERGE:
         a.mergeCut(number_arr,start,end);
         sorted = number_arr;
         counter = a.getCounter();
         time_span = a.getTime();
         break;
     case Sort::selection::INSERTION:
         a.insertion(number_arr);
         sorted = number_arr;
         counter = a.getCounter();
         time_span = a.getTime();
         break;
      default:
         cout<<"we have default case"<<endl;
     }
}

void Sort::display(){
    if(my_select == BUBBLE){
        for(int i =0;i<sorted.size();i++)
            cout<<"The solution of bubble sort: "<<sorted.at(i)<<endl;
    }
    else if(my_select == MERGE){
        for(int i =0;i<sorted.size();i++)
            cout<<"The solution of merge sort: "<<sorted.at(i)<<endl;
    }
    else if(my_select == INSERTION){
        for(int i =0;i<sorted.size();i++)
            cout<<"The solution of insertion sort: "<<sorted.at(i)<<endl;
    }
        
}

void Sort::state(){
    if(my_select == BUBBLE){
        cout<<"Bubble sorting!"<<endl;
        cout<<"The total comparison in this sorting method is: "<<counter<<endl;
        cout<<"The time of bubble sort is:"<<time_span.count()<<" seconds"<<endl;
    }
    if(my_select == MERGE){
        cout<<"Merge sorting!"<<endl;
        cout<<"The total comparison in this sorting method is: "<<counter<<endl;
        cout<<"The time of merge sort is:"<<time_span.count()<<" seconds"<<endl;
    }
    if(my_select == INSERTION){
        cout<<"Insertion sorting!"<<endl;
        cout<<"The total comparison in this sorting method is: "<<counter<<endl;
        cout<<"The time of insertion sort is:"<<time_span.count()<<" seconds"<<endl;
    }
}

void Sort::save(string path,string filename){
    string name;
    ofstream file;
    
    if(my_select == BUBBLE){
        name = path + "BUBBLE_" +filename;
        file.open(name);
        file<<"BUBBLE sorting result:"<<endl;
        for(int i = 0;i<sorted.size();i++){
            file << sorted.at(i) <<endl;
            
        }
    }
    if(my_select == MERGE){
        name = path + "MERGE_" +filename;
        file.open(name);
        file<<"MERGE sorting result:"<<endl;
        for(int i = 0;i<sorted.size();i++){
            file << sorted.at(i) <<endl;
            
        }
    }
    if(my_select == INSERTION){
        name = path + "INSERTION_" +filename;
        file.open(name);
        file<<"INSERTION sorting result:"<<endl;
        for(int i = 0;i<sorted.size();i++){
            file << sorted.at(i) <<endl;
            
        }
    }
    if(!file)
        cout<<"The file exist"<<endl;
    file.close();
    
}
