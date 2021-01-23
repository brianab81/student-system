//
//  main.cpp
//  StudentSystem2020-wgu
//
//  Created by Briana on 11/1/20.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
    // Special requirements from section F 1.
    cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS"<< endl;
    cout << "C++" << endl;
    cout << "001280245" << endl;
    cout << "Briana Brown" << endl;
    cout << "" << endl;
    // Part A - student data table
    //long string to parse
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Briana,Brown,bbro517@wgu.edu,23,22,38,33,SOFTWARE"
    };
    /* This must be done since arrays don't record their own size */
    
    const int numStudents = 5;
    /* Default constructor*/
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    classRoster.printAll();
    cout << endl;
    
    cout << "Displaying Students with Invalid Email's" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    //rework
    cout << "Displaying average Days in class : " << endl;
    for (int i = 0; i < numStudents; i++)
       {
       classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] -> getStudentID());
       cout << std::endl;
       }
  
    
    cout << "Printing by degree type: SOFTWARE" << endl;
    classRoster.printbyDegreeProgram(SOFTWARE);
    
    
    
    cout << "Removing Student with ID A3:" << endl;
    // change the name to remove
    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printAll();
    
    //expected: the above line should print a message saying such a student with this ID was not found.
    classRoster.remove("A3");
    
    
    //system("pause");
    return 0;
}

