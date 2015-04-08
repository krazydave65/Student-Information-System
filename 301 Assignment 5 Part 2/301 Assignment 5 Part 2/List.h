//
//  List.h
//  301 Assignment 5 Part 2
//
//  Created by David Pedroza on 11/15/13.
//  Copyright (c) 2013 David Pedroza. All rights reserved.
//

#ifndef ___01_Assignment_5_Part_2__List__
#define ___01_Assignment_5_Part_2__List__

#include <iostream>
#include "List.h"
#include "NodeType.h"
using namespace std;

//****************** Member Functions *****************************// 

template <class T>
class List
{
public:
    List();
    void makeEmpty ();
    bool isEmpty( );
    void goToStart ( );
    void goToNext ( );
    bool isAtEnd ( );
    T CurrentItem ( );
    void insert (T data);
    void deleteCurrentItem ( );
    int currentPosition ( );
    
    
private:
    NodeType<T> * head;
    NodeType<T> * current;
    NodeType<T> * previous;
    int position; //????????????
};


//*************** Member Function Definitions ********************//

template <class T>
List<T>::List()
{
    current = NULL;
    previous = NULL;
    head = NULL;
    position = 1;
}

template <class T>
void List<T>::makeEmpty()
{
    NodeType<T> *deleteNode;
    
    while (head != NULL)
    {
        deleteNode = head;
        head = head->link;
        delete deleteNode;
    }
    
    current = NULL;
    previous = NULL;
    head = NULL;
    position = 1;
}

template <class T>
bool List<T>::isEmpty()
{
    if(head == NULL)
        return true;
    
    else
        return false;
}

template <class T>
void List<T>::goToStart()
{
    current = head;
    previous = NULL;
    position = 1;
}

template <class T>
void List<T>::goToNext()
{
    if(current!= NULL)
    {
        previous = current;
        current = current->link;
        position++;
    }
}

template <class T>
bool List<T>::isAtEnd()
{
    if(head == NULL || current == NULL)
        return true;
    
    else
        return false;
}

template <class T>
T List<T>::CurrentItem()
{
    T result;
    
    if(head!= NULL && current != NULL)
        result =  current->info;
    
    else
    {
        //cout << "The list is either Empty or current is at the end of List\n\n";
        
    }
    
    return result;
}

template <class T>
void List<T>::insert (T data)
{
    NodeType<T> *temp;
    //temp = previous;
    
    
    if(head == current) // INSERT AT BEGINNING or Insert in a empty list
    {
        current = new NodeType<T>(data);
        
        current->link = head;
        
        //current->info = data;
        
        head = current;
        
        previous = NULL;
        
    }
    
    
    else //Insert anywhere after first position
    {
        temp = new NodeType<T>(data);
        
        temp->info = data;
        
        temp->link = current;
        
        previous->link = temp;
        
        current = temp;
        
    }
}

template <class T>
void List<T>::deleteCurrentItem()
{
    NodeType<T> *deletedNode;
    
    
    
    if (head == NULL)// The list is empty!!!
        cout << "Can NOT Delete since the List is empty!\n\n";
    
    else if(current == NULL) // current is at end of LIST!!!
        cout << "Can NOT Delete since the current position is at the end of the list\n\n";
    
    
    else if(previous == NULL) //current = position 1
    {
        deletedNode = current;
        
        current = current->link;
        
        head = current;
        
        delete deletedNode;
    }
    
    else if(head != NULL && current != NULL) // middle of list
    {
        deletedNode = current;
        current = current->link;
        previous->link = current;
        delete deletedNode;
    }
    
    
    
    
    
    
}

template <class T>
int List<T>::currentPosition()
{
    return position;
}




#endif /* defined(___01_Assignment_5_Part_2__List__) */
