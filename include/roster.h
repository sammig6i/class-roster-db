#ifndef ROSTER_H
#define ROSTER_H
#include <array>
#include <string>
using namespace std;

#include "student.h"

class Roster {
   private:
    Student* classRosterArray[5];

   public:
    int size;
    int idx;

    Roster(int size);
    ~Roster();

    Student** begin() { return std::begin(classRosterArray); }
    Student** end() { return std::end(classRosterArray); }

    void add(string studentID, string firstName, string lastName, string email, int age,
             int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string& studentID);
    void printAll();
    void printAvgDaysInCourse(const std::string& studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parseStudentData(std::string studentData);
};

#endif