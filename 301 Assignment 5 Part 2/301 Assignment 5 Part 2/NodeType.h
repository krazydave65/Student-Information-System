//
//  NodeType.h
//  301 Assignment 5 Part 2
//
//  Created by David Pedroza on 11/15/13.
//  Copyright (c) 2013 David Pedroza. All rights reserved.
//

#ifndef ___01_Assignment_5_Part_2__NodeType__
#define ___01_Assignment_5_Part_2__NodeType__

#include <iostream>
#include "NodeType.h"
using namespace std;



//****************** Member Functions **********************************//

template <class T>
class NodeType //Class Node
{
    
public:
    NodeType(T);
    
    T info;
    NodeType<T> * link;
};


//*************** Member Function Definitions ****************************//




template <class T>
NodeType<T>::NodeType(T data) // constructor //template parameter <T>
{
    info = data;
    link = 0;
}






#endif /* defined(___01_Assignment_5_Part_2__NodeType__) */
