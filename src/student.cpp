#include "student.h"

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, std::array<int, 3> daysToCompleteCourses, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
    }
    this->degreeProgram = degreeProgram;
}

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
int* Student::getDaysToCompleteCourses() {
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
void Student::setDaysToCompleteCourses(std::array<int, 3> daysToCompleteCourses) {
    for (int i = 0; i < 3; i++) {
        this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
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