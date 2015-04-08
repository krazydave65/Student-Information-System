//
//  StudentRecord.h
//  301 Assignment 5 Part 2
//
//  Created by David Pedroza on 11/18/13.
//  Copyright (c) 2013 David Pedroza. All rights reserved.
//
// changes:
// class >> private >> double GPA = 0.0;

#ifndef ___01_Assignment_5_Part_2__StudentRecord__
#define ___01_Assignment_5_Part_2__StudentRecord__

#include <iostream>
using namespace std;

class StudentRecord{
    
public:
    StudentRecord();
    
    void setLastName(string );
    string getLastName();
    
    void setFirstName(string );
    string getFirstName();
    
    void setID(int);
    int getID();
    
    void setGPA(double);
    double getGPA();
    
    
private:
    string lastName;
    string firstName;
    int ID;
    double GPA;
    
};


#endif /* defined(___01_Assignment_5_Part_2__StudentRecord__) */
