//
//  roster.h
//  StudentSystem2020-wgu
//
//  Created by Briana on 12/9/20.
//

#pragma once

#include "student.h"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
   // Student* classRosterArray[numStudents];
public:
    //Parse method goes through a set of comma delimited string and extracts the data of a student
    Student* classRosterArray[numStudents];
    void parse (string row);
    void add (string bStudentID, string bfirstName, string blastName, string bemailAddress, int bage, int bdaysInCourse1, int bdaysInCourse2, int bdaysInCourse3, DegreeProgram deg);
    void printAll(); //calls the print() method in a Student class for each student
    void printbyDegreeProgram (DegreeProgram deg); // Degree Program is passed
    void printInvalidEmails(); //  Each Students ID needs an underscore and either an upper case 'x' or a lower case
    void printAverageDaysInCourse( string StudentID);
    void remove(string StudentID); // finds the sudent with supplied ID and removes
   
    
   
    ~Roster();
};










