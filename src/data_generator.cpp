//
//  data_generator.cpp
//  data_generator
//
//  Created by MollyYu on 9/6/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//
#include <stdio.h>
#include <fstream>
#include <string>
#include "data_generator.h"

using namespace std;
using std::ofstream;
void data_generator::random_data(){
    int num = 0;
    int size = 10;
    int number[size];
    for (int i = 0; i<size;i++){
        num= rand();
        number[i] = num;
    }
}
void data_generator::revesed_data(){
    // insertion sort
    int num = 0;
    int size = 1000;
    int re_array [size];
    for (int i = 0; i<size;i++){
        num = rand();
        re_array[i] = num;
    }
    //sort random array
    int key,pre;
    for (int i = 1; i<size;i++){
        while((re_array[i]< re_array[i-1])&&(i >= 0)){
            key = re_array[i];
            pre = re_array[i-1];
            re_array[i-1] = key;
            re_array[i] = pre;
            i--;
        }
    }
    for (int i = 0; i<size;i++){
        //cout<<"sorted oder: "<<re_array[i]<<endl;
    }
    //reversed sorted array
    int end [size];
    int i = 0;
    for (int j = size-1; j>=0; j--){
        end[i] = re_array[j];
        i++;
    }
    for (int i = 0; i<size;i++){
        //cout<<"reversed oder: "<<end[i]<<endl;
    }
    ofstream file;
    file.open("1000reversed.txt");
    //int size = 10;
    //int num;
    for(int i = 0;i<size;i++){
        //num = rand();
        file << end[i]<<endl;
    }
    if(!file)
        cout<<"The file exist"<<endl;
    file.close();
        
}


void data_generator::unique_data(){
    int size = 1000;
    int size_t = size*0.2;
    int select;
    int unique[size_t];
    int unique_array[size];
    for(int i=0;i<size_t;i++){
        select = rand();
        unique[i] = select;
        //cout<<"My unique: "<<unique[i]<<endl;
    }
    for(int i = 0; i<size;i++){
        int ran = rand()%size_t;
        unique_array[i] = unique[ran];
        cout<<"The unique array is "<<unique_array[i]<<endl;
    }
    ofstream file;
    file.open("1000unique.txt");
    //int size = 10;
    //int num;
    for(int i = 0;i<size;i++){
        //num = rand();
        file << unique_array[i]<<endl;
    }
    if(!file)
        cout<<"The file exist"<<endl;
    file.close();
    
    
    
}


void data_generator::partial_data(){
    int num = 0;
    int size = 1000;
    int size_t = size*0.3;
    int pa_array [size];
    int part[size];
    for (int i = 0; i<size;i++){
        num = rand();
        pa_array[i] = num;
        part[i] = num;
    }
    int key,pre;
    for (int i = 1; i<size;i++){
        while((pa_array[i]< pa_array[i-1])&&(i >= 0)){
            key = pa_array[i];
            pre = pa_array[i-1];
            pa_array[i-1] = key;
            pa_array[i] = pre;
            i--;
        }
    }
    for(int j = 0;j<size_t;j++){
        pa_array[j] = part[j];
    }
    ofstream file;
    file.open("1000partial.txt");
    for(int i = 0;i<size;i++){
        //num = rand();
        file << pa_array[i]<<endl;
    }
    if(!file)
        cout<<"The file exist"<<endl;
    file.close();
}


void  data_generator::writefile(){//write file
    ofstream file;
    file.open("1000random.txt");
    int size = 100;
    int num;
    for(int i = 0;i<size;i++){
        num = rand();
        file << num <<endl;
    }
    if(!file)
        cout<<"The file exist"<<endl;
    file.close();
    
}


void data_generator::readfile(){
    ifstream file;
    file.open("data.txt");
    int num;
    if(!file)
        cout<<"The file fail to open"<<endl;
    else
        cout<<"The file can open successfully!"<<endl;
    while(file){
        file>>num;
        cout<<"The number is: "<<num<<endl;
    }
    file.close();
}

void data_generator::bubble(){
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
    for (int x = 0;x<size;x++){
        cout<<"The bubble sort is: ";
        cout<< number[x]<<endl;
    }
}


void data_generator::insertion(){
    int size = 10;
    int number[] = {3,4,6,2,8,1,5,6,2,5};
    int pre,curr = 0;
    for (int i = 1; i<size;i++){
        while((number[i]< number[i-1])&&(i > 0)){
            curr = number[i];
            pre = number[i-1];
            number[i-1] = curr;
            number[i] = pre;
            i--;
        }
    }
    for (int x = 0;x<size;x++){
        cout<<"The insertion sort is: ";
        cout<<number[x]<<endl;
    }
}
void data_generator::mergeCut(int *number,int start,int end){
    int midd;
    //end--;
    if(end-start>=2){
        midd = (end-start)/2 + start;
        mergeCut(number,start,midd);
        mergeCut(number,midd+1,end);
        merge(number,start,end,midd);
    }
    
}
void data_generator::merge(int *number,int start,int end,int midd){
    //int a[] = {3,4,6,2,8,1,5,6,2,5};
    //cout<<"start "<<number[start]<<endl;
    //cout<<"midd "<<number[midd]<<endl;
    //cout<<"end "<<number[end]<<endl;
    int left_s = midd-start+1;
    int right_s = end-midd;
    //cout<<"left_s "<<left_s<<endl;
    //cout<<"right_s "<<right_s<<endl;
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
    /*for(int i = 0;i<left_s;i++)
        cout<<"L :"<<L[i]<<endl;*/
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
    /*for(int i = 0;i<right_s;i++)
        cout<<"R :"<<R[i]<<endl;*/
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
        //cout<<"The number in array is: "<<number[i]<<endl;
        i++;
    }
    while(l<left_s){
        //copy the remaining on L
        number[i] = L[l];
        //cout<<"L "<<number[i]<<endl;
        l++;
        i++;
    }
    while(r<right_s){
        //copy the remaining on R
        number[i] = R[r];
        //cout<<"R  "<<number[i]<<endl;
        r++;
        i++;
    }
}
