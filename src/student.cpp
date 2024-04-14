#include "student.h"

// Default Constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysToCompleteCourses[0] = 0;
    this->daysToCompleteCourses[1] = 0;
    this->daysToCompleteCourses[2] = 0;
    this->degreeProgram = NONE;
}

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, std::array<int, 3> daysToCompleteCourses, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourses = daysToCompleteCourses;
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
std::array<int, 3>& Student::getDaysToCompleteCourses() {
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
    for (size_t i = 0; i < daysToCompleteCourses.size(); i++) {
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
    std::cout << "Days to Complete Courses: {";
    auto days = getDaysToCompleteCourses();
    for (const auto& day : days) {
        std::cout << day << " ";
    }
    std::cout << "}" << std::endl;
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
        default:
            std::cout << "NONE";
            break;
    }
    std::cout << std::endl;
}