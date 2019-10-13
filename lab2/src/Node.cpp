//
//  Node.cpp
//  lab2
//
//  Created by MollyYu on 10/8/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#include "Node.hpp"
#include <iostream>
Node::Node(int number){
    // void *data equal to the address of number
    data = number;
    next = nullptr;
} 
Node::~Node(){
    delete next;
}


