#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "degree.h"

class Student {
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourses, DegreeProgram degreeProgram);

   private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToCompleteCourses[3];
    DegreeProgram degreeProgram;

   public:
    // getter functions for each variable
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int* getDaysToCompleteCourses();
    DegreeProgram getDegreeProgram() const;

    // setter functions for each variable
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(int daysToCompleteCourses[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // print method
    void print() const;

    // accessors / getters
    std::string Student::getStudentID() const {
        return studentID;
    }
    std::string Student::getFirstName() const {
        return firstName;
    }
    std::string Student::getLastName() const {
        return lastName;
    }
    std::string Student::getEmailAddress() const {
        return emailAddress;
    }
    int Student::getAge() const {
        return age;
    }
    int* Student::getDaysToCompleteCourses() const {
        return daysToCompleteCourses;
    }
    DegreeProgram Student::getDegreeProgram() const {
        return degreeProgram;
    }

    // mutators / setters
    void Student::setStudentID(std::string studentID) {
        this->studentID = studentID;
    }
    void Student::setFirstName(std::string firstName) {
        this->firstName = firstName;
    }
    void Student::setLastName(std::string lastName) {
        this->lastName = lastName;
    }
    void Student::setEmailAddress(std::string emailAddress) {
        this->emailAddress = emailAddress;
    }
    void Student::setAge(int age) {
        this->age = age;
    }
    void Student::setDaysToCompleteCourses(int daysToCompleteCourses[]) {
        for (int i = 0; i < 3; i++) {
            this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
        }
    }
    void Student::setDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
    }

    void Student::print() const {
        std::cout << "Student ID: " << getStudentID() << std::endl;
        std::cout << "First Name: " << getFirstName() << std::endl;
        std::cout << "Last Name: " << getLastName() << std::endl;
        std::cout << "Email Address: " << getEmailAddress() << std::endl;
        std::cout << "Age: " << getAge() << std::endl;
        std::cout << "Days to Complete Courses: ";
        int* days = getDaysToCompleteCourses();
        for (int i = 0; i < 3; i++) {
            std::cout << days[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Degree Program: ";
        switch (getDegreeProgram()) {
            case SECURITY:
                std::cout << "SECURITY";
                break;
            case NETWORK:
                std::cout << "NETWORK";
                break;
            case SOFTWARE:
                std::cout << "SOFTWARE";
                break;
        }
        std::cout << std::endl;
    }
};

#endif