#include "roster.h"

Roster::Roster(int size) {
    classRosterArray.reserve(size);
}

Roster::~Roster() {
    for (Student* studentptr : classRosterArray) {
        delete studentptr;
    }
}

void Roster::addStudent(Student* student) {
    classRosterArray.push_back(student);
}

void Roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    std::array<int, 3> daysToCompleteCourses = {daysInCourse1,
                                                daysInCourse2,
                                                daysInCourse3};
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);
    classRosterArray.push_back(newStudent);
}

void Roster::remove(const std::string& studentID) {
    bool found = false;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); it++) {
        if ((*it)->getStudentID() == studentID) {
            delete *it;
            classRosterArray.erase(it);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cerr << "Student ID " << studentID << "not found." << std::endl;
    }
}

void Roster::printAll() {
    for (const auto& student : classRosterArray) {
        std::cout << student->getStudentID()
                  << "\tFirst Name: " << student->getFirstName()
                  << "\tLast Name: " << student->getLastName()
                  << "\tEmail Address: " << student->getEmailAddress()
                  << "\tAge: " << student->getAge()
                  << "\nDays To Complete Courses: {" << student->getDaysToCompleteCourses()[0] << ", " << student->getDaysToCompleteCourses()[1] << ", " << student->getDaysToCompleteCourses()[2]
                  << "}\tDegree Program: ";
        switch (student->getDegreeProgram()) {
            case SECURITY:
                std::cout << "SECURITY";
                break;
            case NETWORK:
                std::cout << "NETWORK";
                break;
            case SOFTWARE:
                std::cout << "SOFTWARE";
                break;
            default:
                std::cout << "None";
        }
        std::cout << std::endl;
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

            std::cout << "Average days to complete courses for student ID " << studentID << ": " << avgDaysInCourse << std::endl;
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
