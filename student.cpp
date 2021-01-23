//
//  student.cpp
//  StudentSystem2020-wgu
//
//  Created by Briana on 11/1/20.

#include "student.h"


Student::Student () { /* Constructor */
    this->StudentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) this-> daysInCourse[i] = 0;
    this-> degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student (string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram deg)
{
    this->StudentID = StudentID;
    this-> firstName = firstName;
    this-> lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for( int i = 0; i< daysInCourseArraySize; i++) this -> daysInCourse[i] = daysInCourse[i];
    this-> degreeProgram = deg;
   
}
Student::~Student (){} /* Destructor */

string Student::getStudentID() {return this-> StudentID;}
string Student::getfirstName() {return this-> firstName;}
string Student::getlastName() {return this-> lastName;}
string Student::getemailAddress() {return this-> emailAddress;}
int Student::getage() {return this-> age;}
int* Student::getdaysInCourse() {return this-> daysInCourse;}
DegreeProgram Student::getdegreeProgram() {return this-> degreeProgram;}

void Student::setStudentID(string StudentID) {this -> StudentID = StudentID ;}
void Student::setfirstName(string firstName) {this -> firstName = firstName ;}
void Student::setlastName(string lastName) {this -> lastName = lastName;}
void Student::setemailAddress(string emailAddress) {this -> emailAddress = emailAddress ; }
void Student::setage(int age) {this -> age = age ; }
void Student::setdaysInCourse(int daysInCourse[])
{
    for (int i=0; i< daysInCourseArraySize; i++) this-> daysInCourse[i] = daysInCourse[i];
    
}
void Student::setDegreeProgram(DegreeProgram bt) {this -> degreeProgram = bt ;}

void Student::printHeader()
{
    cout << "Output format: StudentID|FirstName|LastName|EmailAddress|Age|NumberofDaystoComplete|DegreeProgram\n";
}

void Student::print()
{
    cout << this -> getStudentID() << '\t';
    cout << this-> getfirstName() << '\t';
    cout << this-> getlastName() << '\t';
    cout << this-> getemailAddress() << '\t';
    cout << this-> getage() << '\t';
    cout << this-> getdaysInCourse()[0] << '\t';
    cout << this-> getdaysInCourse()[1] << '\t';
    cout << this-> getdaysInCourse()[2] << '\t';
    cout << DegreeProgramStrings [this -> getdegreeProgram()] << '\n';
    
}

