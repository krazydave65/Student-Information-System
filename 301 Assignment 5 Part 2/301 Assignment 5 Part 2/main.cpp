//
//  main.cpp
//  301 Assignment 5 Part 2
//
//  Created by David Pedroza on 11/15/13.
//  Copyright (c) 2013 David Pedroza. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "List.h"
#include "NodeType.h"
#include "StudentRecord.h"
using namespace std;
//"STUDENT.DAT"
//"FinalRecord.txt"


void addStudent(int ID, string firstName, string lastName, double GPA, List<StudentRecord> &myList);

void retrieveRecord(int ID , List<StudentRecord> &myList);

void deleteRecord(int ID, List<StudentRecord> &myList);

void modifyStudent(int ID ,List<StudentRecord> &myList);

void printList(List<StudentRecord> &myList);


int main()
{
    List<StudentRecord> myList;

    double number = 0.0;
    char choice ;
    char choice2;
    char deleteAns;
    char saveAns;
    string line;
    string lastName, firstName;
    double GPA = 0.0;
    int ID = 0;
    
    
    
    
    cout << "Student Records\n\n";
    
    
    //********************* Menu for Importing *********************
    
    cout << "Import Student Text File Records (i) \n"
         << "Create a new Student Records (n): ";
    cin >> choice;

    
    switch (choice) { 
        case 'i':
            {   //Read records from "STUDENT.DAT" file

                
                ifstream outData;
                outData.open("STUDENT.DAT");
                
                
                while (!outData.eof()) {
                    outData >> ID >> firstName >> lastName >> GPA;
                    addStudent(ID, firstName, lastName, GPA, myList);
                    
                }
                
                outData.close();
                
                cout << endl;
                cout << "Student Records Import: Successful \n\n";
                
            }
            
            break;
        
        default:
            break;
    }
    
    cout << endl;
    
    
    
    //********************** Main Menu *******************************
    
    cout << "'a' Add Student \n"
         << "'r' Retrieve Student Records \n"
         << "'d' Delete a Student Record \n"
         << "'m' Modify a Student Record \n"
         << "'p' Print Student Records \n"
         << "'q' Quit Program \n\n";
    
    do
    {
    
        cout << "Menu Choice: ";
        cin >> choice2;
        cout << endl;
    
    
        switch (choice2) {
            case 'a': //***** Adding a new Student ******
                {
                    int found = false;
                    cout << "New Student: \n";
                    cout << "Enter ID: ";
                    cin >> ID;
                    cout << "Enter First Name: ";
                    cin >> firstName;
                    cout << "Enter Last Name: ";
                    cin >> lastName;
                    cout << "Enter GPA: ";
                    cin >> GPA;
                
                    myList.goToStart();
                    while (!found && !myList.isAtEnd()) //Check for existing ID
                    {
                        if (myList.CurrentItem().getID() == ID)
                        {
                            cout << "\nThis ID already exists\n";
                            found = true;
                        }
                        
                        else
                            myList.goToNext();
                    }
                    
                    if(!found)
                    {
                        addStudent(ID, firstName, lastName, GPA, myList);
                    }
                    
                    cout << endl;
                }
                break;

            case 'r': //***** Removing a Student ************
                cout << "Enter a Student ID to retrieve: ";
                cin >> ID;
                retrieveRecord(ID, myList);
                cout << endl << endl;
                break;
            
            case 'd': //********* Deleting a Student **********
               

                    cout << "Enter a Student ID to delete: ";
                    cin >> ID;
                    cout << "\nAre you sure you want to delete this ID? \n"
                        << "(y/n): ";
                    cin >> deleteAns;
            
                
                    if (deleteAns == 'y')
                        deleteRecord(ID, myList);
                  
                    else if(deleteAns == 'n')
                        cout << "Back to Menu \n";
                  
                
                cout << endl;
                break;
            
            case 'm':  //****** modify a record ******
                cout << "Enter a Student ID to retrieve: ";
                cin >> ID;
                
                modifyStudent(ID, myList);
                
                cout << endl << endl;                
                break;
            
            case 'p':   //********* Print the List ***********
                printList(myList);
                cout << endl;
                break;
            
            case 'q':   //*********** Quit ************
                cout << endl;
                break;
            
            default:
                break;
                
        } // end of switch case
        
    }while (choice2 != 'q');
    
    
    //*********************** Quit/Save *************************************
    
    cout << "Before quiting do you want to save \n Student Records to a text file?\n"
         << "(y/n): ";
    cin >> saveAns;
    
    
    switch (saveAns)
    {
        case 'y':
            {
                //save myList to "FinalRecord.txt"
                ofstream inData;
                inData.open("STUDENT.DAT");
                
                myList.goToStart();
                
                while (!myList.isAtEnd()) //dont use "inData.is_open() && !myList.isAtEnd()"
                {
                    inData << myList.CurrentItem().getID() << "\t\t"
                           << myList.CurrentItem().getFirstName() << "\t\t"
                           << myList.CurrentItem().getLastName() << "\t\t"
                           << myList.CurrentItem().getGPA() << "\t\t"
                           << endl;
                    
                    myList.goToNext();
                    
                }
                
                inData.close();
            }
            break;
            
        default:
            break;
    }
    
    cout << "Application Terminated\n";
    
    return 0;
}



