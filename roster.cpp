//
//  roster.cpp
//  StudentSystem2020-wgu
//
//  Created by Briana on 11/1/20.
//
#include<string>
#include "roster.h"


void Roster::parse(string studentdata)
{
    DegreeProgram deg = SOFTWARE; /* Defualt value */
    if (studentdata.back() == 'Y') deg = SECURITY; /* Used the last letter as the character to tell us the degree program */
    else if (studentdata.back() == 'K') deg = NETWORK;
           
    
    long rhs = studentdata.find(","); /* finds the comma */
    string bStudentID = studentdata.substr(0,rhs); /* pulls out the substring in front of comma */
    
    long lhs = rhs +1; /* goes to next comma*/
    rhs = studentdata.find(",",lhs);
    string FN = studentdata.substr(lhs, rhs - lhs); /* first name */
    
    lhs = rhs + 1; /* keeps going through to next comma*/
    rhs = studentdata.find(",", lhs);
    string LN = studentdata.substr(lhs, rhs - lhs); /* last name */
    
    lhs = rhs + 1; /* keeps going through to next comma*/
    rhs = studentdata.find(",", lhs);
    string EAdress = studentdata.substr(lhs, rhs - lhs); /* email address */
    
    lhs = rhs + 1; /* keeps going through to next comma*/
    rhs = studentdata.find(",", lhs);
    int age = stod(studentdata.substr(lhs, rhs - lhs)); /* age - converts to int*/
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stod(studentdata.substr(lhs, rhs - lhs)); /* how many days in 1st course*/
    
    lhs = rhs +1;
    rhs = studentdata.find (",", lhs);
    int daysInCourse2 = stod(studentdata.substr(lhs, rhs - lhs)); /* how many days in 2nd course*/
    
    lhs = rhs+1;
    rhs = studentdata.find ("," , lhs);
    int daysInCourse3 =stod(studentdata.substr(lhs, rhs - lhs)); /* how many days in 3rd course*/
    /* first thing done was determing the degree program, now call add() method */
    
    add ( bStudentID, FN, LN, EAdress, age, daysInCourse1, daysInCourse2, daysInCourse3 , deg);
    }
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram deg)
{
    /* puts days in course back into an array for constructor*/
    int parr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student( studentID, firstName, lastName, emailAddress, age, parr, deg);
}
/* display all students*/
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        classRosterArray[i] -> print();
        
    }
}
/* Display only students with matching degree program*/
void Roster::printbyDegreeProgram(DegreeProgram deg)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i] -> getdegreeProgram()== deg) classRosterArray[i] -> print();
    }
    cout << std::endl;
}
/* Email should have a @ and . - no spaces */
void Roster::printInvalidEmails()
{
    bool any = true;
    for (int i=0; i<= Roster::lastIndex; i++)
    {
        string bemailAddress = (classRosterArray[i] -> getemailAddress());
        if (bemailAddress.find('@') == string::npos || (bemailAddress.find('.') == string::npos || !(bemailAddress.find(' ') == string::npos)))
        {
            any = false;
            cout << bemailAddress << " : " << classRosterArray[i] -> getfirstName() << std::endl;
        }
    }
    if(any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string StudentID)
{
    for( int i=0; i<= Roster::lastIndex; i++)
    {
       if (classRosterArray[i] ->getStudentID() == StudentID)
    {
            cout << classRosterArray[i] -> getStudentID() << ":";
            cout << ((classRosterArray[i] -> getdaysInCourse()[0]) + (classRosterArray[i] -> getdaysInCourse()[1]) + (classRosterArray[i] -> getdaysInCourse()[2]))/3.0 << std::endl;
        }
     /*  cout << classRosterArray[i] -> getStudentID() << ":";
       cout << ((classRosterArray[i] -> getdaysInCourse()[0]) + (classRosterArray[i] -> getdaysInCourse()[1]) + (classRosterArray[i] -> getdaysInCourse()[2]))/3.0 << std::endl; */
    }
    cout << std::endl;
}
void Roster::remove(string StudentID)
{
    bool success = false; // assuming it is not here
    for (int i=0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i] -> getStudentID()== StudentID)
        {
            success = true;// found it
            if ( i < numStudents -1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray [numStudents-1];
                classRosterArray [numStudents - 1] = temp;
                
            }
            Roster::lastIndex--; //student no longer visible
        }
    }
        if (success)
        {
            cout << StudentID << " removed from repository.  " << std::endl << std::endl;
            //this -> printAll();
        }
        else cout << StudentID << " not found. " << std::endl << std::endl;
}

//int Roster::getlastIndex() {return this-> lastIndex;}

Roster:: ~Roster()
{
    cout << "DESTRUCTOR CALLED!" << std::endl << std::endl;
    for ( int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
 
