#include "roster.h"

#include <algorithm>
#include <iostream>
#include <string>

Roster::Roster(int size) {
    this->idx = 0;
    this->size = size;
    for (int i = 0; i < size; i++) {
        this->classRosterArray[i] = new Student;
    }
}

Roster::~Roster() {
    for (Student* studentptr : classRosterArray) {
        delete studentptr;
    }
}

void Roster::addStudent(Student* student) {
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            return;
        }
    }
}

void Roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    std::array<int, 3> daysToCompleteCourses = {daysInCourse1,
                                                daysInCourse2,
                                                daysInCourse3};
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);

    classRosterArray[size] = newStudent;
}

// parse Student Data table
void Roster::parseStudentData(std::string studentData) {
    std::string studentID, firstName, lastName, emailAddress;
    int age;
    std::array<int, 3> daysToCompleteCourses;

    if (idx < size) {
        classRosterArray[idx] = new Student;
        int pos = 0;
        std::string delimiter = ",";

        pos = studentData.find(delimiter);
        studentID = studentData.substr(0, pos);
        classRosterArray[idx]->setStudentID(studentID);

        int lastPos = pos;
        pos = studentData.find(delimiter, lastPos + 1);
        firstName = studentData.substr(lastPos + 1, pos - lastPos - 1);
        classRosterArray[idx]->setFirstName(firstName);

        lastPos = pos;
        pos = studentData.find(delimiter, lastPos + 1);
        lastName = studentData.substr(lastPos + 1, pos - lastPos - 1);
        classRosterArray[idx]->setLastName(lastName);

        lastPos = pos;
        pos = studentData.find(delimiter, lastPos + 1);
        emailAddress = studentData.substr(lastPos + 1, pos - lastPos - 1);
        classRosterArray[idx]->setEmailAddress(emailAddress);

        lastPos = pos;
        pos = studentData.find(delimiter, lastPos + 1);
        age = std::stoi(studentData.substr(lastPos + 1, pos - lastPos - 1));
        classRosterArray[idx]->setAge(age);

        for (int i = 0; i < 3; i++) {
            lastPos = pos;
            pos = studentData.find(delimiter, lastPos + 1);
            daysToCompleteCourses[i] = std::stoi(studentData.substr(lastPos + 1, pos - lastPos - 1));
            lastPos = pos;
        }
        classRosterArray[idx]->setDaysToCompleteCourses(daysToCompleteCourses);

        lastPos = pos;
        pos = studentData.find(delimiter, lastPos + 1);
        std::string degree = studentData.substr(lastPos + 1, pos - lastPos - 1);
        if (degree == "SECURITY") {
            classRosterArray[idx]->setDegreeProgram(SECURITY);
        } else if (degree == "NETWORK") {
            classRosterArray[idx]->setDegreeProgram(NETWORK);
        } else if (degree == "SOFTWARE") {
            classRosterArray[idx]->setDegreeProgram(SOFTWARE);
        } else {
            classRosterArray[idx]->setDegreeProgram(NONE);
        }

        idx++;
    }
}

void Roster::remove(const std::string& studentID) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] == nullptr) {
            break;
        }
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cerr << "Student ID " << studentID << " not found." << std::endl;
    } else if (found) {
        std::cerr << "Student ID " << studentID << " removed." << std::endl;
    }
}

void Roster::printAll() {
    for (const auto& student : classRosterArray) {
        if (student == nullptr) {
            continue;
        } else {
            student->print();
        }
        printf("\n\n");
    }
}

void Roster::printAvgDaysInCourse(const std::string& studentID) {
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); it++) {
        if ((*it)->getStudentID() == studentID) {
            std::array<int, 3> days = (*it)->getDaysToCompleteCourses();

            int sum = 0;
            for (size_t i = 0; i < days.size(); i++) {
                sum += days[i];
            }
            double avgDaysInCourse = sum / 3.0;
            double roundedAvg = std::round(avgDaysInCourse * 100) / 100;

            std::cout << "Average days to complete courses for student ID " << studentID << ": " << roundedAvg << std::endl;
            return;
        }
    }
    std::cerr << "Student ID " << studentID << " not found." << std::endl;
}
void Roster::printInvalidEmails() {
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); it++) {
        std::string email = (*it)->getEmailAddress();
        if (email.empty()) {
            std::cout << "Student ID " << (*it)->getStudentID() << "does not have an email." << std::endl;
        } else {
            bool hasAtSymbol = false;
            bool hasDot = false;
            bool hasSpace = false;

            for (char c : email) {
                if (c == '@') {
                    hasAtSymbol = true;
                } else if (c == '.') {
                    hasDot = true;
                } else if (c == ' ') {
                    hasSpace = true;
                }
            }

            if (!hasAtSymbol || !hasDot || hasSpace) {
                std::cout << "Student ID " << (*it)->getStudentID() << " has an invalid email address: " << (*it)->getEmailAddress() << std::endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::string programString;
    switch (degreeProgram) {
        case SECURITY:
            programString = "Security";
            break;
        case NETWORK:
            programString = "Network";
            break;
        case SOFTWARE:
            programString = "Software";
            break;
        default:
            programString = "None";
            break;
    }

    bool found = false;
    std::cout << "Students in " << programString << " program:"
              << std::endl;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); it++) {
        if ((*it)->getDegreeProgram() == degreeProgram) {
            (*it)->print();
            found = true;

        } else {
            continue;
        }
        std::cout << std::endl;
    }
    if (!found) {
        std::cerr << "No students are in the " << programString << " program." << std::endl;
    }
}
