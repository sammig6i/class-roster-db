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
    printf("Student ID: %s\t", this->getStudentID().c_str());
    printf("First Name: %s\t", this->getFirstName().c_str());
    printf("Last Name: %s\t", this->getLastName().c_str());
    printf("Email Address: %s\t", this->getEmailAddress().c_str());
    printf("Age: %d\t\n", this->getAge());
    std::array<int, 3> days = this->getDaysToCompleteCourses();
    printf("Days to Complete Courses: ");
    for (size_t i = 0; i < days.size(); i++) {
        printf("%d ", days[i]);
    }
    printf("\tDegree Program: ");
    switch (this->getDegreeProgram()) {
        case SECURITY:
            printf("SECURITY");
            break;
        case NETWORK:
            printf("NETWORK");
            break;
        case SOFTWARE:
            printf("SOFTWARE");
            break;
        default:
            printf("NONE");
    }
}