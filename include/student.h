#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "degree.h"

class Student {
   private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    std::array<int, 3> daysToCompleteCourses;
    DegreeProgram degreeProgram;

   public:
    // Constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, std::array<int, 3> daysToCompleteCourses, DegreeProgram degreeProgram);

    // getter functions for each variable
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    std::array<int, 3>& getDaysToCompleteCourses();
    DegreeProgram getDegreeProgram() const;

    // setter functions for each variable
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(std::array<int, 3> daysToCompleteCourses);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // print method
    void print();
};

#endif