//
//  Node.hpp
//  lab2
//
//  Created by MollyYu on 10/8/19.
//  Copyright © 2019 MollyYu. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
class Node{
public:
    Node* next;
    Node(int);
    ~Node();
    
private:
    int data;
 
};
#endif /* Node_hpp */
