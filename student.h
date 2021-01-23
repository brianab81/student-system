//
//  student.h
//  StudentSystem2020-wgu
//
//  Created by Briana on 11/9/20.
//
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;



class Student  {
public:
    const static int daysInCourseArraySize = 3;
    
private:
    string StudentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
    
    
public:
    // constructor
    Student();
    
    // loaded constructor
    Student( string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram deg);
    
    //Deconstructor??
    ~Student();
    
    //accessors for each instance variable
    string getStudentID ();
    string getlastName();
    string getemailAddress();
    string getfirstName();
    int getage();
    int* getdaysInCourse(); //* = designate a variable as a pointer.
    DegreeProgram getdegreeProgram();
    
    //mutator for each instance variable
    void setStudentID(string studentID);
    void setfirstName( string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setage(int age);
    void setdaysInCourse(int days[]);
    void setDegreeProgram (DegreeProgram bt);
    
    // Display a header
    static void printHeader();
    //displays specific student's data 
    void print() ;
    
  
};


