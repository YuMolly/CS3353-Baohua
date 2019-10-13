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
using namespace std::chrono;
void sortAlgos::bubble(vector<int> &number){
    t1 = high_resolution_clock::now();
    int pre,curr = 0;
    for (int i =1;i<number.size();i++){
        for(int j = 1; j < number.size();j++){
            if(number[j] < number[j-1]){
                curr = number[j-1];
                pre = number[j];
                number[j-1] = pre;
                number[j] = curr;
            }
            counter++;
        }
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
}

void sortAlgos::mergeCut(vector<int>&number,int start,int end){
    t1 = high_resolution_clock::now();
    int midd;
    if(end-start>=2){
        midd = (end-start)/2 + start;
        mergeCut(number,start,midd);
        mergeCut(number,midd+1,end);
        merge(number,start,end,midd);
        counter++;
    }
    
}
void sortAlgos::merge(vector<int>&number,int start,int end,int midd){
    int left_s = midd-start+1;
    int right_s = end-midd;
    int L[left_s];
    int R[right_s];
    int temp;
    for(int i = 0;i<left_s;i++){
        L[i] = number[start+i];
    }
    if(left_s > 1){
        if(L[0] > L[1]){
            temp= L[1];
            L[1] = L[0];
            L[0] = temp;
        }
    }
    for(int i = 0;i<right_s;i++){
        R[i] = number[midd+i+1];
    }
    if(right_s > 1){
        if(R[0] > R[1]){
            temp= R[1];
            R[1] = R[0];
            R[0] = temp;
            
        }
    }
    int l = 0;
    int r  = 0;
    int i = start;
    while((l<left_s)&&(r<right_s)){
        // do not pass the size of L or R
        // compare the values in L and R array
        if(L[l]<=R[r]){
            number[i] = L[l];
            l++;
        }
        else{
            number[i] = R[r];
            r++;
        }
       
        i++;
    }
    while(l<left_s){
        //copy the remaining on L
        number[i] = L[l];
        
        l++;
        i++;
    }
    while(r<right_s){
        //copy the remaining on R
        number[i] = R[r];
        
        r++;
        i++;
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
}

void sortAlgos::insertion(vector<int> &number){
    t1 = high_resolution_clock::now();
    int pre,curr = 0;
    for (int i = 1; i<number.size();i++){
        curr = number[i];
        pre = i-1;
        while((curr < number[pre])&&(pre >= 0)){
            number[pre+1] = number[pre];
            pre = pre -1;
        }
        number[pre+1] = curr;
        counter++;
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
}

int sortAlgos::getCounter(){
    return counter;
}

chrono::duration<double>  sortAlgos::getTime(){
    return time_span;
}
