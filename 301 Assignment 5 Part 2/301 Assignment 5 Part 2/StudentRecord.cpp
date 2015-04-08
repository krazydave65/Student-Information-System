//
//  StudentRecord.cpp
//  301 Assignment 5 Part 2
//
//  Created by David Pedroza on 11/18/13.
//  Copyright (c) 2013 David Pedroza. All rights reserved.
//

#include "StudentRecord.h"

StudentRecord::StudentRecord()
{
    lastName = "";
    firstName = "";
    ID = 0;
    GPA = 0;
    
}

void StudentRecord::setLastName(string last)
{
    lastName = last;
}

void StudentRecord::setFirstName(string first)
{
    firstName = first;
}

void StudentRecord::setID(int tempID)
{
    ID = tempID;
}

void StudentRecord::setGPA(double tempGPA)
{
    GPA = tempGPA;
}

string StudentRecord::getLastName()
{
    return lastName;
}

string StudentRecord::getFirstName()
{
    return firstName;
}

int StudentRecord::getID()
{
    return ID;
}

double StudentRecord::getGPA()
{
    return GPA;
}