//***************************** Functions ************************************



void addStudent(int ID, string firstName, string lastName, double GPA, List<StudentRecord> &myList) 
{
    StudentRecord newStudent;
    bool found = false;
        
    newStudent.setID(ID);
    newStudent.setFirstName(firstName);
    newStudent.setLastName(lastName);
    newStudent.setGPA(GPA);
    
    myList.goToStart();
    
    
    //check for duplicates
    myList.goToStart();
    while (!found && !myList.isAtEnd()) //Check for existing ID
    {
        if (myList.CurrentItem().getID() == ID)
        {
            found = true;
        }
        
        else
            myList.goToNext();
    }
    
    
    if(!found)
    {
        //sorting in order
        found = false;
        myList.goToStart();
    
        while (!found)
        {
            if ( myList.CurrentItem().getID() > ID || myList.isAtEnd())
            {
                myList.insert(newStudent);
                found = true;
            }
        
            else
                myList.goToNext();
        }
    
    }

    
}



void printList(List<StudentRecord> &myList) //Print list
{
    
    myList.goToStart();
    
    cout << "   Student Records: \n";
    
    cout << "ID:\t\tFirst:\t\tLast:\t\tGPA:\n"
         << "-------------------------------------\n";
    
    while(!myList.isAtEnd())
    {
        cout << myList.CurrentItem().getID() << "\t";
        cout << myList.CurrentItem().getFirstName() << "\t\t";
        cout << myList.CurrentItem().getLastName() << "\t\t";
        cout << myList.CurrentItem().getGPA() << "\t\t";
        
        myList.goToNext();
        cout << endl;
    }
    
}


void retrieveRecord(int ID , List<StudentRecord> &myList)
{
    
    bool found = false;
    myList.goToStart();
    
    cout << endl;
    
    while (!found && !myList.isAtEnd())
    {
        
        
        if (ID == myList.CurrentItem().getID())
        {
            found = true;
            
            cout << "ID:\t\tFirst:\t\tLast:\t\tGPA\n"
                 << "------------------------------------\n";
            cout << myList.CurrentItem().getID() << "\t";
            cout << myList.CurrentItem().getFirstName() << "\t\t";
            cout << myList.CurrentItem().getLastName() << "\t\t";
            cout << myList.CurrentItem().getGPA() << "\t\t";
        }
        
        
        else 
            myList.goToNext(); // increment++
    }
    
    if (!found) 
        cout << "ID Not Found! \n";
        
}



void modifyStudent(int ID ,List<StudentRecord> &myList)
{
    string lastName, firstName;
    double GPA = 0.0;
    
    //******** Retrieve/Print out Student Record **********
    bool found = false;
    myList.goToStart();
    
    cout << endl;
    
    while (!found && !myList.isAtEnd())
    {
        
        
        if (ID == myList.CurrentItem().getID())
        {
            found = true;
            
            cout << "ID:\t\tFirst:\t\tLast:\t\tGPA\n"
            << "------------------------------------\n";
            cout << myList.CurrentItem().getID() << "\t";
            cout << myList.CurrentItem().getFirstName() << "\t\t";
            cout << myList.CurrentItem().getLastName() << "\t\t";
            cout << myList.CurrentItem().getGPA() << "\t\t";
        }
        
        
        else
            myList.goToNext(); // increment++
    }
    
    if (!found)
        cout << "ID Not Found! \n";
    
    
    //***************** Modify Student Record *****************
    
    if (found)
    {
        cout << "\n\nStudent Modification \n";
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter GPA: ";
        cin >> GPA;
        
        StudentRecord newStudentRecord = myList.CurrentItem();
        
        newStudentRecord.setFirstName(firstName);
        newStudentRecord.setLastName(lastName);
        newStudentRecord.setGPA(GPA);
        
        myList.deleteCurrentItem();
        myList.insert(newStudentRecord);
    }
    
    
}


void deleteRecord(int ID, List<StudentRecord> &myList)
{
    
    bool found;
    myList.goToStart();
    
    while (!found && !myList.isAtEnd())
    {
        if (ID == myList.CurrentItem().getID())
        {
            found = true;
            myList.deleteCurrentItem();
        }
        
        
        
        else
            myList.goToNext(); // increment++
    }
    
    if (!found)
        cout << "ID Not Found! \n";
    
}



























