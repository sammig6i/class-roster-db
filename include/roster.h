#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
   public:
    std::vector<Student*> classRosterArray;

    Roster(int size);
    ~Roster();

    void addStudent(Student* student);
    void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string& studentID);
    void printAll();
    void printAvgDaysInCourse(const std::string& studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif