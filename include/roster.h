#ifndef ROSTER_H
#define ROSTER_H
#include <array>
#include <string>

#include "student.h"

class Roster {
   public:
    int size;
    int idx;
    std::array<Student*, 5> classRosterArray;

    Roster(int size);
    ~Roster();

    std::array<Student*, 5>::iterator begin() { return std::begin(classRosterArray); }
    std::array<Student*, 5>::iterator end() { return std::end(classRosterArray); }

    void addStudent(Student* student);
    void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string& studentID);
    void printAll();
    void printAvgDaysInCourse(const std::string& studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parseStudentData(std::string studentData);
};

#endif